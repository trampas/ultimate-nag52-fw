#include "calibration_structs.h"
#include "tcu_alloc.h"
#include "esp_flash.h"
#include "esp_log.h"
#include "string.h"

CalibrationInfo* CAL_RAM_PTR = NULL;
HydraulicCalibration* HYDR_PTR = NULL;
MechanicalCalibration* MECH_PTR = NULL;
TorqueConverterCalibration* TCC_CFG_PTR = NULL;
ShiftAlgorithmPack* SHIFT_ALGO_CFG_PTR = NULL;

uint16_t crc(const uint8_t* buffer, uint16_t len) {
    uint16_t res = 0;
    for(uint16_t i = 0; i < len; i++) {
        res += i;
        res += buffer[i];
    }
    return res;
}

// Sanity check the values that are used as divisors in the control code.
// A zeroed block would otherwise cause divide-by-zero exceptions at runtime.
static esp_err_t check_calibration_plausible(const CalibrationInfo* c) {
    // Index the packed struct directly (avoids taking an unaligned pointer)
    bool ratio_zero = false;
    for (int i = 1; i <= 5; i++) {
        if (c->mech_cal.ratio_table[i] == 0) {
            ratio_zero = true;
        }
    }
    if (ratio_zero) {
        ESP_LOGE("CAL", "Calibration load failed. Ratio table has 0'ed values!");
        return ESP_ERR_INVALID_ARG;
    }
    if (c->hydr_cal.p_multi_1 == 0 || c->hydr_cal.p_multi_other == 0) {
        ESP_LOGE("CAL", "Calibration load failed. Hydraulic p_multi has 0'ed values!");
        return ESP_ERR_INVALID_ARG;
    }
    for (int i = 0; i < SHIFT_ARRAY_LEN; i++) {
        if (c->hydr_cal.shift_spc_gain[i] == 0) {
            ESP_LOGE("CAL", "Calibration load failed. shift_spc_gain[%d] is 0!", i);
            return ESP_ERR_INVALID_ARG;
        }
        if (c->mech_cal.turbine_drag[i] == 0 || c->mech_cal.intertia_torque[i] == 0) {
            ESP_LOGW("CAL", "Mechanical calibration entry %d has a 0 turbine_drag/inertia value", i);
        }
    }
    if (c->tcc_cal.multiplier_map_z[0] == 0 || c->tcc_cal.multiplier_map_z[1] == 0) {
        ESP_LOGW("CAL", "TCC multiplier map has 0'ed values");
    }
    return ESP_OK;
}

esp_err_t EGSCal::init_egs_calibration() {
    // First of all, allocate our buffer
    esp_err_t ret = ESP_OK;
    CAL_RAM_PTR = reinterpret_cast<CalibrationInfo*>(TCU_HEAP_ALLOC(sizeof(CalibrationInfo)));
    if (NULL == CAL_RAM_PTR) {
        ret = ESP_ERR_NO_MEM;
    } else {
        // Allocation OK!
        ret = esp_flash_read(NULL, static_cast<void*>(CAL_RAM_PTR), CALIBRATION_START_ADDRESS, sizeof(CalibrationInfo));
        if (ESP_OK == ret) {
            // Copy OK!
            if (CAL_RAM_PTR->magic != 0xDEADBEEFu) {
                // Magic failed
                ret = ESP_ERR_INVALID_VERSION;
                goto exit;
            }
            if (CAL_RAM_PTR->len != sizeof(CalibrationInfo)) {
                // Size mismatch (Maybe data is added?)
                ESP_LOGE("CAL", "Calibration load failed. Length mismatch. Length at info is %d, calibration size is %d", (int)CAL_RAM_PTR->len, (int)sizeof(CalibrationInfo));
                ret = ESP_ERR_INVALID_SIZE;
                goto exit;
            }
            uint16_t crc_calculated = crc(&(reinterpret_cast<uint8_t*>(CAL_RAM_PTR))[8], sizeof(CalibrationInfo)-8);
            if (crc_calculated != CAL_RAM_PTR->crc) {
                // CRC Error
                ESP_LOGE("CAL", "Calibration load failed. CRC error. Wanted %04X, got %04X", crc_calculated, CAL_RAM_PTR->crc);
                ret = ESP_ERR_INVALID_CRC;
                goto exit;
            }
            // Guard against zeroed CAL
            ret = check_calibration_plausible(CAL_RAM_PTR);
            if (ESP_OK != ret) {
                goto exit;
            }
            // All OK!
            HYDR_PTR = &CAL_RAM_PTR->hydr_cal;
            MECH_PTR = &CAL_RAM_PTR->mech_cal;
            TCC_CFG_PTR = &CAL_RAM_PTR->tcc_cal;
            SHIFT_ALGO_CFG_PTR = &CAL_RAM_PTR->shift_algo_cal;
        }
    }
exit:
    return ret;
}

esp_err_t EGSCal::reload_egs_calibration() {
    // First of all, allocate a temp buffer
    esp_err_t ret = ESP_OK;
    if (nullptr == CAL_RAM_PTR) { // CAL Info is not set, cannot 'reload', as it was never allocated
        ret = ESP_ERR_INVALID_STATE;
    } else {
        CalibrationInfo* tmp = reinterpret_cast<CalibrationInfo*>(TCU_HEAP_ALLOC(sizeof(CalibrationInfo)));
        if (NULL == tmp) {
            ret = ESP_ERR_NO_MEM;
        } else {
            // Allocation OK!
            ret = esp_flash_read(NULL, static_cast<void*>(tmp), CALIBRATION_START_ADDRESS, sizeof(CalibrationInfo));
            if (ESP_OK == ret) {
                // Copy OK!
                if (tmp->magic != 0xDEADBEEFu) {
                    // Magic failed
                    ret = ESP_ERR_INVALID_VERSION;
                }
                else if (tmp->len != sizeof(CalibrationInfo)) {
                    // Size mismatch (Maybe data is added?)
                    ESP_LOGE("CAL", "Calibration load failed. Length mismatch. Length at info is %d, calibration size is %d", (int)tmp->len, (int)sizeof(CalibrationInfo));
                    ret = ESP_ERR_INVALID_SIZE;
                }
                else {
                    uint16_t crc_calculated = crc(&(reinterpret_cast<uint8_t*>(tmp))[8], sizeof(CalibrationInfo)-8);
                    if (crc_calculated != tmp->crc) {
                        // CRC Error
                        ESP_LOGE("CAL", "Calibration load failed. CRC error. Wanted %04X, got %04X", crc_calculated, tmp->crc);
                        ret = ESP_ERR_INVALID_CRC;
                    }
                    else {
                        // Guard against zeroed CAL (Check the NEW block, not the one already in use)
                        ret = check_calibration_plausible(tmp);
                        if (ESP_OK == ret) {
                            // Copy the temporery CalInfo to the in use one!
                            memcpy(CAL_RAM_PTR, tmp, sizeof(CalibrationInfo));
                        }
                    }
                }
            }
            // Always release the temp buffer (Previously leaked on the early-exit paths)
            TCU_FREE(tmp);
        }
    }
    return ret;
}