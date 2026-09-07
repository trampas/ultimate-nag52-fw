"""Command line interface: ``python nag52log.py <command> ...``."""
from __future__ import annotations

import argparse
import json
import signal
import sys
from typing import List, Optional

from . import __version__
from .protocol import SESSION_CUSTOM_UN52, SESSION_EXTENDED
from .records import DEFAULT_FAST, DEFAULT_ONCE, DEFAULT_SLOW, RECORDS


def _split(s: Optional[str]) -> Optional[List[str]]:
    if s is None:
        return None
    return [x for x in s.split(",") if x.strip()]


def cmd_record(args: argparse.Namespace) -> int:
    from .logger import Nag52Logger, default_output_path

    out = args.output or default_output_path(args.dir)
    session = SESSION_CUSTOM_UN52 if args.session == "un52" else SESSION_EXTENDED
    fast = _split(args.records)
    slow = _split(args.slow)
    once = _split(args.once)
    if fast is not None and "tcu_time" not in fast:
        fast = ["tcu_time"] + fast
    logger = Nag52Logger(
        args.port, out, baud=args.baud, fast=fast, slow=slow, once=once,
        slow_interval=args.slow_interval, rate_hz=args.rate, poll=not args.no_poll,
        session=session, echo_log=not args.no_echo, status=not args.quiet,
        reset=args.reset, request_timeout=args.timeout, max_cycles=args.cycles,
    )

    def _sigterm(_signum, _frame):  # allow `timeout`/systemd to stop us cleanly
        logger.stop()

    signal.signal(signal.SIGTERM, _sigterm)
    try:
        logger.run()
    except Exception as exc:  # noqa: BLE001
        print("[nag52log] fatal: %s" % exc, file=sys.stderr)
        return 1
    return 0


def cmd_export(args: argparse.Namespace) -> int:
    from .reader import LogFile

    lf = LogFile.load(args.file)
    out = args.output or (args.file.rsplit(".jsonl", 1)[0] + ".csv")
    cols = _split(args.columns)
    n = lf.write_csv(out, cols)
    print("wrote %d rows x %d columns to %s" % (n, len(cols) if cols else len(lf.columns()), out))
    if args.logs:
        m = lf.write_log_text(args.logs)
        print("wrote %d log lines to %s" % (m, args.logs))
    return 0


def cmd_info(args: argparse.Namespace) -> int:
    from .reader import LogFile

    lf = LogFile.load(args.file)
    print(json.dumps(lf.summary(), indent=2))
    if args.shifts:
        for s in lf.shifts():
            print("  %8.2fs  %s -> %s  %.3fs  (seq %d-%d, profile %s)" % (
                s["t_start"], s["from"], s["to"], s.get("duration", 0), s["seq_start"],
                s.get("seq_end", -1), s.get("profile")))
    if args.columns:
        for c in lf.columns():
            print("  " + c)
    return 0


def cmd_records(_args: argparse.Namespace) -> int:
    for name, rec in RECORDS.items():
        tag = {"fast": "", "slow": " [slow]", "once": " [once]"}[rec.group]
        print("%-14s RLI 0x%02X  %3d B%s  %s" % (name, rec.rli, rec.size, tag, rec.desc))
        for f in rec.fields:
            extra = []
            if f.unit:
                extra.append(f.unit)
            if f.enum:
                extra.append("enum " + f.enum)
            if f.desc:
                extra.append(f.desc)
            print("    %-30s %s" % (f.name, "  ".join(extra)))
    print("\ndefault fast: %s\ndefault slow: %s\ndefault once: %s" % (
        ",".join(DEFAULT_FAST), ",".join(DEFAULT_SLOW), ",".join(DEFAULT_ONCE)))
    return 0


def cmd_ports(_args: argparse.Namespace) -> int:
    try:
        from serial.tools import list_ports
    except ImportError:
        print("pyserial is not installed (pip install -r requirements.txt)")
        return 1
    ports = list(list_ports.comports())
    usb = [p for p in ports if p.vid is not None]
    for p in (usb or ports):
        mark = "  <- CP210x (Ultimate-NAG52)" if p.vid == 0x10C4 else ""
        print("%-16s %s%s" % (p.device, p.description, mark))
    if not usb:
        print("(no USB serial devices found; is the TCU plugged in?)")
    return 0


def build_parser() -> argparse.ArgumentParser:
    ap = argparse.ArgumentParser(prog="nag52log",
                                 description="Serial data logger for the Ultimate-NAG52 TCU")
    ap.add_argument("--version", action="version", version=__version__)
    sub = ap.add_subparsers(dest="cmd")

    r = sub.add_parser("record", help="record live data + ESP_LOG output to a .jsonl file (default)")
    r.add_argument("-p", "--port", default="/dev/ttyUSB0", help="serial port (default /dev/ttyUSB0)")
    r.add_argument("-b", "--baud", type=int, default=921600)
    r.add_argument("-o", "--output", help="output file (.jsonl or .jsonl.gz); default logs/nag52_<stamp>.jsonl")
    r.add_argument("--dir", default="logs", help="directory for auto-named output files")
    r.add_argument("--records", help="comma separated records polled every cycle (see `records`)")
    r.add_argument("--slow", help="comma separated records polled every --slow-interval")
    r.add_argument("--once", help="comma separated records read once at connect")
    r.add_argument("--slow-interval", type=float, default=1.0, help="seconds between slow-record polls")
    r.add_argument("--rate", type=float, default=0.0, help="target cycles per second (0 = as fast as possible)")
    r.add_argument("--timeout", type=float, default=0.5, help="per-request timeout in seconds")
    r.add_argument("--cycles", type=int, help="stop after this many cycles")
    r.add_argument("--session", choices=["extended", "un52"], default="extended",
                   help="diagnostic session to open (both give the fast 2 ms server loop)")
    r.add_argument("--no-poll", action="store_true", help="only capture ESP_LOG output, send nothing")
    r.add_argument("--no-echo", action="store_true", help="do not print TCU log lines to stdout")
    r.add_argument("-q", "--quiet", action="store_true", help="no status line on stderr")
    r.add_argument("--reset", action="store_true",
                   help="pulse RTS/EN on open to reboot the TCU (captures boot logs; needs auto-reset circuit)")
    r.set_defaults(func=cmd_record)

    e = sub.add_parser("export", help="flatten a .jsonl log into CSV")
    e.add_argument("file")
    e.add_argument("-o", "--output", help="CSV path (default: alongside input)")
    e.add_argument("--columns", help="comma separated subset of columns, e.g. t,sensors.input_rpm")
    e.add_argument("--logs", help="also write the ESP_LOG lines as plain text to this path")
    e.set_defaults(func=cmd_export)

    i = sub.add_parser("info", help="summarise a .jsonl log")
    i.add_argument("file")
    i.add_argument("--shifts", action="store_true", help="list detected gear changes")
    i.add_argument("--columns", action="store_true", help="list available CSV columns")
    i.set_defaults(func=cmd_info)

    rc = sub.add_parser("records", help="list the live-data records this logger understands")
    rc.set_defaults(func=cmd_records)

    pp = sub.add_parser("ports", help="list serial ports")
    pp.set_defaults(func=cmd_ports)
    return ap


def main(argv: Optional[List[str]] = None) -> int:
    argv = list(sys.argv[1:] if argv is None else argv)
    ap = build_parser()
    known = {"record", "export", "info", "records", "ports"}
    if not argv or (argv[0] not in known and not argv[0].startswith("-")):
        argv = ["record"] + argv
    elif argv[0].startswith("-") and argv[0] not in ("-h", "--help", "--version"):
        argv = ["record"] + argv
    args = ap.parse_args(argv)
    if not hasattr(args, "func"):
        ap.print_help()
        return 2
    return args.func(args)
