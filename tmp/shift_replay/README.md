# Shift replay harness (host build)

Replays each gear change from `logger/logs/nag52_20260907_054611.jsonl` through the firmware's
shift algorithms (`ShiftingAlgorithm` / `CrossoverShift` / `ReleasingShift` + `PressureManager`)
compiled for the host, exactly as `Gearbox::elapse_shift` drives them, using the logged sensor
inputs on a 20 ms grid. Open loop: the logged RPMs do not react to changed pressures.

* `egsdb.py`            decodes the config app's `egs_db.bin`; `cal_data.h` is the EGS PN 0205459132
                        block set (hydr STDP / mech 51 / tcc 71 / shift SM00) matched to the log.
* `prep_shifts.py`      log -> `shifts/shift_NN_from_to.txt` (inputs + logged outputs per 20 ms).
* `build.sh new <repo>` / `build.sh old baseline_1b96089`  -> `sim_new`, `sim_old`.
                        A/B builds must differ only in `<repo>`; note `maps.cpp` is taken from
                        the variant tree, so shift map and shift time map changes are compared
                        correctly. Recreate an old baseline tree with
                        `git worktree add baseline_<sha> <sha>`.
* `run_all.py`          fits the start offset of the old build to the logged p_on trace, runs both,
                        writes `results/*.old.txt|*.new.txt` and `results/summary.json`.
* `sim_new shift.txt out.txt --ind-from-driver`  what-if: indicated torque = driver torque
                        (results in `results_whatif/`).

Not captured by the log and therefore assumed default: module settings (PRM/REL/CRS/ADP/SBS), the
NVS-stored fill/low-fill/TCC maps and the adaptation maps (all zero here).
