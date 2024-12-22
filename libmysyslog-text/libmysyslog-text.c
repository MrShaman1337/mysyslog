#include "libmysyslog-text.h"

/* Запись текстового сообщения в лог-файл */
int
text_log (const char *message, int level, const char *log_path)
{
    return mysyslog (message, level, /* driver */ 0, /* format */ 0, log_path);
}
