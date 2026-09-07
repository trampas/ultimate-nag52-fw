#ifndef SOLENOID_STUB_H
#define SOLENOID_STUB_H
#define SOLENOID_H
#include <stdint.h>
#include "esp_err.h"
class OnOffSolenoid {
public:
    bool is_on = false;
    void on() { is_on = true; }
    void off() { is_on = false; }
    uint16_t get_pwm_raw() { return is_on ? 4096 : 0; }
};
class ConstantCurrentSolenoid {
public:
    uint16_t target = 0;
    void set_current_target(uint16_t t) { target = t; }
};
class InrushControlSolenoid {
public:
    uint16_t duty = 0;
    void set_duty(uint16_t d) { duty = d; }
};
namespace Solenoids { uint16_t get_solenoid_voltage(void); }
extern OnOffSolenoid *sol_y3;
extern OnOffSolenoid *sol_y4;
extern OnOffSolenoid *sol_y5;
extern ConstantCurrentSolenoid *sol_mpc;
extern ConstantCurrentSolenoid *sol_spc;
extern InrushControlSolenoid *sol_tcc;
#endif
