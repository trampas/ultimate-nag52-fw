"""
The recording loop: polls live-data records over the diagnostic endpoint,
captures ESP_LOG output that arrives on the same UART, and writes everything
to a JSON Lines file.

Output format (one JSON object per line, ``type`` discriminates):

* ``header``   first line: logger version, start time, record + enum metadata
* ``snapshot`` one-off records read at connect (firmware header, TCM config, ...)
* ``cycle``    one polling cycle: ``t`` (host seconds since start), ``tcu_ms``
               (TCU clock read at the start of the cycle), ``dt`` (cycle
               duration in s) and one sub-object per record, keyed by name
* ``log``      one ESP_LOG line, parsed into level / tcu_ms / tag / msg when it
               matches the ESP-IDF format, otherwise just ``raw``
* ``event``    connection state changes, TCU reboots, errors
* ``end``      last line, with counters

Timestamps: ``t`` is host ``time.monotonic()`` relative to the header's
``t0_monotonic``; ``tcu_ms`` is the TCU's ``esp_timer`` millisecond clock.
The ``tcu_ms`` inside ``log`` lines comes from the ESP log macro (RTOS tick
based) and is within a few ms of the esp_timer clock.
"""
from __future__ import annotations

import datetime as _dt
import gzip
import io
import json
import os
import sys
import time
from typing import Any, Dict, List, Optional, TextIO

from . import __version__
from .protocol import (KWP_TP_TIMEOUT_S, KwpClient, KwpError, KwpNegativeResponse,
                       KwpTimeout, LogLine, SESSION_EXTENDED, SerialReader, open_serial)
from .records import (DEFAULT_FAST, DEFAULT_ONCE, DEFAULT_SLOW, ENUMS, Record,
                      describe_all, resolve)

FORMAT_VERSION = 1


def default_output_path(directory: str = "logs") -> str:
    stamp = _dt.datetime.now().strftime("%Y%m%d_%H%M%S")
    return os.path.join(directory, "nag52_%s.jsonl" % stamp)


class JsonlWriter:
    def __init__(self, path: str) -> None:
        self.path = path
        d = os.path.dirname(path)
        if d:
            os.makedirs(d, exist_ok=True)
        if path.endswith(".gz"):
            self._fh: TextIO = io.TextIOWrapper(gzip.open(path, "wb"), encoding="utf-8")
        else:
            self._fh = open(path, "w", encoding="utf-8")
        self.lines = 0
        self._last_flush = time.monotonic()

    def write(self, obj: Dict[str, Any]) -> None:
        self._fh.write(json.dumps(obj, separators=(",", ":"), ensure_ascii=False))
        self._fh.write("\n")
        self.lines += 1
        now = time.monotonic()
        if now - self._last_flush > 0.5:
            self._fh.flush()
            self._last_flush = now

    def close(self) -> None:
        try:
            self._fh.flush()
        finally:
            self._fh.close()


class Nag52Logger:
    """
    Drive one logging session.  Construct, then ``run()`` until Ctrl-C.

    ``port`` may be a path (opened with pyserial) or an already-open
    pyserial-like object (used by the tests).
    """

    def __init__(self, port, out_path: str, baud: int = 921600,
                 fast: Optional[List[str]] = None, slow: Optional[List[str]] = None,
                 once: Optional[List[str]] = None, slow_interval: float = 1.0,
                 rate_hz: float = 0.0, poll: bool = True, session: int = SESSION_EXTENDED,
                 echo_log: bool = True, status: bool = True, reset: bool = False,
                 request_timeout: float = 0.5, status_stream: TextIO = sys.stderr,
                 echo_stream: TextIO = sys.stdout, max_cycles: Optional[int] = None) -> None:
        self.port_arg = port
        self.baud = baud
        self.out_path = out_path
        self.fast = resolve(DEFAULT_FAST if fast is None else fast)
        self.slow = resolve(DEFAULT_SLOW if slow is None else slow)
        self.once = resolve(DEFAULT_ONCE if once is None else once)
        self.slow_interval = slow_interval
        self.period = (1.0 / rate_hz) if rate_hz and rate_hz > 0 else 0.0
        self.poll = poll
        self.session = session
        self.echo_log = echo_log
        self.status = status
        self.reset = reset
        self.request_timeout = request_timeout
        self.status_stream = status_stream
        self.echo_stream = echo_stream
        self.max_cycles = max_cycles

        self.t0 = 0.0
        self.writer: Optional[JsonlWriter] = None
        self.reader: Optional[SerialReader] = None
        self.client: Optional[KwpClient] = None
        self.ser = None
        self.connected = False
        self.stats = {"cycles": 0, "log_lines": 0, "bad_frames": 0, "errors": 0,
                      "reconnects": 0, "tcu_reboots": 0}
        self._last_tcu_ms: Optional[int] = None
        self._last_status = 0.0
        self._last_slow = -1e9
        self._last_summary: Dict[str, Any] = {}
        self._stop = False

    # -- helpers -------------------------------------------------------------
    def _now(self) -> float:
        return round(time.monotonic() - self.t0, 4)

    def _emit(self, obj: Dict[str, Any]) -> None:
        if self.writer:
            self.writer.write(obj)

    def _event(self, name: str, **kw: Any) -> None:
        obj = {"type": "event", "t": self._now(), "event": name}
        obj.update(kw)
        self._emit(obj)
        if self.status:
            print("[nag52log] %s %s" % (name, json.dumps(kw) if kw else ""),
                  file=self.status_stream, flush=True)

    def _on_log(self, text: str) -> None:
        line = LogLine.parse(text)
        obj: Dict[str, Any] = {"type": "log", "t": self._now()}
        if line.level is not None:
            obj.update({"tcu_ms": line.tcu_ms, "level": line.level,
                        "tag": line.tag, "msg": line.msg})
        else:
            obj["raw"] = line.raw
        self.stats["log_lines"] += 1
        self._emit(obj)
        if self.echo_log:
            print(text, file=self.echo_stream, flush=True)

    def _on_bad_frame(self, text: str) -> None:
        self.stats["bad_frames"] += 1

    def stop(self) -> None:
        self._stop = True

    # -- connection ----------------------------------------------------------
    def _open(self) -> None:
        if isinstance(self.port_arg, str):
            self.ser = open_serial(self.port_arg, self.baud, reset=self.reset)
        else:
            self.ser = self.port_arg
        self.reader = SerialReader(self.ser, self._on_log, self._on_bad_frame)
        self.reader.start()
        self.client = KwpClient(self.ser, self.reader, timeout=self.request_timeout)

    def _handshake(self) -> bool:
        """Start the diagnostic session and read the one-off records."""
        assert self.client is not None
        try:
            self.client.start_session(self.session)
        except KwpError:
            return False
        snapshot: Dict[str, Any] = {"type": "snapshot", "t": self._now(), "records": {}}
        try:
            snapshot["ecu_serial"] = self.client.read_ecu_serial()
        except KwpError:
            pass
        for rec in self.once:
            try:
                snapshot["records"][rec.name] = rec.decode(self.client.read_local_ident(rec.rli))
            except KwpNegativeResponse as exc:
                snapshot["records"][rec.name] = {"_error": str(exc)}
            except KwpError:
                return False
        self._emit(snapshot)
        self._last_tcu_ms = None
        return True

    def _wait_for_tcu(self) -> None:
        """Retry the handshake until the TCU answers (it may be powered off)."""
        backoff = 0.5
        announced = False
        while not self._stop:
            if self._handshake():
                self.connected = True
                self._event("connected", session="0x%02X" % self.session)
                return
            if not announced:
                self._event("waiting_for_tcu")
                announced = True
            self._sleep(backoff)
            backoff = min(backoff * 1.5, 3.0)

    def _sleep(self, seconds: float) -> None:
        end = time.monotonic() + seconds
        while not self._stop and time.monotonic() < end:
            time.sleep(min(0.05, max(0.0, end - time.monotonic())))
            self._check_reader()

    def _check_reader(self) -> None:
        if self.reader is not None and self.reader.error is not None:
            raise self.reader.error

    # -- polling -------------------------------------------------------------
    def _read_record(self, rec: Record) -> Any:
        assert self.client is not None
        try:
            return rec.decode(self.client.read_local_ident(rec.rli))
        except KwpNegativeResponse as exc:
            return {"_error": exc.nrc}

    def _cycle(self) -> None:
        assert self.client is not None
        start = time.monotonic()
        cycle: Dict[str, Any] = {"type": "cycle", "seq": self.stats["cycles"], "t": self._now()}
        do_slow = (start - self._last_slow) >= self.slow_interval
        records = list(self.fast) + (list(self.slow) if do_slow else [])
        for rec in records:
            data = self._read_record(rec)
            if rec.name == "tcu_time" and isinstance(data, dict) and "tcu_ms" in data:
                tcu_ms = data["tcu_ms"]
                cycle["tcu_ms"] = tcu_ms
                if self._last_tcu_ms is not None and tcu_ms + 1000 < self._last_tcu_ms:
                    self.stats["tcu_reboots"] += 1
                    self._event("tcu_reboot", tcu_ms_before=self._last_tcu_ms, tcu_ms_after=tcu_ms)
                self._last_tcu_ms = tcu_ms
            else:
                cycle[rec.name] = data
        if do_slow:
            self._last_slow = start
        cycle["dt"] = round(time.monotonic() - start, 4)
        self._emit(cycle)
        self.stats["cycles"] += 1
        self._last_summary = cycle

    def _print_status(self, force: bool = False) -> None:
        if not self.status:
            return
        now = time.monotonic()
        if not force and now - self._last_status < 1.0:
            return
        self._last_status = now
        parts = ["t=%7.1fs" % self._now(), "cycles=%d" % self.stats["cycles"],
                 "logs=%d" % self.stats["log_lines"]]
        c = self._last_summary
        sl = c.get("shift_live") if isinstance(c, dict) else None
        if isinstance(sl, dict) and "actual_gear" in sl:
            parts.append("gear=%s>%s" % (sl.get("actual_gear"), sl.get("target_gear")))
            parts.append("in=%srpm eng=%srpm out=%srpm" % (sl.get("input_rpm"), sl.get("engine_rpm"), sl.get("output_rpm")))
            parts.append("spc=%s mpc=%s" % (sl.get("spc_pressure"), sl.get("mpc_pressure")))
        if isinstance(c, dict) and "dt" in c:
            parts.append("cycle=%.0fms" % (c["dt"] * 1000))
        if self.client:
            st = self.client.stats
            parts.append("to=%d retry=%d bad=%d" % (st["timeouts"], st["retries"], self.stats["bad_frames"]))
        if not self.connected:
            parts.append("(no TCU)")
        print("[nag52log] " + " ".join(parts), file=self.status_stream, flush=True)

    # -- main ----------------------------------------------------------------
    def run(self) -> Dict[str, Any]:
        self.t0 = time.monotonic()
        self.writer = JsonlWriter(self.out_path)
        header = {
            "type": "header", "format": FORMAT_VERSION, "logger_version": __version__,
            "started": _dt.datetime.now().astimezone().isoformat(timespec="seconds"),
            "t0_monotonic": self.t0, "port": self.port_arg if isinstance(self.port_arg, str) else "object",
            "baud": self.baud, "poll": self.poll,
            "fast": [r.name for r in self.fast], "slow": [r.name for r in self.slow],
            "slow_interval": self.slow_interval, "rate_hz": (1.0 / self.period) if self.period else None,
            "records": describe_all(), "enums": {k: {str(i): n for i, n in v.items()} for k, v in ENUMS.items()},
        }
        self.writer.write(header)
        if self.status:
            print("[nag52log] writing %s" % self.out_path, file=self.status_stream, flush=True)
        try:
            self._open()
            self._event("port_open", port=header["port"], baud=self.baud)
            if not self.poll:
                while not self._stop:
                    self._sleep(0.2)
                    self._print_status()
                return self.stats
            consecutive_failures = 0
            self._wait_for_tcu()
            while not self._stop and self.connected:
                cycle_start = time.monotonic()
                try:
                    self._cycle()
                    consecutive_failures = 0
                except KwpTimeout:
                    consecutive_failures += 1
                    self.stats["errors"] += 1
                    if consecutive_failures >= 3:
                        self.connected = False
                        self.stats["reconnects"] += 1
                        self._event("tcu_lost")
                        self._wait_for_tcu()
                        continue
                except KwpError as exc:
                    self.stats["errors"] += 1
                    self._event("kwp_error", error=str(exc))
                self._check_reader()
                self._print_status()
                if self.max_cycles is not None and self.stats["cycles"] >= self.max_cycles:
                    break
                if self.period:
                    wait = self.period - (time.monotonic() - cycle_start)
                    if wait > 0:
                        self._sleep(wait)
                    # Keep the extended session alive even at very low rates
                    if self.client and time.monotonic() - self.client.last_tx > KWP_TP_TIMEOUT_S * 0.6:
                        try:
                            self.client.tester_present()
                        except KwpError:
                            pass
        except KeyboardInterrupt:
            pass
        finally:
            self._finish()
        return self.stats

    def _finish(self) -> None:
        if self.reader:
            self.reader.stop()
        if self.ser is not None and isinstance(self.port_arg, str):
            try:
                self.ser.close()
            except Exception:  # noqa: BLE001
                pass
        if self.reader:
            self.reader.join(timeout=1.0)
        if self.writer:
            end = {"type": "end", "t": self._now(), "stats": dict(self.stats)}
            if self.client:
                end["kwp"] = dict(self.client.stats)
            self.writer.write(end)
            self.writer.close()
            self._print_status(force=True)
            if self.status:
                print("[nag52log] wrote %d lines to %s" % (self.writer.lines, self.out_path),
                      file=self.status_stream, flush=True)
