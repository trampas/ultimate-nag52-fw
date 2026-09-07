// Host driver for tmp/road_load_check/check.sh - see that script for why.
// Feeds triples of (output_rpm, input_torque, gear_ratio) through the real
// RoadLoadEstimator::predict_output_accel and prints one result per line.
#include <stdio.h>
#include <stdlib.h>
#include "road_load.h"
#include "nvs/eeprom_config.h"

TCM_CORE_CONFIG VEHICLE_CONFIG;
uint32_t GET_CLOCK_TIME() { return 0; }
void sim_log(const char*, const char*, const char*, ...) {}

int main(int argc, char** argv) {
    // This car: read from the calibration in a real log, never hardcoded in
    // firmware - here only so both sides of the comparison use the same figures.
    VEHICLE_CONFIG.diff_ratio = 3070;
    VEHICLE_CONFIG.wheel_circumference = 1975;
    RoadLoadEstimator::init();
    for (int i = 1; i + 2 < argc; i += 3) {
        SensorData sd = {};
        sd.output_rpm = atoi(argv[i]);
        sd.input_torque = atoi(argv[i + 1]);
        printf("%d\n", RoadLoadEstimator::predict_output_accel(&sd, atof(argv[i + 2])));
    }
    return 0;
}
