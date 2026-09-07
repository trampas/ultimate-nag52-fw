// Does a settings block written by an older firmware still load correctly?
//
// Appending a setting has to be safe across an upgrade, or every field added
// costs the user everything they had tuned in that block. read_subsystem_settings
// fills the struct with its defaults and lets the stored blob overwrite only what
// it reaches, so anything appended since keeps its default. This exercises the
// real template against a fake flash, because "it should work" is not a test.
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "nvs/eeprom_impl.h"

const unsigned char* fake_nvs_blob = nullptr;
int fake_nvs_len = -1;
int fake_nvs_last_write_len = -1;
nvs_handle_t MAP_NVS_HANDLE = 0;
TCM_CORE_CONFIG VEHICLE_CONFIG;

int SIM_LOG_VERBOSE = 1;
void sim_log(const char* lvl, const char* tag, const char* fmt, ...) {
    va_list ap; va_start(ap, fmt);
    printf("      [%s] ", tag); vprintf(fmt, ap); printf("\n"); va_end(ap);
}
const char* esp_err_to_name(esp_err_t e) { return "ERR"; }

esp_err_t nvs_get_blob(nvs_handle_t, const char*, void* out_value, size_t* length) {
    if (fake_nvs_len < 0) { return ESP_ERR_NVS_NOT_FOUND; }
    if ((size_t)fake_nvs_len > *length) { return ESP_ERR_NVS_INVALID_LENGTH; }
    memcpy(out_value, fake_nvs_blob, (size_t)fake_nvs_len);
    *length = (size_t)fake_nvs_len;
    return ESP_OK;
}
esp_err_t nvs_set_blob(nvs_handle_t, const char*, const void*, size_t length) {
    fake_nvs_last_write_len = (int)length; return ESP_OK;
}
esp_err_t nvs_commit(nvs_handle_t) { return ESP_OK; }

// An old two-field block, and the same block after two fields were appended.
struct __attribute__((packed)) Old { uint8_t a; uint8_t b; };
struct __attribute__((packed)) New { uint8_t a; uint8_t b; uint8_t c; int16_t d; };
static const New NEW_DEFAULTS = { .a = 1, .b = 2, .c = 78, .d = 20 };

static int fails = 0;
static void check(const char* what, bool ok) {
    printf("  %-58s %s\n", what, ok ? "ok" : "FAIL");
    if (!ok) { fails++; }
}

int main() {
    New s;

    printf("\nan upgrade: flash holds the old 2-byte block, firmware wants 5\n");
    Old stored = { .a = 40, .b = 50 };
    fake_nvs_blob = (const unsigned char*)&stored; fake_nvs_len = sizeof(Old);
    fake_nvs_last_write_len = -1;
    EEPROM::read_subsystem_settings<New>("KEY", &s, &NEW_DEFAULTS);
    check("the user's tuned values survive", s.a == 40 && s.b == 50);
    check("appended fields take their defaults", s.c == 78 && s.d == 20);
    check("nothing is written back over the stored block", fake_nvs_last_write_len == -1);

    printf("\nsteady state: flash matches the struct\n");
    New full = { .a = 9, .b = 8, .c = 7, .d = 6 };
    fake_nvs_blob = (const unsigned char*)&full; fake_nvs_len = sizeof(New);
    EEPROM::read_subsystem_settings<New>("KEY", &s, &NEW_DEFAULTS);
    check("every stored value is used", s.a == 9 && s.b == 8 && s.c == 7 && s.d == 6);

    printf("\nfirst boot after a key change: nothing stored\n");
    fake_nvs_len = -1; fake_nvs_last_write_len = -1;
    memset(&s, 0xAA, sizeof(s));
    EEPROM::read_subsystem_settings<New>("KEY", &s, &NEW_DEFAULTS);
    check("defaults are loaded", s.a == 1 && s.b == 2 && s.c == 78 && s.d == 20);
    check("and seeded into flash", fake_nvs_last_write_len == (int)sizeof(New));

    printf("\na downgrade: flash holds MORE than this firmware understands\n");
    unsigned char big[sizeof(New) + 4]; memset(big, 0x5A, sizeof(big));
    fake_nvs_blob = big; fake_nvs_len = sizeof(big); fake_nvs_last_write_len = -1;
    memset(&s, 0xAA, sizeof(s));
    EEPROM::read_subsystem_settings<New>("KEY", &s, &NEW_DEFAULTS);
    check("defaults are used rather than a misread", s.a == 1 && s.b == 2 && s.c == 78 && s.d == 20);
    check("the newer block is left intact for a re-upgrade", fake_nvs_last_write_len == -1);

    printf("\n%s\n", fails ? "FAILED" : "all good");
    return fails ? 1 : 0;
}
