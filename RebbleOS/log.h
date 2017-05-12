#pragma once
/* log.h
 * routines for logging apps and system
 * RebbleOS
 *
 * Author: Barry Carter <barry.carter@gmail.com>
 */

#define SYS_LOG(module, lvl, fmt, ...) \
            log_printf(module, "SYS", lvl, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#define KERN_LOG(module, lvl, fmt, ...) \
            log_printf(module, "KERN", lvl, __FILE__, __LINE__, fmt, ##__VA_ARGS__)
#define DRV_LOG(module, lvl, fmt, ...) \
            log_printf(module, "DRIVER", lvl, __FILE__, __LINE__, fmt, ##__VA_ARGS__)


typedef enum LogLevel {
    APP_LOG_LEVEL_ERROR,
    APP_LOG_LEVEL_WARNING,
    APP_LOG_LEVEL_INFO,
    APP_LOG_LEVEL_DEBUG,
    APP_LOG_LEVEL_DEBUG_VERBOSE
} LogLevel;


void app_log_trace(uint8_t level, const char *filename, uint32_t f, const char *fmt, ...);
void log_printf(const char *layer, const char *module, uint8_t level, const char *filename, uint32_t line_no, const char *fmt, ...);
