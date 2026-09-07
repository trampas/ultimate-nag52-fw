#ifndef EEPROM_CONFIG_STUB_H
#define EEPROM_CONFIG_STUB_H
#define EEPROM_CONFIG_H
#include <stdint.h>
#include <stddef.h>
#include "esp_err.h"
struct __attribute__ ((packed)) TCM_CORE_CONFIG{
    uint8_t deprecated_is_large_nag;
    uint16_t diff_ratio;
    uint16_t wheel_circumference;
    uint8_t is_four_matic;
    uint16_t transfer_case_high_ratio;
    uint16_t transfer_case_low_ratio;
    uint8_t default_profile;
    uint16_t red_line_rpm_diesel;
    uint16_t red_line_rpm_petrol;
    uint8_t engine_type;
    uint8_t egs_can_type;
    uint8_t shifter_style;
    uint8_t io_0_usage;
    uint8_t input_sensor_pulses_per_rev;
    uint8_t output_pulse_width_per_kmh;
    uint8_t gen_mosfet_purpose;
    uint8_t throttlevalve_maxopeningangle;
    uint16_t c_eng;
    uint16_t engine_drag_torque;
    bool jeep_chrysler;
};
extern TCM_CORE_CONFIG VEHICLE_CONFIG;
namespace EEPROM {
    esp_err_t read_nvs_map_data(const char* map_name, int16_t* dest, const int16_t* default_map, size_t map_element_count);
    esp_err_t write_nvs_map_data(const char* map_name, const int16_t* to_write, size_t map_element_count);
}
#endif
