#ifndef ESP_LOG_STUB_H
#define ESP_LOG_STUB_H
#include <stdio.h>
#include "esp_err.h"
extern int SIM_LOG_VERBOSE;
extern void sim_log(const char* lvl, const char* tag, const char* fmt, ...);
#define ESP_LOGI(tag, fmt, ...) sim_log("I", tag, fmt, ##__VA_ARGS__)
#define ESP_LOGW(tag, fmt, ...) sim_log("W", tag, fmt, ##__VA_ARGS__)
#define ESP_LOGE(tag, fmt, ...) sim_log("E", tag, fmt, ##__VA_ARGS__)
#define ESP_LOGD(tag, fmt, ...) do {} while (0)
#define ESP_LOG_INFO 3
#define ESP_LOG_WARN 2
#define ESP_LOG_ERROR 1
#define ESP_LOG_LEVEL(lvl, tag, fmt, ...) sim_log("L", tag, fmt, ##__VA_ARGS__)
#endif
