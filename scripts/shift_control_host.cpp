// Regression cases exercise the same pure functions called by the firmware.
#include "shifting_algo/control_limits.h"
#include "models/shift_demand.h"
#include "canbus/egs51_torque.h"
#include <cassert>
#include <limits>
int main() {
    float integral = 0;
    for (int i = 0; i < 200; ++i) {
        assert(ShiftControl::pid(-500, -500, integral, 1, .1, 0, 1, -100, 100) == -100);
    }
    assert(integral == 0); // Cannot bank 200 cycles of unreachable negative torque.
    assert(ShiftControl::pid(10, -500, integral, 1, .1, 0, 1, -100, 100) > 0);
    float a = 0, b = 0;
    for (int i = 0; i < 20; ++i) ShiftControl::pid(10, 10, a, 0, .1, 0, 1, -1000, 1000);
    for (int i = 0; i < 40; ++i) ShiftControl::pid(10, 10, b, 0, .1, 0, .5, -1000, 1000);
    assert(a == b); // Equal elapsed time at different loop cadences.
    assert(ShiftControl::turbine_target(2800, 2100, 2000, 20, true) == 2100);
    assert(ShiftControl::turbine_target(2005, 2010, 2000, 20, true) == 2000);
    assert(ShiftControl::turbine_target(2995, 2990, 3000, 20, false) == 3000);
    float off = 200;
    for (int i = 0; i < 100; ++i) {
        float next = ShiftControl::releasing_torque(off, i < 5 ? 200 : 400, 20, 100, 500, 20);
        assert(next <= off && next >= 20);
        off = next;
    }
    assert(off == 20); // Tip-in cannot indefinitely re-clamp the off clutch.
    assert(ShiftDemand::kickdown(true, true, 200, true));
    assert(ShiftDemand::kickdown(true, true, 200, true)); // Held through another decision.
    assert(!ShiftDemand::kickdown(false, true, 200, true));
    assert(!ShiftDemand::kickdown(true, false, 200, true));
    assert(!ShiftDemand::kickdown(true, true, 0, true));
    assert(!ShiftDemand::kickdown(true, true, 200, false));
    assert(!ShiftDemand::useful_downshift(4093, 0, 4500, 4200));
    assert(!ShiftDemand::useful_downshift(3500, 0, 4500, 3600));
    assert(ShiftDemand::useful_downshift(3200, 100, 4500, 4000));
    assert(ShiftDemand::projected_rpm(1000, -100, 2, 1000) == 2000);
    assert(ShiftDemand::projected_rpm(1000, 100, 2, 1000) == 2200);
    ShiftDemand::LiftHold lift;
    for (int i = 0; i <= 10; ++i) lift.update(1000 + 20*i, 200 - 10*i, true, true);
    assert(lift.active(1250)); // Multi-sample quick lift, not just one giant pedal step.
    lift.update(1300, 180, true, true);
    assert(!lift.active(1300));
    lift.update(1320, 0, true, true);
    assert(lift.active(1320));
    lift.update(2320, 0, true, true);
    assert(!lift.active(2320));
    lift.update(2340, 200, true, true);
    lift.update(2360, 0, true, true);
    lift.update(2380, 0, false, true);
    assert(!lift.active(2380));
    assert(Egs51Torque::encode(120, 54, false) == 40);
    assert(Egs51Torque::encode(120, 54, true) == 58);
    assert(Egs51Torque::encode(-1000, 54, true) == 0);
    assert(Egs51Torque::encode(10000, 54, true) == 0xFD);
    assert(Egs51Torque::encode(120, INT16_MAX, true) == 0xFE);
    assert(Egs51Torque::encode(std::numeric_limits<float>::quiet_NaN(), 54, false) == 0xFE);
}
