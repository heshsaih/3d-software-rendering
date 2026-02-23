#include "goop.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOG_FORMAT "%s [%s]: %s\n"
#define DATE_FORMAT "%d-%m-%Y %H:%M:%S"
#define LOG_TYPE_ERROR "GOOP_ERROR"
#define LOG_TYPE_WARN "GOOP_WARN"
#define LOG_TYPE_INFO "GOOP_INFO"

void goop_log(const char *message, const char *type) {
    time_t now = time(NULL);
    struct tm t = {0};
    localtime_s(&t, &now);
    char date_buff[32];
    strftime(date_buff, 32, DATE_FORMAT, &t);
    printf(LOG_FORMAT, date_buff, type, message);
}

void goop_log_info(const char *message) { goop_log(message, LOG_TYPE_INFO); }

void goop_log_warn(const char *message) { goop_log(message, LOG_TYPE_WARN); }

void goop_log_error(const char *message) {
    goop_log(message, LOG_TYPE_ERROR);
    goop_destroy();
    exit(-1);
}
