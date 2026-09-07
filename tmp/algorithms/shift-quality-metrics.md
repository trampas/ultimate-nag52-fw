# Measuring shift quality

Implemented in `src/shift_trace.h` (`ShiftQuality`, computed on the TCU) and
`scripts/shift_quality.py` (offline reference; the two are meant to agree and the
script prints both when a log has them).

---

## There is no single number

Quality is a **vector**, and what counts as good is **mode dependent**. Comfort
wants low jerk and will pay for it in duration; Agility wants spontaneity and
accepts jerk to get it. Collapsing to one score hides exactly the trade being
made.

Our own drive shows why — the two modes fail on entirely different metrics:

| metric | measured | comfort target | agility target |
|---|---|---|---|
| response_ms | 500 | ≤700 ok | ≤350 **1.4× over** |
| duration_ms | 1041 | ≤1400 ok | ≤800 **1.3× over** |
| peak_jerk | 39.3 | ≤12 **3× over** | ≤30 1.3× over |
| torque_hole | 66 | ≤60 marginal | ≤120 ok |
| settle_osc | 0 | ok | ok |
| slip_energy_J | 5824 | ok | ok |

Comfort fails on jerk and nothing else. Agility fails on responsiveness and its
jerk is nearly acceptable. They need opposite fixes.

---

## The metrics

### peak_jerk — m/s³

Rate of change of fore-and-aft acceleration. **The** metric: SAE 650465
established with the GMR Jerkmeter that it is what correlates with subjective
shift feel, and it still is.

Comfortable shifts are generally quoted **under about 10 m/s³**, objectionable
above roughly 20–30. Ours measured 39.

Derived from output shaft speed here, because the TCU has no accelerometer. ZF
uses a real G-sensor. The difference matters: output-shaft-derived jerk misses
driveline compliance and body motion an occupant actually feels, so treat it as a
consistent relative measure rather than an absolute one.

> **Sampling rate is not optional.** Jerk is a second derivative and a shift's
> inertia phase is 100–200 ms. Measured both ways over 51 shifts, ~19 Hz polled
> data gave a median of 19.8 m/s³ against 39.3 from a 50 Hz trace — **it
> understates by 2×**. Below roughly 50 Hz you are aliasing, not measuring.

### duration_ms and response_ms

A shift can always be made smooth by making it long, so jerk alone is not a
score — SAE 911938 defines quality as low jerk *and* spontaneous response.

`response_ms` is request until the ratio actually starts to move, and it is the
one most easily missed: a shift can finish quickly having sat still for most of
its length. Ours was a **500 ms median before anything happens**, which is the
dominant Agility complaint and is invisible in duration alone.

### slip_energy — joules

`∫ T_clutch · ω_slip dt` over the applying clutch. The wear and thermal load
metric — the energy the friction material absorbs and the oil carries away.

> **Gate it on engagement.** Integrating across the whole shift counts bleed and
> fill, where slip is largest but the plates are not touching. That inflated a
> gentle 3→4 to 30 kJ. Gate on applying-clutch pressure exceeding its return
> spring (1139–1289 mBar on this box; we use 1300).

Clutch torque is rarely logged. Estimating it from input shaft dynamics works:
`T ≈ |I·dω/dt| + T_input`, with `I` fitted from logged inertia phases (0.16 kg·m²
here, R² 0.84–0.96 per shift type on upshifts). Good relatively, rough absolutely
— and it inherits any ECM torque bias.

### lockup_rate — rpm/s

How fast the applying clutch slip collapses at engagement. SAE 911938: a large
rate of change of slip at lock-up excites the driveline afterwards, felt as a
thump even when the shift was otherwise clean.

### torque_hole — rpm/s of output shaft

How far output acceleration falls below its pre-shift value. The sag, felt
separately from the jerk spike.

### settle_osc

Acceleration reversals about the pre-shift level in the ~0.6 s after the shift. A
clean engagement settles; a hard one rings. Ours measured 0, which located the
harshness *in* the shift rather than at lock-up.

---

## Doing it on the controller

US 8346444 does real-time shift quality detection from **transmission output
shaft acceleration** — which a TCU already has. That is the template for
`ShiftQuality`: accumulate one sample at a time inside an existing periodic hook,
O(1), no allocation, nothing added to the shift control path.

Two reasons to have it on the TCU rather than only offline:

1. A shift can be judged from the car instead of only from a log afterwards.
2. **Adaptation needs a reward signal.** Without a quality score, a learner has
   no way to tell a good shift from a bad one and can only learn from rare
   explicit failures.

Duplicating the metric between firmware and an offline script invites drift.
Guard it: `static_assert` the struct sizes, carry a size field on the wire, and
have the offline tool print both sets of numbers side by side.

---

## Suggested targets

Provisional. Only the jerk figures have outside support; the rest are starting
points, deliberately kept in one dict (`TARGETS` in `scripts/shift_quality.py`)
so they can be corrected against drives rather than being spread through the
analysis.

```
comfort   jerk ≤12 m/s³   hole ≤60   response ≤700 ms   duration ≤1400 ms
agility   jerk ≤30 m/s³   hole ≤120  response ≤350 ms   duration ≤800 ms
```
