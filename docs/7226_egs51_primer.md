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

The corrected pass replaced an earlier bit-order interpretation that briefly mis-attributed one PWM behavior to Y4. The corrected mapping and engagement behavior are captured in the EGS51 notes and reconstructed C artifact. [R2][R3]

## 4. EGS51 P/N and engagement behavior

From corrected EGS51 state-machine reconstruction:

- In N/P idle, EGS51 holds Y5 + Y4 together as the hydraulic-neutral pair.
- On leaving N/P, EGS51 releases both first.
- Drive engagement then proceeds through Y3/Y5 logic with Y4 normally off.
- Reverse engagement energizes Y4 where required.

This is the key OEM behavior to keep separate from "Y4 only" strategies. [R2][R3]

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

EGS51 notes document a linearized internal relation in ROM-space terms:

T ~= ((mean8 * 177) >> 8 - 52) * 2

Interpretation caveats are documented in the same EGS51 section and should be treated as calibration-sensitive until re-verified against direct measured points. [R2]

## 6. Open items and recommended additions

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

### External references (local copies)

- [E1] ST L9341 datasheet local copy: [docs/references/L9341_ST_CD00000102.pdf](references/L9341_ST_CD00000102.pdf)
- [E2] NXP KTY81 series datasheet local copy: [docs/references/www_nxp_com_docs_en_data_sheet_KTY81_SER_pdf.pdf](references/www_nxp_com_docs_en_data_sheet_KTY81_SER_pdf.pdf)
- [E3] KTY81 table extraction artifact: [docs/references/KTY81_SER_layout.txt](references/KTY81_SER_layout.txt)
- [E4] 5G-Tronic background snapshot: [docs/references/en_wikipedia_org_wiki_5G_Tronic.html](references/en_wikipedia_org_wiki_5G_Tronic.html)
- [E5] Siemens MCU handbook local copy: [docs/references/Siemens_1994_8bit_Microcontroller_Handbook.pdf](references/Siemens_1994_8bit_Microcontroller_Handbook.pdf)

### Manifest

- [docs/references/README.md](references/README.md)
