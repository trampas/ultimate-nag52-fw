# Torque-converter calibration what-if: egs_db block 71 vs the EGS51 ROM's own maps

Date: 2026-09-09. Log: logger/logs/nag52_20260908_093707.jsonl (firmware ea733f5, 45 shifts).
Question: the TCC block "71" the car runs is not in its own ECU ROM (A0215451432). The ROM holds two
converter characterizations. Does swapping them in change what the shift algorithms command?

## The three blocks (TorqueConverterCalibration)

| block | multiplier_map x / z | pump_map_x | pump_map_z |
|---|---|---|---|
| egs_db 71 (in the car) | [0,883] / [177,100] | [0,104,381,575,674,825,883,1000,1056,1500,2500] | [4211,4276,4252,4187,3902,3106,2724,0,797,3252,10406] |
| ROM variant A @bank0 0x0F370 | [0,917] / [179,100] | [0,379,500,676,850,891,917,1000,1056,1500,2500] | [4333,4676,4756,4584,3976,3699,3250,0,1295,5284,17305] |
| ROM variant B @bank0 0x0F7D4 | [0,914] / [170,100] | [0,125,392,573,726,850,914,1000,1056,1500,2500] | [4637,4729,4729,4980,4729,4148,3712,0,1295,5284,17305] |

Which of A/B applies to this car is coding-selected in the ECU and unknown.

## Method

`build.sh new` (baseline, cal_data.h = block 71), `build.sh tccA` / `build.sh tccB` with cal_data_tccA.h /
cal_data_tccB.h swapped in. All runs use the new harness flag `--recompute-input-trq`, which derives
input torque from driver torque through the ACTIVE multiplier/pump maps exactly as gearbox.cpp does
(without it the harness reuses the logged input torque, which the TCU computed with block 71).
Per-shift outputs are in per_shift/ (ROW columns: see harness.cpp COLS line). Deltas below are the
maximum absolute per-cycle difference from baseline over the whole shift.

## Result

- Shifts starting UNLOCKED (speed ratio < 0.9): n=8. max dp_on A=132 mBar, B=102 mBar; max dItrq A=10 Nm, B=8 Nm.
- Shifts starting at/near lockup (>= 0.9): n=37. max dp_on A=117 mBar, B=88 mBar.
- Torque request amount: unchanged in every shift.
- Against commanded pressures of 3000-7000 mBar this is 2-4 %: minor on the shift side. Park it.

## Limitation

The harness runs the shift algorithms open-loop. It does NOT run the TCC lockup controller
(torque_converter.cpp, pump_trq_targ from pump_map_z), which is where a 1.6x higher overrun pump
torque would actually act. Lockup/slip behaviour is untested by this experiment.

## Per-shift table

| shift | ratio0 | dItrq A | dItrq B | dp_on A | dp_on B | dspc A | dspc B |
|---|---|---|---|---|---|---|---|
| 00_D2_D1 | 0.70 | 6 | 4 | 100 | 60 | 100 | 60 |
| 01_D1_D2 | 0.94 | 0 | 0 | 0 | 0 | 0 | 0 |
| 02_D2_D3 | 0.96 | 0 | 0 | 0 | 0 | 0 | 0 |
| 03_D3_D4 | 0.97 | 0 | 0 | 0 | 0 | 0 | 0 |
| 04_D4_D3 | 1.12 | 0 | 0 | 0 | 0 | 0 | 0 |
| 05_D3_D2 | 1.03 | 0 | 0 | 0 | 0 | 0 | 0 |
| 06_D2_D1 | 0.39 | 0 | 0 | 0 | 0 | 0 | 0 |
| 07_D1_D2 | 0.96 | 0 | 0 | 0 | 0 | 0 | 0 |
| 08_D2_D3 | 0.94 | 0 | 0 | 0 | 0 | 0 | 0 |
| 09_D3_D4 | 1.05 | 6 | 4 | 76 | 51 | 76 | 51 |
| 10_D4_D3 | 0.70 | 7 | 6 | 77 | 57 | 77 | 57 |
| 11_D3_D4 | 0.93 | 8 | 6 | 102 | 60 | 102 | 60 |
| 12_D4_D3 | 0.88 | 10 | 8 | 116 | 102 | 116 | 102 |
| 13_D3_D4 | 0.94 | 0 | 0 | 0 | 0 | 0 | 0 |
| 14_D4_D5 | 0.98 | 0 | 0 | 0 | 0 | 0 | 0 |
| 15_D5_D4 | 1.45 | 0 | 0 | 0 | 0 | 0 | 0 |
| 16_D4_D3 | 1.16 | 0 | 0 | 0 | 0 | 0 | 0 |
| 17_D3_D2 | 1.28 | 6 | 5 | 71 | 59 | 71 | 59 |
| 18_D2_D3 | 0.94 | 8 | 6 | 117 | 88 | 117 | 88 |
| 19_D3_D2 | 0.85 | 10 | 8 | 132 | 102 | 132 | 102 |
| 20_D2_D3 | 0.99 | 0 | 0 | 0 | 0 | 0 | 0 |
| 21_D3_D4 | 0.96 | 0 | 0 | 0 | 0 | 0 | 0 |
| 22_D4_D5 | 0.97 | 0 | 0 | 0 | 0 | 0 | 0 |
| 23_D5_D4 | 1.44 | 0 | 0 | 0 | 0 | 0 | 0 |
| 24_D4_D3 | 1.10 | 0 | 0 | 0 | 0 | 0 | 0 |
| 25_D3_D2 | 1.01 | 0 | 0 | 0 | 0 | 0 | 0 |
| 26_D2_D1 | 0.59 | 0 | 0 | 0 | 0 | 0 | 0 |
| 27_D1_D2 | 0.96 | 1 | 0 | 16 | 0 | 16 | 0 |
| 28_D2_D3 | 0.95 | 3 | 2 | 44 | 30 | 44 | 30 |
| 29_D3_D4 | 0.95 | 1 | 1 | 12 | 6 | 12 | 6 |
| 30_D4_D5 | 0.99 | 0 | 0 | 0 | 0 | 0 | 0 |
| 31_D5_D4 | 1.55 | 6 | 4 | 64 | 43 | 64 | 43 |
| 32_D4_D3 | 0.86 | 6 | 5 | 76 | 51 | 76 | 51 |
| 33_D3_D4 | 0.97 | 0 | 0 | 0 | 0 | 0 | 0 |
| 34_D4_D3 | 1.12 | 0 | 0 | 0 | 0 | 0 | 0 |
| 35_D3_D2 | 1.02 | 5 | 3 | 58 | 35 | 58 | 35 |
| 36_D2_D1 | 0.66 | 5 | 3 | 84 | 50 | 84 | 50 |
| 37_D1_D2 | 0.96 | 0 | 0 | 0 | 0 | 0 | 0 |
| 38_D2_D3 | 0.95 | 0 | 0 | 0 | 0 | 0 | 0 |
| 39_D3_D4 | 0.99 | 0 | 0 | 0 | 0 | 0 | 0 |
| 40_D4_D3 | 1.13 | 0 | 0 | 0 | 0 | 0 | 0 |
| 41_D3_D2 | 1.07 | 6 | 5 | 78 | 52 | 78 | 52 |
| 42_D2_D3 | 0.95 | 2 | 1 | 13 | 13 | 13 | 13 |
| 43_D3_D2 | 1.16 | 1 | 1 | 21 | 21 | 21 | 21 |
| 44_D2_D1 | 0.99 | 0 | 0 | 0 | 0 | 0 | 0 |
