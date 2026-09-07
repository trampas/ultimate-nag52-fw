// Extends the shift_replay stub with the one symbol read_subsystem_settings needs.
#pragma once
#include "../../shift_replay/stubs/esp_err.h"
#ifdef ESP_ERR_NVS_INVALID_LENGTH
#undef ESP_ERR_NVS_INVALID_LENGTH
#endif
const char* esp_err_to_name(esp_err_t e);
