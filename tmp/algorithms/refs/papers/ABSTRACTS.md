# Abstracts and notes for papers that could not be downloaded

## SAE 930674 — Automatic Transmission Shift Schedule Control Using Fuzzy Logic

"The use of automatic transmissions is continually increasing because of their
ease of operation. Transmission performance requirements that have become more
important in recent years include smooth shift quality and a shift schedule
that matches the driver's intentions. An electronically controlled automatic
gearbox, which sets the shift schedule according to the vehicle speed and
throttle valve opening, provides a dramatic improvement in shift quality over
its hydraulically controlled counterpart. However, even with an electronically
controlled automatic transmission, shift hunting occurs when driving uphill or
towing an object. Based on the use of fuzzy logic, a technique has been
developed for estimating running resistance, represented by the road gradient.
This technique has been incorporated in a new shift schedule control method
that eliminates shift hunting. Research is now under way on a fuzzy logic
technique for inferring the driver's intention to accelerate."

## Ngo, Hofman, Steinbuch, Serrarens — Optimal gear shift strategies for fuel economy and driveability (IMechE Part D, 2013)

Fuel-optimal gear shift by dynamic programming, with driveability introduced
three ways: (1) weighted inverse of power reserve in the cost, (2) constant
power reserve constraint, (3) variable power reserve. Variable power reserve
gives the best economy without losing driveability. A stochastic DP variant
derives one schedule over many cycles. Up to ~15 % fuel improvement vs a
prescribed schedule is reported in the DP literature it belongs to.

Power reserve = available engine power in the candidate gear at the current
speed minus the power needed to hold the road load. The schedule is the locus
of speeds where the next gear still leaves the required reserve.

## The Horsepower Reserve Formulation of Driveability (CVT)

Defines driveability as a horsepower margin above road load; derives a desired
engine speed from a target reserve (figures show a 20 hp reserve case). The
same formulation gives a stepped-transmission shift line directly.

## SAE 2017-01-1108 — Optimal gearshift strategy based on vehicle power demand

"Selection of gearshift point plays an important role in the field of automatic
transmission technology, which directly affects the vehicle dynamic and
economic performance." DP over NEDC, FTP75 and full-throttle acceleration;
"the proposed optimal gearshift strategy can achieve the optimal tradeoff
between the fuel economy and the drivability, which is adaptive to the vehicle
dynamic characteristics."

## Miao, Liu, Zhu — Three-parameter transmission gear-shifting schedule (2018)

Adds a terrain coefficient to throttle and speed, estimated online by
multi-step recursive least squares; corrects the two-parameter economy schedule
for vehicle load and road slope.

## WEVJ 15(12):545 — Shift strategy based on mass and road gradient estimation

A TCU without mass and gradient estimation shifts frequently and lacks power
when loaded or climbing; the paper estimates both and adjusts the shift rule
from the estimates.

## Machines 11(9):915 — DP + fuzzy adaptive shift schedule (multi-gear AMT EV)

DP produces the base schedule; fuzzy logic adapts it in real time to load and
driver, improving adaptability of the schedule.

## Appl. Sci. 11(12):5555 — Heavy-truck shift strategy by DP

DP solves the globally optimal shift sequence on a simplified powertrain model
and extracts a schedule; up to 15.4 % fuel improvement vs a prescribed map.

## Actuators 15(6):293 — Hierarchical adaptive shift strategy (two-speed EV)

Hysteresis width set per mode: large in comfort (rare shifts), small in sport;
negative acceleration widens the downshift hysteresis to avoid short-lived
downshifts near a boundary.

## IJAT 2017 — Adaptive control of the shifting process

Torque phase: keep clutch slip in a small band to avoid tie-up and flare.
Inertia phase: keep synchronisation time in a band to avoid long shifts or
shock. Adaptive pressure from linearly extrapolated ratio-change time and
initial rate of pressure change, stored in keep-alive memory.

## Control Eng. Practice 2018 — Robust control and estimation of clutch-to-clutch shifts

Closed-loop on-coming clutch slip tracking a calculated slip profile during the
inertia phase; observers for unmeasured clutch torque.

## Array 2022 — Deep reinforcement learning for gearshift controllers

DRL agent trained in simulation against a powertrain plant model; reward
combines jerk, shift time and slip energy. Requires a plant model and training
in simulation; surveyed and not adopted for the ESP32.

## SAE 650465, 911938, 925223

Paywalled and the SAE site returns only a header to non-browser clients. Notes
from prior reading are in ../../references.md.
