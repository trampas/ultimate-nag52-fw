# 722.6 + EGS51 Primer (Physical + OEM Behavior)

## Scope

This document is the physical and OEM-behavior primer for developers working on NAG52.
It focuses on:

- physical transmission behavior,
- hydraulic control circuits,
- EGS51 observed behavior from ROM analysis,
- temperature sensing and conversion context.

NAG52-specific implementation details are kept in the companion document:

- [NAG52 behavior and parity guide](nag52_behavior_and_parity.md)

## Evidence tags

- Repo: measured or reverse-engineered in this repository.
- External: public datasheet, handbook, patent, or technical publication.

## 1. Physical transmission overview

The 722.6 (5G-Tronic family) is a 5-speed automatic transmission with a torque converter lockup clutch, multiple planetary gear elements, and multiple apply/release friction elements. [E4]

In this repo's calibration model, friction elements are referenced as K1, K2, K3, B1, B2, B3 and tied to gear/circuit logic used by control code and analysis scripts. [R1]

For this car's measured calibration snapshot, ratio table and strongest-loaded clutch mapping are documented in the transmission notes. [R1]

## 2. Hydraulic model developers must hold in mind

Three on/off shift solenoids select circuits, while two regulators set pressure levels:

- Y3 -> 1-2 and 4-5 circuit
- Y5 -> 2-3 circuit
- Y4 -> 3-4 circuit
- MPC -> working/line pressure regulator
- SPC -> shift pressure regulator
- TCC -> converter lockup control path [R1]

Critical selector rule:

- Shift solenoid ON: clutch feed is from SPC.
- Shift solenoid OFF: clutch feed is from working pressure (MPC path). [R1]

This is why end-of-shift SPC ramps are pressure-matching handover events, not automatically "harshness" errors. [R1]

## 3. EGS51 output-driver and solenoid mapping

Corrected EGS51 analysis indicates the L9341 output word is decoded as:

- OUT3 -> Y3
- OUT2 -> Y4
- OUT1 -> Y5
- OUT4 -> TCC-related channel behavior [R2]

This mapping is confirmed two ways: the ST L9341 datasheet frame definition (bits 15-12/11-8/7-4/3-0 = channel 4/3/2/1) and the owner's board trace of the four output pins. [E1][R2]

It replaced an earlier bit-order interpretation that briefly mis-attributed one PWM behavior to Y4; the PWM channel is in fact the **TCC**, not Y4. All three shift solenoids are driven peak-and-hold: full duty for three PWM periods, then roughly 25-38 percent selected by a temperature index. [R2][R3]

## 4. EGS51 P/N and engagement behavior

The engagement state machine (bank1 `5BB6`-`6191`, nine sub-states) has been transcribed
into C and checked instruction-by-instruction against an execution oracle. What holds: [R2][R3][R7]

- In N/P idle (state 8), EGS51 requests **Y5 + Y4 together** as the hydraulic-neutral pair,
  with pressure targets MPC 0 / clutch 200 / SPC 800 in ROM units.
- On leaving N/P, EGS51 **releases both** before starting the engagement sequence at state 0.
- Reverse engagement energizes Y4 on its branch.

**Withdrawn:** an earlier pass concluded that Drive engagement runs through Y3/Y5 with "Y4
normally off". Instruction-level review shows the full machine **also sets Y4 in states 1, 2,
4 and 5** under their own conditions. Whether a real-world Drive engagement reaches those
paths cannot be decided from this routine alone; it depends on the producers of the gear and
flag inputs (`B3`, `AB`, the `9A`/`94`/`1BD` flag words), which are not yet reconstructed.
Treat "EGS51 never uses Y4 for D" as **unsupported**, not as established OEM behavior. [R7]

Two further mechanics worth holding:

- **State 0 falls through into state 1 in the same invocation**, so pressure targets can move
  twice in one cycle.
- **Timer arithmetic wraps at 8 bits.** Two cold fill times of 150 sum to 44, not 300. This is
  real `ADD A,R7` behavior and is preserved in the model. The duration of one timer tick is
  still unestablished, so all EGS51 times are in scheduler cycles, not milliseconds. [R7]

## 5. Temperature sensor curves and conversion context

### 5.1 Sensor family context

Repository findings indicate the TFT resistance behavior aligns with an NXP KTY81-family curve rather than an OEM-unique resistance table. [R2]

Primary sensor datasheet source:

- NXP KTY81 series product data. [E2]

### 5.2 Numeric curve table (KTY81/221)

Extracted from KTY81 series Table 11 (KTY81/221 and KTY81/222), using the KTY81/221 column. [E2][E3]

| Temp (degC) | Min (ohm) | Typ (ohm) | Max (ohm) |
|---|---:|---:|---:|
| -55 | 941 | 970 | 999 |
| -50 | 990 | 1019 | 1049 |
| -40 | 1094 | 1123 | 1153 |
| -30 | 1205 | 1235 | 1264 |
| -20 | 1325 | 1354 | 1382 |
| -10 | 1452 | 1480 | 1508 |
| 0 | 1587 | 1613 | 1640 |
| 10 | 1730 | 1754 | 1779 |
| 20 | 1882 | 1903 | 1924 |
| 25 | 1960 | 1980 | 2000 |
| 30 | 2037 | 2059 | 2081 |
| 40 | 2195 | 2222 | 2250 |
| 50 | 2360 | 2393 | 2426 |
| 60 | 2531 | 2571 | 2611 |
| 70 | 2710 | 2757 | 2804 |
| 80 | 2895 | 2950 | 3005 |
| 90 | 3086 | 3150 | 3214 |
| 100 | 3285 | 3358 | 3431 |
| 110 | 3488 | 3571 | 3655 |
| 120 | 3684 | 3779 | 3873 |
| 125 | 3776 | 3876 | 3976 |
| 130 | 3862 | 3967 | 4073 |
| 140 | 4009 | 4125 | 4241 |
| 150 | 4112 | 4237 | 4363 |

Machine-readable copy used to generate this table:

- [KTY81/221 CSV extraction](references/kty81_221_222_table.csv)

### 5.3 Curve graph (draw.io source and PNG output)

Diagram source:

- [docs/diagrams/kty81_221_curve.drawio](diagrams/kty81_221_curve.drawio)

Expected rendered output (generated from draw.io source):

- docs/diagrams/kty81_221_curve.svg
- docs/diagrams/kty81_221_curve.png
- docs/diagrams/kty81_221_curve.jpg (optional)

Build command:

```sh
make -C docs diagrams
```

Format selection example:

```sh
DRAWIO_FORMATS="svg png" make -C docs diagrams
```

If PNG is missing, run the build command after ensuring either:

- local draw.io CLI is installed, or
- Docker daemon access is available to your user.

### 5.4 EGS51 internal temperature math note

EGS51 linearizes its own ATF input with a straight line, over an 8-sample mean of a paged
analog input:

T_raw ~= ((mean8 * 177) >> 8 - 52) * 2

A straight-line fit (no resistance table anywhere in the ROM) is consistent with a KTY-class
sensor, which supports section 5.1. [R2]

**The unit of `T_raw` is not settled.** A "+50 offset" hypothesis was raised from the CAN
substitute path (when the ATF sensor faults, EGS51 falls back to an engine-frame temperature
byte plus 10, and MB engine temperature bytes are degC+40). It is **not** confirmed:

- the CAN object the substitute is read from has not been identified, only its register
  window, so the +40 premise is unverified for that specific byte; and
- an argument offered for it in an earlier pass was arithmetically wrong.

The reconstructed model therefore keeps **raw ROM units throughout and converts nothing**.
Do not re-base NAG52's temperature axes on this hypothesis. The decisive test is a direct
measurement: hold a known ATF temperature and compare it against the value the ECU reports.
Note that this car's own TFT curve reads roughly 7-10 degC high, so the comparison needs an
independent reference, not the TCU's own number. [R2][R7]

## 6. EGS51 pressure control chain

This is the part of EGS51 that decides how hard it shifts. The chain, end to end, is now
transcribed and oracle-checked: [R3][R7]

```
engagement / shift machines
        |  P_MPC (internal RAM 44:45)        clutch target (46:47)
        v                                            v
        |                                  egs51_spc()  bank1 7093
        |                                            v
        |                                   P_SPC_SOL (48:49)
        v                                            v
   egs51_pressure_demand()  bank1 D76E  <------------+
        v
   demand byte  (MPC 0x37, SPC 0x35)
        v
   PI current loop  bank0 3EEC/3F5C  ->  SFR D9 = 255-u (MPC), SFR DA = u (SPC)
```

### 6.1 Clutch pressure to SPC solenoid pressure

```
SPC = shift_reg_spring_pressure
    + min(positive_signed16(clutch + 20*term), SPC_MAX) * 1000 / shift_spc_gain[idx]
```

The gain is a **divisor**, not a multiplier. NAG52 already implements exactly this relation
in `s_algo.cpp` and `shifting_algo_helpers.cpp`, which is an independent corroboration of the
reading; an earlier EGS51 pass had it inverted and was wrong by a factor of ~3.3 at gain 1993.
The signed sum wraps to 16 bits before the positive clamp. [R3][R7][R8]

### 6.2 Line pressure and the demand byte

```
line   = 1000 * (lp_reg_spring_pressure + P_MPC) / p_multi        (+ shift adder, - shift factor)
inlet  = lerp(line; input_min..input_max -> output_min..output_max)
k      = shift_pressure_addr_percent * (output_max - inlet) / 1000
p_adj  = p + k * positive_signed16(p + inlet_pressure_offset) / 1000   (only when p < inlet)
demand = PCS_map(p_adj, ATF_raw) * 10 / 45
```

`p_multi` and the inlet map are also **divisors/limits**, in the same arrangement NAG52 uses
in `PressureManager::calc_current_linear_sol`. The `*10/45` scaling means the demand byte is
in units of 4.5 mA. [R3][R7][R8]

### 6.3 Seven more calibration fields located

Matching the constants this routine reads against the TCU's own calibration located seven
previously unplaced NAG52 hydraulic fields at fixed bank1 addresses, all byte-for-byte: [R2]

| Field | bank1 address | Value |
|---|---|---:|
| shift_pressure_addr_percent | 0xFFD3 (u8) | 30 |
| inlet_pressure_offset | 0xFFD4 | 1000 |
| extra_pressure_pump_speed_min | 0xFFE3 | 1000 |
| extra_pressure_pump_speed_max | 0xFFE5 | 4000 |
| extra_pressure_adder_r1_1 | 0xFFE7 | 1500 |
| extra_pressure_adder_other_gears | 0xFFE9 | 1000 |
| shift_pressure_factor_percent | 0xFFEB | 37 |

The shift adder is a lerp from zero to `extra_pressure_adder_*` over
`extra_pressure_pump_speed_min..max` - structurally identical to NAG52's own
`extra_p` interpolation over engine speed. [R3][R8]

### 6.4 Current loop

Per channel: a 16-bit integrator biased at 0x8000, `I += Ki*error` saturating, output
`I - 32768 + Kp*error` saturating, then `min(255, value >> 4)`. Kp = 4 and Ki = 2 come from
bank0 ROM `0B38`/`0B39`, and the loop period is 1250 counter ticks. **MPC writes `255-u`,
SPC writes `u`** - only the MPC duty register is inverted. [R3][R7]

## 7. Verifying these claims

Everything above is reproducible from the repository, given the (uncommitted, proprietary)
ROM image:

```sh
python3 tmp/egs51/tests/verify_model.py       # C model vs ROM instruction oracle
python3 tmp/egs51/tools/egs51tool.py verify   # 32 calibration fields vs cal_data.h
```

The first compiles every reconstructed C file with `-Wall -Wextra -Werror -pedantic` and
compares results against an 8051 interpreter executing the original ROM bytes, so it is
independent of Ghidra's decompiler output. The second exits non-zero on any mismatch and
reports `NO DATA` rather than success when it has nothing to compare.

**Scope limit worth respecting:** the oracle covers the routines in the coverage table of
[R7] - ramp/interpolation/map primitives, SPC, pressure demand, timing helpers, engagement,
current control, frame composition, gear map, solenoid select. The newer files (shift
supervisor, TCC control, analog scan, calibration services) compile clean but are
**transcribed, not yet oracle-verified**. Do not treat those at the same confidence. [R7]

## 8. Open items and recommended additions

Still worth adding to this primer over time:

- clutch-to-element apply charts from open training material,
- valve-body hydraulic paths with annotated circuit names,
- converter and lube circuit diagrams,
- hardware photos with confirmed pin tracing references.

## References

### Repo references

- [R1] [TRANSMISSION_NOTES.md](../TRANSMISSION_NOTES.md)
- [R2] [tmp/egs51/README.md](../tmp/egs51/README.md)
- [R3] [tmp/egs51/reconstructed/egs51_pressure.c](../tmp/egs51/reconstructed/egs51_pressure.c)
- [R7] EGS51 executable-model review notes and coverage table: [tmp/egs51/reconstructed/README.md](../tmp/egs51/reconstructed/README.md)
- [R8] NAG52 pressure manager: [src/pressure_manager.cpp](../src/pressure_manager.cpp), [src/shifting_algo/s_algo.cpp](../src/shifting_algo/s_algo.cpp)

### External references (local copies)

- [E1] ST L9341 datasheet local copy: [docs/references/L9341_ST_CD00000102.pdf](references/L9341_ST_CD00000102.pdf)
- [E2] NXP KTY81 series datasheet local copy: [docs/references/www_nxp_com_docs_en_data_sheet_KTY81_SER_pdf.pdf](references/www_nxp_com_docs_en_data_sheet_KTY81_SER_pdf.pdf)
- [E3] KTY81 table extraction artifact: [docs/references/KTY81_SER_layout.txt](references/KTY81_SER_layout.txt)
- [E4] 5G-Tronic background snapshot: [docs/references/en_wikipedia_org_wiki_5G_Tronic.html](references/en_wikipedia_org_wiki_5G_Tronic.html)
- [E5] Siemens MCU handbook local copy: [docs/references/Siemens_1994_8bit_Microcontroller_Handbook.pdf](references/Siemens_1994_8bit_Microcontroller_Handbook.pdf)

### Manifest

- [docs/references/README.md](references/README.md)
