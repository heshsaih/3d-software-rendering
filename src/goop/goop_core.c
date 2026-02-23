#include "goop.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_init.h>
#include <stddef.h>
#include <stdlib.h>

goop_context *ctx = NULL;


int goop_init() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        goop_log_error("SDL initialization failed, returning");
        return -1;
    }

    goop_log_info("SDL context initialized successfully");
    ctx = malloc(sizeof(goop_context));
    goop_log_info("GOOP context initialized");
    return 0;
}

void goop_destroy() {
    goop_log_info("GOOP context destoying");
    free(ctx);
    goop_log_info("GOOP Context destroyed");
    goop_log_info("GOOP cleared successfully, exiting");
}
