#ifndef PROFILES_STUB_H
#define PROFILES_STUB_H
#define PROFILES_H
#include <stdint.h>
#include "common_structs.h"
#include "stored_map.h"
#include "maps.h"
#include "nvs/all_keys.h"
#include "nvs/eeprom_config.h"
enum class GearboxProfile : uint8_t { Standard = 0u, Comfort = 1u, Winter = 2u, Agility = 3u, Manual = 4u, Race = 5u, Individual = 6u, Underscore = 7u, Failure = 8u };
class AbstractProfile {
public:
    AbstractProfile(uint8_t id, const int16_t* up_time, const int16_t* dn_time) : id(id) {
        const int16_t x[6] = {0, 20, 40, 60, 80, 100};
        int16_t redline = VEHICLE_CONFIG.red_line_rpm_diesel;
        int16_t step = (redline - 1000) / 4;
        int16_t y[5] = {1000, (int16_t)(1000 + step), (int16_t)(1000 + step * 2), (int16_t)(1000 + step * 3), redline};
        if (up_time) {
            upshift_time_map = new StoredMap(NVS_KEY_MAP_NAME_S_UPSHIFT_TIME, SHIFT_TIME_MAP_SIZE, x, y, 6, 5, up_time);
            downshift_time_map = new StoredMap(NVS_KEY_MAP_NAME_S_DOWNSHIFT_TIME, SHIFT_TIME_MAP_SIZE, x, y, 6, 5, dn_time);
        }
    }
    uint8_t get_profile_id() { return id; }
    uint16_t get_upshift_time(uint16_t input_rpm, float pedal_percent) {
        return upshift_time_map ? (uint16_t)upshift_time_map->get_value(pedal_percent, (float)input_rpm) : 500;
    }
    uint16_t get_downshift_time(uint16_t input_rpm, float pedal_percent) {
        return downshift_time_map ? (uint16_t)downshift_time_map->get_value(pedal_percent, (float)input_rpm) : 500;
    }
    ShiftCharacteristics get_shift_characteristics(GearChange requested, SensorData* sensors) {
        ShiftCharacteristics r;
        switch (requested) {
            case GearChange::_1_2: case GearChange::_2_3: case GearChange::_3_4: case GearChange::_4_5:
                r.target_shift_time = get_upshift_time(sensors->input_rpm, ((float)sensors->pedal_pos * 100.0) / 250.0); break;
            case GearChange::_5_4: case GearChange::_4_3: case GearChange::_3_2: case GearChange::_2_1:
                r.target_shift_time = get_downshift_time(sensors->input_rpm, ((float)sensors->pedal_pos * 100.0) / 250.0); break;
            default: r.target_shift_time = 500; break;
        }
        return r;
    }
    uint8_t id;
    StoredMap* upshift_time_map = nullptr;
    StoredMap* downshift_time_map = nullptr;
};
extern AbstractProfile* standard;
extern AbstractProfile* manual;
extern AbstractProfile* race;
#endif
