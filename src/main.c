#include "goop/goop.h"

int main() {
    int status = goop_init();
    goop_log_info("Info lot tego");
    goop_log_warn("warn lotasiet");
    goop_log_error("ded");
    goop_destroy();
    return 0;
}
