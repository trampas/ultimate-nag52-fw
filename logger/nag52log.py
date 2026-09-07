#!/usr/bin/env python3
"""Entry point: ``./nag52log.py --help``."""
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

from nag52logger.cli import main  # noqa: E402

if __name__ == "__main__":
    sys.exit(main())
