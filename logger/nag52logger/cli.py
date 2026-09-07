"""Command line interface: ``python nag52log.py <command> ...``."""
from __future__ import annotations

import argparse
import json
import signal
import sys
import time
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
    if args.dash:
        # The score comes from the driving_dynamics record, which is not in the
        # default set - one extra round trip, only paid when the view is on.
        fast = list(fast if fast is not None else DEFAULT_FAST)
        if "driving_dynamics" not in fast:
            fast.append("driving_dynamics")
    logger = Nag52Logger(
        args.port, out, baud=args.baud, fast=fast, slow=slow, once=once,
        slow_interval=args.slow_interval, rate_hz=args.rate, poll=not args.no_poll,
        session=session, echo_log=(not args.no_echo) and not args.dash, status=not args.quiet,
        reset=args.reset, request_timeout=args.timeout, max_cycles=args.cycles,
        accel=args.accel, accel_rate=args.accel_rate, trace=not args.no_shift_trace,
        dashboard=args.dash, dash_window=args.dash_window,
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


def cmd_calibration(args: argparse.Namespace) -> int:
    """Print the calibration block recorded in a log (or read live from the TCU with --live)."""
    from .calibration import decode_calibration, summarize
    if args.live:
        from .protocol import KwpClient, SerialReader, open_serial
        from .calibration import read_calibration
        ser = open_serial(args.port, args.baud, reset=False)
        reader = SerialReader(ser, lambda _l: None, lambda: None)
        reader.start()
        try:
            client = KwpClient(ser, reader, timeout=0.5)
            client.start_session(SESSION_EXTENDED)
            cal = read_calibration(client)
        finally:
            reader.stop()
            ser.close()
    else:
        from .reader import LogFile
        lf = LogFile.load(args.file)
        cal = (lf.snapshot or {}).get("calibration")
        if cal is None:
            print("no calibration block in this log (recorded with an older logger?)", file=sys.stderr)
            return 1
        if args.raw and isinstance(cal, dict) and cal.get("_raw"):
            cal = decode_calibration(bytes.fromhex(cal["_raw"]))
    out = cal if args.full else summarize(cal)
    if args.output:
        with open(args.output, "w") as fh:
            json.dump(cal, fh, indent=2)
        print("wrote %s" % args.output)
    print(json.dumps(out, indent=2))
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


def cmd_accel(args: argparse.Namespace) -> int:
    """List IIO accelerometers and time one, so a useless rate is found before the drive."""
    from .accel import USEFUL_HZ, AccelSource, find_accelerometers

    devices = find_accelerometers()
    if not devices:
        print("no IIO accelerometer found (looked under /sys/bus/iio/devices)")
        return 1
    for dev in devices:
        d = dev.describe()
        print("%s  %s" % (d["node"], d["name"]))
        print("    path        %s" % d["path"])
        print("    scale       %g m/s^2 per count" % d["scale"])
        print("    rate        %s Hz%s" % (d["sampling_frequency"],
              "" if not d["available_frequencies"] else
              "  (available: %s)" % d["available_frequencies"]))
        print("    buffer      %s" % ("yes" if d["buffer"] else "no"))
        if d["buffer"] and not d["buffer_readable"]:
            print("                not readable as this user - falling back to slow sysfs polling")
            print("                (fix: udev rule granting read on %s + write on the sysfs attrs)"
                  % dev.dev_node)
        src = AccelSource(dev, time.monotonic(), rate_hz=args.rate)
        src.start()
        time.sleep(max(0.5, args.seconds))
        src.stop()
        a = src.summary()
        print("    MEASURED    %s Hz over %.1f s via %s (%d samples)"
              % (a["measured_rate_hz"], args.seconds, a["backend"], a["samples"]))
        if src.error:
            print("    error       %s" % src.error)
        if not a["usable_for_shift_shock"]:
            print("    VERDICT     too slow for shift shock - needs >= %g Hz, this is %s Hz"
                  % (USEFUL_HZ, a["measured_rate_hz"]))
        else:
            print("    VERDICT     usable for shift shock")
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
    r.add_argument("--accel", nargs="?", const="auto", default="auto", metavar="DEV",
                   help="host accelerometer to record alongside the TCU data (default: auto, "
                        "the first one found). Also accepts an iio node (iio:device2), a "
                        "device name, or a sysfs path -- see the `accel` subcommand")
    r.add_argument("--no-accel", dest="accel", action="store_const", const=None,
                   default=argparse.SUPPRESS,
                   help="do not record an accelerometer")
    r.add_argument("--dash", action="store_true",
                   help="live terminal view of the agility score and shift quality "
                        "(implies --no-echo, and polls driving_dynamics)")
    r.add_argument("--dash-window", type=float, default=120.0, metavar="S",
                   help="seconds of history in the live view (default 120)")
    r.add_argument("--no-shift-trace", action="store_true",
                   help="do not read back the TCU's high rate shift recorder")
    r.add_argument("--accel-rate", type=float, default=0.0, metavar="HZ",
                   help="requested accelerometer sample rate (0 = leave the driver's setting)")
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

    ca = sub.add_parser("calibration", help="show the EGS calibration block stored in a log, or read it live")
    ca.add_argument("file", nargs="?", help=".jsonl log (omit with --live)")
    ca.add_argument("--live", action="store_true", help="read the block from the TCU now instead of a log")
    ca.add_argument("-p", "--port", default="/dev/ttyUSB0")
    ca.add_argument("-b", "--baud", type=int, default=921600)
    ca.add_argument("--full", action="store_true", help="print every field, not just the summary")
    ca.add_argument("--raw", action="store_true", help="re-decode from the stored raw bytes with this logger's layout")
    ca.add_argument("-o", "--output", help="also write the full decoded block as JSON to this path")
    ca.set_defaults(func=cmd_calibration)

    rc = sub.add_parser("records", help="list the live-data records this logger understands")
    rc.set_defaults(func=cmd_records)

    pp = sub.add_parser("ports", help="list serial ports")
    pp.set_defaults(func=cmd_ports)

    ac = sub.add_parser("accel", help="list host accelerometers and measure their real sample rate")
    ac.add_argument("--seconds", type=float, default=3.0, help="how long to measure for")
    ac.add_argument("--rate", type=float, default=0.0, metavar="HZ", help="request this rate first")
    ac.set_defaults(func=cmd_accel)
    return ap


def main(argv: Optional[List[str]] = None) -> int:
    argv = list(sys.argv[1:] if argv is None else argv)
    ap = build_parser()
    known = {"record", "export", "info", "records", "ports", "calibration", "accel"}
    if not argv or (argv[0] not in known and not argv[0].startswith("-")):
        argv = ["record"] + argv
    elif argv[0].startswith("-") and argv[0] not in ("-h", "--help", "--version"):
        argv = ["record"] + argv
    args = ap.parse_args(argv)
    if not hasattr(args, "func"):
        ap.print_help()
        return 2
    return args.func(args)
