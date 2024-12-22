#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Уровни логирования */
enum log_level {
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR,
    LOG_CRITICAL
};

/* Форматы логов */
enum log_format {
    LOG_FORMAT_TEXT,
    LOG_FORMAT_JSON
};

/* Записать сообщение в лог-файл */
int
mysyslog (const char *message, enum log_level level, int driver, enum log_format format, const char *log_path)
{
    if (message == NULL || log_path == NULL)
    {
        fprintf (stderr, "Ошибка: message или log_path не могут быть NULL.\n");
        return -1;
    }

    /* Открытие файла для записи */
    FILE *log_file = fopen (log_path, "a");
    if (log_file == NULL)
    {
        perror ("Ошибка при открытии файла лога");
        return -1;
    }

    /* Получение текущего времени */
    time_t now = time (NULL);
    if (now == (time_t)(-1))
    {
        perror ("Ошибка при получении времени");
        fclose (log_file);
        return -1;
    }

    /* Форматирование временной метки */
    char timestamp[20];
    if (strftime (timestamp, sizeof (timestamp), "%Y-%m-%d %H:%M:%S", localtime (&now)) == 0)
    {
        fprintf (stderr, "Ошибка форматирования временной метки.\n");
        fclose (log_file);
        return -1;
    }

    /* Преобразование уровня логирования в строку */
    const char *level_str;
    switch (level)
    {
        case LOG_DEBUG:    level_str = "DEBUG";    break;
        case LOG_INFO:     level_str = "INFO";     break;
        case LOG_WARN:     level_str = "WARN";     break;
        case LOG_ERROR:    level_str = "ERROR";    break;
        case LOG_CRITICAL: level_str = "CRITICAL"; break;
        default:           level_str = "UNKNOWN";  break;
    }

    /* Запись сообщения в выбранном формате */
    if (format == LOG_FORMAT_TEXT)
    {
        fprintf (log_file, "%s [%s] driver=%d: %s\n", timestamp, level_str, driver, message);
    }
    else if (format == LOG_FORMAT_JSON)
    {
        fprintf (log_file,
                 "{\"timestamp\":\"%s\",\"level\":\"%s\",\"driver\":%d,\"message\":\"%s\"}\n",
                 timestamp, level_str, driver, message);
    }
    else
    {
        fprintf (stderr, "Ошибка: неизвестный формат лога.\n");
        fclose (log_file);
        return -1;
    }

    fclose (log_file);
    return 0;
}
