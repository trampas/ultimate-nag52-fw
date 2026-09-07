// Pre-included into every translation unit: shadows firmware headers that are included by relative path
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#define ABSTRACT_CAN_H
#define __TCU_IO_H
#define SHIFTER_H
#include "esp_err.h"
#include "esp_log.h"
#include "solenoids/solenoids.h"
#include "canbus/can_defines.h"
#include "nvs/eeprom_config.h"
#include "nvs/all_keys.h"
#include "torque_converter.h"
enum class ShifterPosition : uint8_t { P = 0, P_R = 1, R = 2, R_N = 3, N = 4, N_D = 5, D = 6, PLUS = 7, MINUS = 8, FOUR = 9, THREE = 10, TWO = 11, ONE = 12, SignalNotAvailable = 0xFF };
#include "common_structs.h"
#include "profiles.h"
