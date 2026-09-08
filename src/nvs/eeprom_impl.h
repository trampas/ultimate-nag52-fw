/** @file */
#ifndef EEPROM_IMPL_H
#define EEPROM_IMPL_H

#include "eeprom_config.h"

namespace EEPROM {
    template <typename T>
    esp_err_t write_subsystem_settings(const char* key_name, const T* write) {
        sol_tcc->isr_disable();
        vTaskDelay(5);
        esp_err_t e = nvs_set_blob(MAP_NVS_HANDLE, key_name, write, sizeof(T));
        if (e != ESP_OK) {
            ESP_LOG_LEVEL(ESP_LOG_ERROR, "EEPROM", "Error writing subsystem settings for %s (%s)", key_name, esp_err_to_name(e));
        } else {
            e = nvs_commit(MAP_NVS_HANDLE);
            if (e != ESP_OK) {
                ESP_LOG_LEVEL(ESP_LOG_ERROR, "EEPROM", "Error calling nvs_commit: %s", esp_err_to_name(e));
            }
        }
        sol_tcc->isr_enable();
        return e;
    }

    /**
     * @brief Load one settings block, defaults first and the stored blob over the top.
     *
     * The order is the point. Filling the struct with its defaults before the read
     * means any field the stored blob does not reach keeps its default, so a block
     * written by an older firmware loads its old values and every setting appended
     * since simply comes up at the new default.
     *
     * That is what makes appending a setting safe across a firmware upgrade without
     * bumping the NVS key. Bumping the key also works, but it discards everything
     * the user had set in that block, so it should be reserved for what it is
     * actually for: forcing a changed DEFAULT onto a TCU that has already stored the
     * old one. (The same trick on shift maps is a different code path entirely -
     * read_nvs_map_data - and the note in TRANSMISSION_NOTES.md section 5 still
     * stands for those.)
     *
     * The corollary is that settings may only ever be APPENDED. Reordering or
     * removing a field changes the meaning of bytes that are already in flash, and
     * nothing here can detect that - the sizes still agree. A size change is
     * reported so an upgrade is at least visible in the boot log.
     */
    template <typename T>
    esp_err_t read_subsystem_settings(const char* key_name, T* dest, const T* default_settings) {
        if (nullptr == dest || nullptr == default_settings) {
            return ESP_ERR_INVALID_ARG;
        }
        memcpy(dest, default_settings, sizeof(T));
        if (nullptr == key_name) {
            return ESP_ERR_INVALID_ARG;
        }
        size_t size = sizeof(T);
        esp_err_t e = nvs_get_blob(MAP_NVS_HANDLE, key_name, dest, &size);
        if (ESP_ERR_NVS_NOT_FOUND == e) {
            ESP_LOG_LEVEL(ESP_LOG_WARN, "EEPROM", "subsystem %s not found in NVS. Seeding it with the defaults from prog flash", key_name);
            return write_subsystem_settings(key_name, default_settings);
        }
        if (ESP_OK != e) {
            // Includes the stored blob being LARGER than this struct, which is an
            // older firmware reading settings a newer one wrote. Defaults are
            // already in place, and the stored blob is deliberately left alone so
            // that flashing the newer firmware back does not find it truncated.
            ESP_LOG_LEVEL(ESP_LOG_WARN, "EEPROM", "subsystem %s could not be read (%s). Running on defaults, stored data left untouched", key_name, esp_err_to_name(e));
            return ESP_OK;
        }
        if (size != sizeof(T)) {
            ESP_LOG_LEVEL(ESP_LOG_WARN, "EEPROM", "subsystem %s was stored by an older build (%u bytes, now %u). Kept the stored values; the %u appended byte(s) took their defaults", key_name, (unsigned int)size, (unsigned int)sizeof(T), (unsigned int)(sizeof(T) - size));
        } else {
            ESP_LOG_LEVEL(ESP_LOG_INFO, "EEPROM", "subsystem %s loaded OK from NVS!", key_name);
        }
        return ESP_OK;
    }


}
#endif