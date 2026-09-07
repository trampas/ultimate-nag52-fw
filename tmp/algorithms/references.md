# Annotated references

What each source actually gives you, so the next person can decide whether to
fetch it. Grouped by problem.

---

## Shift quality measurement

**SAE 650465 — Measuring Automatic Transmission Shift Performance**
<https://www.sae.org/publications/technical-papers/content/650465/>
The origin of jerk as the shift quality metric. Describes the "GMR Jerkmeter", a
portable instrument for measuring acceleration and jerk during on-road
evaluation, and establishes that jerk — the rate of change of fore-and-aft
acceleration — is what tracks subjective shift feel. Still the primary metric
sixty years later.

**SAE 911938 — Improving Automatic Transmission Shift Quality by Feedback
Control with a Turbine Speed Sensor**
<https://www.sae.org/publications/technical-papers/content/911938/>
Two things worth taking. First, a high quality shift is *low jerk and
spontaneous* — long shift duration reads as sluggish, so jerk alone is not a
score. Second, if the rate of change of clutch slip speed is large at lock-up the
driveline is excited afterwards, which is felt as a thump even when the shift was
otherwise clean. That is where our `lockup_rate` metric comes from.

**US 8346444 — Real time transmission shift quality detection and evaluation
utilizing transmission output shaft acceleration**
<https://image-ppubs.uspto.gov/dirsearch-public/print/downloadPdf/8346444>
The template for doing quality assessment *on the controller* rather than
offline, using output shaft acceleration — which a TCU already has. This is what
`ShiftQuality` in the firmware follows.

**Slip Energy Evaluation for a Conventional Friction Clutch**
<https://trid.trb.org/view/1882705>
Clutch slip energy — the integral of friction torque × slip speed — as the wear
and thermal load measure. Energy can be computed from real-time frictional torque
and slip angle, with slip from the angular speed signals either side of the
clutch.

**Shift Quality Assessment and Optimization for Dual Clutch Transmission**
<https://www.researchgate.net/publication/302211994_Shift_Quality_Assessment_and_Optimization_for_Dual_Clutch_Transmission>
DCT-focused but the metric taxonomy transfers.

---

## Road load, mass and grade estimation

**Vahidi, Stefanopoulou & Peng — Recursive Least Squares with Forgetting for
Online Estimation of Vehicle Mass and Road Grade: Theory and Experiments**
*Vehicle System Dynamics 43:1*
PDF: <https://websites.umich.edu/~annastef/papers_Long_ctrl/JournalPaperMassGrade_Final.pdf>
**The one to read.** Full derivation and experimental validation. Mass estimated
within 5 %, grade tracked well, *provided inputs are persistently exciting*. Full
maths in [road-load-estimation.md](road-load-estimation.md).

Two details that save time:
- They deliberately did **not** use accelerometers — the recorded signals were
  too noisy, and tilt sensors had too little signal-to-noise for grade. A
  model-based estimate from CAN data beat both.
- They discard data where the service brakes were applied, because turning brake
  pressure into force needs a model they did not have.

**SAE 2014-01-0111 — Methods in Vehicle Mass and Road Grade Estimation**
<https://saemobilus.sae.org/articles/methods-vehicle-mass-road-grade-estimation-2014-01-0111>
Free copy: <https://bpb-us-e1.wpmucdn.com/sites.psu.edu/dist/1/118779/files/2020/08/Kidambi_methods_vehicle_mass_road_grade_estimation.pdf>
Compares four methods — RLS with multiple forgetting factors, extended Kalman
filter, dynamic grade observer, and parallel mass-and-grade. Read this to choose
an approach rather than to implement one.

**US 9454508 — Kinematic road gradient estimation** /
**US 10042815 — Road gradient estimation arbitration**
<https://image-ppubs.uspto.gov/dirsearch-public/print/downloadPdf/9454508>
<https://image-ppubs.uspto.gov/dirsearch-public/print/downloadPdf/10042815>
Production approaches, including arbitrating between several grade estimates of
differing trustworthiness. Relevant if a second source (GPS, accelerometer) is
ever added.

---

## Shift schedules and adaptation

**SAE 930674 — Automatic Transmission Shift Schedule Control Using Fuzzy Logic**
<https://saemobilus.sae.org/papers/automatic-transmission-shift-schedule-control-using-fuzzy-logic-930674>
**The anti-hunting reference.** Estimates running resistance, represented as road
gradient, and feeds it into the shift schedule to eliminate hunting. If you only
read one thing about why a TCU should know the grade, read this.

**Miao, Liu & Zhu — Three-parameter transmission gear-shifting schedule for
improved fuel economy** (2018)
<https://doi.org/10.1177/0954407017703234>
Traditional schedules are two-parameter: throttle position and vehicle speed.
This adds a third, a *terrain coefficient*, estimated online by multi-step
recursive least squares. Directly the answer to "can a shift map have more than
one input variable".

**Optimization of Shift Strategy Based on Vehicle Mass and Road Gradient
Estimation** — *World Electric Vehicle Journal* 15(12):545
<https://doi.org/10.3390/wevj15120545>
Notes that a TCU without mass and gradient estimation gives frequent shifting and
insufficient power when fully loaded or climbing — i.e. the exact symptom — and
adjusts the shift rule from the estimates.

**SAE 925223 — A Study on Adaptive Automatic Transmission Control**
<https://www.sae.org/papers/a-study-adaptive-automatic-transmission-control-925223/>
Earlier survey of adaptive AT control.

**US 11261961 / US 11846348 — Method for automated calibration and (online)
adaptation of automatic transmission controllers**
<https://image-ppubs.uspto.gov/dirsearch-public/print/downloadPdf/11261961>
<https://image-ppubs.uspto.gov/dirsearch-public/print/downloadPdf/11846348>
Automated calibration workflow — relevant to the idea of learning shift points
from logged drives rather than hand-tuning.

---

## Driver type / driving style recognition

**The ZF 8HP: Its Shift Strategy** — Gears Magazine
<https://gearsmagazine.com/magazine/the-zf-8hp-its-shift-strategy-no-problems-here-adaptive-strategies-and-how-they-affect-your-diagnostic-process/>
Driver type assessment via fuzzy logic, with an inertia sensor (G-sensor) as the
central input, evaluating engine torque demand and acceleration/deceleration
rates. The line worth remembering: during emergency management program selection,
driver type assessment data is ignored. That is the gating principle — suspend
learning when the objective changes.

**Adapting Sensors in Mercedes Transmissions** — Transmission Digest
<https://www.transmissiondigest.com/adapting-sensors-in-mercedes-transmissions/>
**Reset Transmission Adaptive Shifting** — MB Medic
<https://www.mercedesmedic.com/reset-mercedes-benz-transmission-procedure-instructions/>
Consumer-level but useful for what the *original* EGS on this car did: records
driving style over roughly the last 40 shift points and shifts earlier or later
to match. Sets the expectation the driver already has.

**Adaptive Fuzzy Shift Strategy in Automatic Transmission of Construction
Vehicles**
<https://www.researchgate.net/publication/251826149_Adaptive_Fuzzy_Shift_Strategy_in_Automatic_Transmission_of_Construction_Vehicles>
Fuzzy shift strategy with load adaptation, off-highway context.

---

## Searching notes

Terms that produced useful results: *shift schedule control fuzzy logic*,
*running resistance estimation shift hunting*, *vehicle mass road grade recursive
least squares forgetting*, *shift quality jerk clutch slip energy*, *driver type
assessment adaptive transmission*.

Terms that mostly returned dealer marketing: *Mercedes adaptive shifting*,
*transmission adaptation reset*, *drive mode*.

USPTO full-text PDFs render poorly through text extraction; fetch and read them
as PDFs rather than expecting a summariser to handle them.
