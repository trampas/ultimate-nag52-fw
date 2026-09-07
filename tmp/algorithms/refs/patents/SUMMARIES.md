# Patent summaries

Read from the full text on 2026-09-07. Numbers are the patents' own examples,
not calibrations for this car.

## US 6571162 — cornering detection, upshift inhibit

- Signal: difference between right and left wheel rotational speeds.
- Difference > S1 ⇒ "started around a corner", inhibit upshift.
  Difference < S2 ⇒ corner complete, release.
- S1/S2 depend on the selected shift map: economy higher (inhibits later),
  sport lower (inhibits earlier), uphill map uses the sport values.
- No timers or throttle conditions in the base method.

## US 6098004 — preventing gear hunting (GM)

- Computes a required "upshift vehicle acceleration", indexed by vehicle speed
  and by the gap between current speed and the scheduled upshift speed. The
  closer to the upshift point, the more acceleration is required.
- Actual acceleration below required ⇒ upshift flag cleared; above ⇒ allowed.
- Example: 1.1 mph/s required, 0.5 mph/s achieved ⇒ no upshift.
- Released as throttle drops (lower requirement) or acceleration rises.

## US 5669850 — shift hunting prevention (Ford)

- Threshold = (output torque in current gear − expected torque in next gear) /
  reflected vehicle inertia + desired acceleration level.
- Upshift blocked ("grade hunting flag") when observed acceleration < threshold.
- 2-3: throttle > 10°, output speed < 3200 rpm; 3-4: throttle > 10°,
  output speed < 4000 rpm. Sequential shifts only.

## US 6527672 — FastOff (Bosch)

- FastOff when pedal gradient falls below a threshold from a map of pedal
  position × driver-type counter.
- Sets upshift-prevention flag; hold durations THSV1/THSV2 depend on road
  gradient, THSV3 for repeated negative gradients.
- Released on clear traction (pedal above a traction/thrust line vs engine
  speed and gradient), on timeout, or when output speed < KW_NABMIN.

## US 8133154 — pedal-based shift point stabilisation (Ford)

- Pedal rate through a first-order lag; compared against thresholds that vary
  with time since last shift: −86 %/s at t = 0 to −4 %/s at t = 6 s.
- When armed, the schedule is looked up with a modified pedal value, giving
  hysteresis during gradual pedal transitions. Minimum 0.150 s inhibit timer.

## US 9676388 — grade logic braking

- Grade from an inclinometer (the RLS estimate substitutes here).
- Downshift when grade > threshold (2/4/6 % examples) AND brake applied AND
  vehicle still accelerating, regardless of engine rpm.
- Upshift when brakes off for ~3 s, or acceleration < 0.1 g, or grade below
  threshold.

## US 7374513 — adaptive closed-throttle downshifts (GM)

- Ratio change start: turbine departs attained-gear speed by 50 rpm. Inertia
  phase: 50 rpm above attained until 50 rpm below commanded.
- Off-going pressure: up on early slip / underlap, down after N clean shifts.
- On-coming pressure: up for slip-late, underlap, past-sync, turbine float;
  short shift ⇒ down, long shift ⇒ up. Correction = full · scalar · gain.
- On-coming volume: down for early ratio change / long full-feed; up for
  slip-late / underlap.
- Only at closed throttle; no correction on long fill delay; gain resets to
  minimum when adaptation direction reverses.

## US 6915890 — oncoming clutch fill learning

- Detects regulator valve regulating → full-feed → regulating transitions in a
  validation window; volume = flow rate × accumulated time.
- Correction = full correction × adaptive gain (from error counters) × factor
  (by recorded reason), weighted by line pressure and temperature, clamped by
  max/min change.
- Gated on valid fill achieved and engine torque in range. Stored as 3×3
  adaptive matrices, each cell a 5×5 calibration by pressure and temperature.

## US 7762925 / US 8032288 — torque reduction shaping

- Torque phase: gradual reduction by spark and/or throttle; inertia phase:
  spark retard to offset inertia torque.
- Begin the reduction before the expected start of the inertia phase and ramp
  it up; torque and inertia phases each ~0.15-0.5 s.

## US 8346444 — shift quality from output shaft acceleration

- Real-time evaluation on the controller from output shaft acceleration;
  template for the on-TCU `ShiftQuality` vector.
