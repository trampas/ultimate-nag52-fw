"""
Serial transport and a minimal KWP2000 client for the Ultimate-NAG52 USB
diagnostic endpoint.

The TCU shares a single UART (UART0, exposed through the on-board CP210x
USB bridge at 921600 baud) between two things:

* ``ESP_LOG`` text output (plain lines, ``I (1234) TAG: message``)
* the KWP2000 diagnostic endpoint (see ``src/diag/endpoints/usb_endpoint.cpp``)

Wire format of the diagnostic endpoint::

    PC  -> TCU   raw bytes:   [len_hi, len_lo, id_hi, id_lo, payload...]
                              len = 2 + len(payload)
                              The TCU treats "bytes arrived, then a poll with
                              no new bytes" as end-of-message, so a request
                              must be written in one go.
    TCU -> PC    ASCII line:  '#' + 4 hex chars (id) + 2 hex chars / byte + '\\n'

Any received line that does not start with ``#`` is log output.  Because the
log path and the diagnostic path are written by different code on the TCU it
is possible (rare) for a log line to be spliced into the middle of a frame;
the demultiplexer therefore validates every frame and discards bad ones, and
the client simply retries.
"""
from __future__ import annotations

import queue
import re
import threading
import time
from dataclasses import dataclass
from typing import Callable, Iterator, Optional, Tuple

# --- KWP2000 constants (mirrors src/diag/kwp2000_defines.h) -----------------
KWP_ECU_TX_ID = 0x07E9  # TCU sends on this ID
KWP_ECU_RX_ID = 0x07E1  # Tester requests on this ID

SID_START_DIAGNOSTIC_SESSION = 0x10
SID_READ_ECU_IDENT = 0x1A
SID_READ_DATA_LOCAL_IDENT = 0x21
SID_READ_MEM_BY_ADDRESS = 0x23
SID_TESTER_PRESENT = 0x3E

SESSION_DEFAULT = 0x81
SESSION_EXTENDED = 0x92
SESSION_CUSTOM_UN52 = 0x93

NRC_RESPONSE_PENDING = 0x78
KWP_CMD_RESPONSE_REQUIRED = 0x01

# The TCU drops back to the default session (20 ms server loop instead of 2 ms)
# if it hears nothing from the tester for this long.
KWP_TP_TIMEOUT_S = 4.5

NRC_NAMES = {
    0x10: "GENERAL_REJECT",
    0x11: "SERVICE_NOT_SUPPORTED",
    0x12: "SUB_FUNC_NOT_SUPPORTED_INVALID_FORMAT",
    0x21: "BUSY_REPEAT_REQUEST",
    0x22: "CONDITIONS_NOT_CORRECT",
    0x23: "ROUTINE_NOT_COMPLETE",
    0x31: "REQUEST_OUT_OF_RANGE",
    0x33: "SECURITY_ACCESS_DENIED",
    0x78: "RESPONSE_PENDING",
    0x80: "SERVICE_NOT_SUPPORTED_IN_ACTIVE_DIAG_SESSION",
}

_HEX_RE = re.compile(rb"^[0-9A-Fa-f]*$")
_ANSI_RE = re.compile(r"\x1b\[[0-9;]*m")
_ESP_LOG_RE = re.compile(r"^([EWIDV]) \((\d+)\) ([^:]*): ?(.*)$")


class KwpError(Exception):
    """Base class for diagnostic errors."""


class KwpTimeout(KwpError):
    """No (final) response arrived in time."""


class KwpNegativeResponse(KwpError):
    def __init__(self, sid: int, nrc: int):
        self.sid = sid
        self.nrc = nrc
        name = NRC_NAMES.get(nrc, "0x%02X" % nrc)
        super().__init__("Negative response to SID 0x%02X: %s" % (sid, name))


class KwpBadResponse(KwpError):
    """A frame arrived but it does not look like a response to our request."""


@dataclass
class Frame:
    id: int
    data: bytes


@dataclass
class LogLine:
    """One line of ESP_LOG output, parsed where possible."""
    raw: str
    level: Optional[str] = None
    tcu_ms: Optional[int] = None
    tag: Optional[str] = None
    msg: Optional[str] = None

    @classmethod
    def parse(cls, text: str) -> "LogLine":
        clean = _ANSI_RE.sub("", text)
        m = _ESP_LOG_RE.match(clean)
        if m:
            return cls(raw=clean, level=m.group(1), tcu_ms=int(m.group(2)),
                       tag=m.group(3), msg=m.group(4))
        return cls(raw=clean)


def encode_request(payload: bytes, req_id: int = KWP_ECU_RX_ID) -> bytes:
    """Build the raw bytes the TCU expects for one request."""
    length = 2 + len(payload)
    return bytes([(length >> 8) & 0xFF, length & 0xFF,
                  (req_id >> 8) & 0xFF, req_id & 0xFF]) + bytes(payload)


def decode_frame_line(line: bytes) -> Optional[Frame]:
    """Decode a ``#IIIIhex...`` line (without the newline). None if invalid."""
    if len(line) < 5 or line[0:1] != b"#":
        return None
    body = line[1:]
    if len(body) % 2 != 0 or not _HEX_RE.match(body):
        return None
    try:
        raw = bytes.fromhex(body.decode("ascii"))
    except ValueError:
        return None
    return Frame(id=(raw[0] << 8) | raw[1], data=raw[2:])


class LineDemux:
    """
    Splits the incoming byte stream into diagnostic frames and log lines.

    ``feed()`` yields ``("frame", Frame)``, ``("log", str)`` or
    ``("bad_frame", str)`` tuples.
    """
    MAX_LINE = 64 * 1024  # a '#' frame can be up to ~8 KiB; logs are far shorter

    def __init__(self) -> None:
        self._buf = bytearray()

    def feed(self, data: bytes) -> Iterator[Tuple[str, object]]:
        self._buf += data
        while True:
            nl = self._buf.find(b"\n")
            if nl < 0:
                if len(self._buf) > self.MAX_LINE:
                    # Garbage without newline (e.g. boot ROM output at the
                    # wrong baud rate).  Flush it as a raw log chunk.
                    chunk = bytes(self._buf)
                    self._buf.clear()
                    yield ("log", chunk.decode("utf-8", errors="replace"))
                return
            line = bytes(self._buf[:nl]).rstrip(b"\r")
            del self._buf[:nl + 1]
            if not line:
                continue
            if line[0:1] == b"#":
                frame = decode_frame_line(line)
                if frame is not None:
                    yield ("frame", frame)
                else:
                    yield ("bad_frame", line.decode("utf-8", errors="replace"))
            else:
                yield ("log", line.decode("utf-8", errors="replace"))


class SerialReader(threading.Thread):
    """
    Background thread that drains the serial port, demultiplexes it and
    dispatches frames to a queue and log lines to a callback.

    ``port`` only needs a pyserial-like interface: ``read(n)``, ``in_waiting``
    and ``timeout``.  That keeps it testable without hardware.
    """

    def __init__(self, port, on_log: Callable[[str], None],
                 on_bad_frame: Optional[Callable[[str], None]] = None) -> None:
        super().__init__(name="nag52-serial-reader", daemon=True)
        self.port = port
        self.frames: "queue.Queue[Frame]" = queue.Queue()
        self.on_log = on_log
        self.on_bad_frame = on_bad_frame
        self.error: Optional[BaseException] = None
        self.bytes_rx = 0
        self.bad_frames = 0
        self._stop = threading.Event()
        self._demux = LineDemux()

    def stop(self) -> None:
        self._stop.set()

    def run(self) -> None:
        try:
            while not self._stop.is_set():
                n = self.port.in_waiting
                data = self.port.read(n if n > 0 else 1)
                if not data:
                    continue
                self.bytes_rx += len(data)
                for kind, item in self._demux.feed(data):
                    if kind == "frame":
                        self.frames.put(item)
                    elif kind == "log":
                        self.on_log(item)  # type: ignore[arg-type]
                    else:
                        self.bad_frames += 1
                        if self.on_bad_frame:
                            self.on_bad_frame(item)  # type: ignore[arg-type]
        except BaseException as exc:  # noqa: BLE001 - surfaced to the main thread
            self.error = exc

    def drain_frames(self) -> int:
        """Throw away any queued frames (stale responses). Returns count."""
        n = 0
        while True:
            try:
                self.frames.get_nowait()
                n += 1
            except queue.Empty:
                return n


class KwpClient:
    """
    Request/response client on top of a ``SerialReader``.

    The TCU is strictly one-request-at-a-time; do not call from multiple
    threads.
    """

    def __init__(self, port, reader: SerialReader, timeout: float = 0.5,
                 retries: int = 2) -> None:
        self.port = port
        self.reader = reader
        self.timeout = timeout
        self.retries = retries
        self.last_tx = 0.0
        self.stats = {"requests": 0, "retries": 0, "timeouts": 0,
                      "negative": 0, "bad": 0}

    # -- low level ---------------------------------------------------------
    def request(self, payload: bytes, timeout: Optional[float] = None) -> bytes:
        """
        Send ``payload`` (SID + args) and return the positive response payload
        (including the SID+0x40 byte).  Retries on timeout / corrupt frame.
        """
        timeout = self.timeout if timeout is None else timeout
        last_err: KwpError = KwpTimeout("no attempt made")
        for attempt in range(self.retries + 1):
            if attempt:
                self.stats["retries"] += 1
            try:
                return self._request_once(payload, timeout)
            except (KwpTimeout, KwpBadResponse) as exc:
                last_err = exc
                if self.reader.error is not None:
                    raise
        raise last_err

    def _request_once(self, payload: bytes, timeout: float) -> bytes:
        self.reader.drain_frames()
        self.stats["requests"] += 1
        self.port.write(encode_request(payload))
        self.last_tx = time.monotonic()
        deadline = self.last_tx + timeout
        sid = payload[0]
        while True:
            remaining = deadline - time.monotonic()
            if remaining <= 0:
                self.stats["timeouts"] += 1
                raise KwpTimeout("SID 0x%02X: no response within %.2fs" % (sid, timeout))
            if self.reader.error is not None:
                raise KwpTimeout("serial reader died: %r" % (self.reader.error,))
            try:
                frame = self.reader.frames.get(timeout=min(remaining, 0.05))
            except queue.Empty:
                continue
            data = frame.data
            if not data:
                continue
            if data[0] == 0x7F:
                if len(data) >= 3 and data[1] == sid and data[2] == NRC_RESPONSE_PENDING:
                    deadline = time.monotonic() + max(timeout, 2.0)
                    continue
                if len(data) >= 3 and data[1] == sid:
                    self.stats["negative"] += 1
                    raise KwpNegativeResponse(sid, data[2])
                # negative response to some other SID: stale, ignore
                continue
            if data[0] == sid + 0x40:
                return bytes(data)
            # A positive response to something else (stale). Keep waiting.
            self.stats["bad"] += 1

    # -- services ----------------------------------------------------------
    def start_session(self, mode: int = SESSION_EXTENDED) -> None:
        resp = self.request(bytes([SID_START_DIAGNOSTIC_SESSION, mode]))
        if len(resp) < 2 or resp[1] != mode:
            raise KwpBadResponse("unexpected StartDiagnosticSession reply %s" % resp.hex())

    def tester_present(self) -> None:
        self.request(bytes([SID_TESTER_PRESENT, KWP_CMD_RESPONSE_REQUIRED]))

    def read_local_ident(self, rli: int) -> bytes:
        """ReadDataByLocalIdentifier: returns the record bytes (no SID / RLI)."""
        resp = self.request(bytes([SID_READ_DATA_LOCAL_IDENT, rli]))
        if len(resp) < 2 or resp[1] != rli:
            raise KwpBadResponse("RLI 0x%02X: reply carries RLI 0x%02X"
                                 % (rli, resp[1] if len(resp) > 1 else -1))
        return resp[2:]

    def read_ecu_serial(self) -> str:
        return self.read_local_ident(0xE1).decode("ascii", errors="replace")

    def read_memory(self, address: int, length: int) -> bytes:
        """
        ReadMemoryByAddress (3 byte address, 1 byte length, max 255).  The
        firmware maps 0x800000.. onto the calibration flash partition and lower
        addresses onto SRAM/PSRAM (see kwp2000.cpp process_read_mem_address).
        """
        if not 0 < length <= 255:
            raise ValueError("length must be 1..255")
        req = bytes([SID_READ_MEM_BY_ADDRESS, (address >> 16) & 0xFF, (address >> 8) & 0xFF,
                     address & 0xFF, length])
        resp = self.request(req)
        data = resp[1:]
        if len(data) != length:
            raise KwpBadResponse("ReadMemory 0x%06X: expected %d bytes, got %d" % (address, length, len(data)))
        return data


def open_serial(port: str, baud: int = 921600, reset: bool = False):
    """
    Open the CP210x port without toggling the ESP32 reset/boot lines.

    pyserial asserts DTR and RTS on open by default, which on boards with the
    usual auto-program circuit resets the chip.  We pre-clear both so that
    attaching the logger never disturbs a running TCU.  ``reset=True`` pulses
    RTS (EN) so that boot logs are captured too.
    """
    import serial  # imported lazily so the rest of the package works without it

    ser = serial.Serial()
    ser.port = port
    ser.baudrate = baud
    ser.timeout = 0.05
    ser.write_timeout = 1.0
    ser.dtr = False
    ser.rts = False
    ser.rtscts = False
    ser.dsrdtr = False
    ser.open()
    if reset:
        ser.dtr = False
        ser.rts = True
        time.sleep(0.1)
        ser.rts = False
    ser.reset_input_buffer()
    return ser
