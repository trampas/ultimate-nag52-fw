// Fake NVS for tmp/settings_migration_check - see check.sh.
// Just enough of the API for read_subsystem_settings, plus hooks so a test can
// say "flash holds THIS many bytes" and watch what the real loader does with it.
#pragma once
#include <stddef.h>
#include <stdint.h>
#include "esp_err.h"

typedef uint32_t nvs_handle_t;

#ifndef ESP_ERR_NVS_BASE
#define ESP_ERR_NVS_BASE 0x1100
#endif
#define ESP_ERR_NVS_NOT_FOUND       (ESP_ERR_NVS_BASE + 0x02)
#define ESP_ERR_NVS_INVALID_LENGTH  (ESP_ERR_NVS_BASE + 0x0c)

// What "flash" currently holds. fake_nvs_len < 0 means the key is absent.
extern const unsigned char* fake_nvs_blob;
extern int fake_nvs_len;
// Set by nvs_set_blob so a test can see whether the loader wrote anything back.
extern int fake_nvs_last_write_len;

esp_err_t nvs_get_blob(nvs_handle_t handle, const char* key, void* out_value, size_t* length);
esp_err_t nvs_set_blob(nvs_handle_t handle, const char* key, const void* value, size_t length);
esp_err_t nvs_commit(nvs_handle_t handle);
