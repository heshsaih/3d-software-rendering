#include "goop.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_init.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOG_FORMAT "%s [GOOP_%s]: %s\n"
#define DATE_FORMAT "%d-%m-%Y %H:%M:%S"

char *get_time_formatted() {
    time_t now = time(NULL);
    struct tm t = {0};
    localtime_s(&t, &now);
    char *date_buff = malloc(64);
    strftime(date_buff, 64, DATE_FORMAT, &t);
    return date_buff;
}

void goop_log_info(const char *message) {
    char *date = get_time_formatted();
    printf(LOG_FORMAT, date, "INFO", message);
    free(date);
}

void goop_log_warn(const char *message) {
    char *date = get_time_formatted();
    printf(LOG_FORMAT, date, "WARN", message);
    free(date);
}
void goop_log_error(const char *message) {
    char *date = get_time_formatted();
    printf(LOG_FORMAT, date, "ERROR", message);
    free(date);

    goop_destroy();
    exit(-1);
}

goop_context *goop_init() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("FAILED!");
        return NULL;
    }

    return malloc(sizeof(goop_context));
}

void goop_destroy() {}
