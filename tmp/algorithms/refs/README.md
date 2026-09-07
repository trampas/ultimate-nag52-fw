# Saved references

Local copies of the sources behind [../recommendation.md](../recommendation.md)
and [../references.md](../references.md), fetched 2026-09-07.

**The markdown here is tracked; the fetched documents are not.** They are 30 MB
of binaries, and the trade-press articles are copyrighted text a public repo
should not redistribute. Run `./fetch.sh` to get them back - it skips anything
already present. The summaries and abstracts below stand on their own without
them.

```
refs/
  patents/    USPTO full-text PDFs (all fetched) + SUMMARIES.md
  papers/     open-access PDFs that could be fetched + ABSTRACTS.md for the rest
  articles/   trade press and forum pages, .html plus a .txt extraction
```

## Patents (all in `patents/`, PDF from image-ppubs.uspto.gov)

| file | title | why it is here |
|---|---|---|
| US6098004 | Preventing gear hunting in an automatic transmission (GM) | required-acceleration upshift gate |
| US5669850 | Shift hunting prevention (Ford) | next-gear torque capability check, 10° / 3200-4000 rpm gates |
| US6571162 | Controller for automatic transmission | cornering from L/R wheel speed difference, S1/S2 thresholds |
| US4788892 | Controller for automatic transmission | early cornering + throttle downshift inhibit |
| US6456923 | Method for detecting cornering | bend radius from front wheel speeds |
| US6527672 | Gearbox control on spontaneous accelerator release (Bosch) | FastOff hold, grade-dependent timers, traction-line release |
| US8133154 | Accelerator-pedal-based shift point stabilisation (Ford) | pedal-rate thresholds vs time since last shift |
| US9676388 | Grade logic braking | grade + brake + accelerating ⇒ downshift; 3 s release |
| US5685799 | Shift stabilisation control | delay/lockout logic |
| US8568271 | Prevent shift hunting in a powertrain | kickdown delay on speed loss |
| US7374513 | Adaptive control of closed-throttle downshifts (GM) | turbine timing ⇒ fill/pressure adaptation, 50 rpm windows |
| US6915890 | Learning oncoming clutch fill level and volume | counter-gated adaptive gain, matrices by pressure/temp |
| US7762925 | Engine power reduction during shifting | torque reduction shaping across torque/inertia phase |
| US8032288 | Upshift control system | begin reduction before inertia phase, ramp it |
| US7505842 | Configuring a transmission control (Porsche) | DSP programs: fast-off, uphill, downhill |
| US5188005 | Improving smoothness of shifts | adaptive pressure from ratio-change time |
| US6278926 | Adaptive electronic transmission control | learned powertrain variables in keep-alive memory |
| US6374170 | Cross-adaptive control for an automatic shift transmission | adaptation shared across shifts |
| US8346444 | Real-time shift quality from output shaft acceleration | template for `ShiftQuality` |
| US9454508 | Kinematic road gradient estimation (Ford) | grade estimate |
| US10042815 | Road gradient estimation arbitration (Ford) | arbitration between grade sources |
| US11261961 | Automated calibration of AT controllers | learning from logged drives |
| US11846348 | Online adaptation of AT controllers | same family |

Short technical summaries of the ones read in detail: [patents/SUMMARIES.md](patents/SUMMARIES.md).

## Papers (`papers/`)

Fetched as PDF:

| file | reference |
|---|---|
| vahidi-rls-mass-grade.pdf | Vahidi, Stefanopoulou, Peng — RLS with forgetting for online mass and grade, VSD 43:1 (28 pp) |
| kidambi-methods-mass-grade-sae-2014-01-0111.pdf | Kidambi et al. — Methods in vehicle mass and road grade estimation, SAE 2014-01-0111 |
| nature-srep-shifting-process-control-2022.pdf | Research on shifting process control of automatic transmission, Sci. Rep. 2022 |

Not fetchable by script (MDPI, ScienceDirect, SAGE, Springer, SAE and
ResearchGate all return 403 to non-browser clients). Abstracts and notes in
[papers/ABSTRACTS.md](papers/ABSTRACTS.md); open the DOI in a browser and
save the PDF next to it if you want the full text:

- Ngo, Hofman, Steinbuch, Serrarens — Optimal gear shift strategies for fuel economy and driveability, IMechE Part D 2013. <https://www.researchgate.net/publication/259786183>
- The Horsepower Reserve Formulation of Driveability (CVT). <https://www.researchgate.net/publication/228800886>
- SAE 2017-01-1108 — Optimal gearshift strategy based on vehicle power demand. <https://saemobilus.sae.org/content/2017-01-1108>
- Miao, Liu, Zhu — Three-parameter shift schedule with terrain coefficient. <https://doi.org/10.1177/0954407017703234>
- Optimization of Shift Strategy Based on Vehicle Mass and Road Gradient Estimation, WEVJ 15(12):545. <https://doi.org/10.3390/wevj15120545>
- Adaptive shift schedule design: DP + fuzzy, Machines 11(9):915. <https://doi.org/10.3390/machines11090915>
- Shift strategy optimisation for heavy trucks by DP, Appl. Sci. 11(12):5555. <https://www.mdpi.com/2076-3417/11/12/5555>
- Hierarchical adaptive gear shift strategy, Actuators 15(6):293. <https://doi.org/10.3390/act15060293>
- Adaptive control of the shifting process in automatic transmissions, IJAT 2017. <https://doi.org/10.1007/s12239-017-0018-4>
- Robust control and estimation of clutch-to-clutch shifts, Control Eng. Practice 2018. <https://doi.org/10.1016/j.conengprac.2017.06.001>
- Inertia Phase Control of the Clutch-to-Clutch Shift Process (Springer chapter). <https://doi.org/10.1007/978-3-642-41572-2_4>
- Deep reinforcement learning for gearshift controllers, Array 2022. <https://doi.org/10.1016/j.array.2022.100211>
- SAE 650465, 911938, 930674, 925223 — paywalled; abstracts in ABSTRACTS.md where obtainable.

## Articles (`articles/`)

| file | source |
|---|---|
| gears-zf-8hp-shift-strategy | Gears Magazine — ZF 8HP shift strategy, driver type assessment, program selection |
| gears-shifty-business | Gears Magazine — adaptive strategies overview |
| gears-shift-busyness | Gears Magazine — a shift busyness case (brake pedal sensor) |
| transmissiondigest-722-6-shift-strategy | Transmission Digest — the 722.6 shift strategy (original EGS behaviour) |
| transmissiondigest-adapting-sensors-mercedes | Transmission Digest — Mercedes adaptation |
| mbmedic-reset-adaptive-shifting | MB Medic — adaptation reset, ~40 shift memory |
| mkultra-722-6-adaption-procedure | Mk-Ultra — 722.6 adaption procedure |
| wikipedia-adaptive-transmission-control | overview, named production systems |
| rennlist-tiptronic-shift-speed | Porsche Tiptronic DSP SK1-SK5 programs, fast-off |
