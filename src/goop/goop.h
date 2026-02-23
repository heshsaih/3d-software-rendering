typedef struct {
} goop_context;

int goop_init();
void goop_destroy();
void goop_log_info(const char *message);
void goop_log_warn(const char *message);
void goop_log_error(const char *message);
