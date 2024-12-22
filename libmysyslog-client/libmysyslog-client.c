/* 
 * Простой пример программы, использующей libmysyslog для логирования.
 * Демонстрирует опции командной строки для настройки сообщения журнала.
 */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "libmysyslog.h"

/* Функция для вывода страницы помощи */
static void
print_usage (const char *program_name)
{
  fprintf (stderr, 
           "Использование: %s -m сообщение -l уровень -d драйвер -f формат -p путь\n", 
           program_name);
}

/* Основная функция */
int
main (int argc, char *argv[])
{
  int opt;
  char *msg = NULL;
  int level = INFO;
  int driver = 0;
  int format = 0;
  char *path = NULL;

  /* Разбор параметров командной строки */
  while ((opt = getopt (argc, argv, "m:l:d:f:p:")) != -1)
    {
      switch (opt)
        {
        case 'm':
          msg = optarg;
          break;
        case 'l':
          level = atoi (optarg);
          break;
        case 'd':
          driver = atoi (optarg);
          break;
        case 'f':
          format = atoi (optarg);
          break;
        case 'p':
          path = optarg;
          break;
        default:
          print_usage (argv[0]);
          exit (EXIT_FAILURE);
        }
    }

  /* Проверка обязательных параметров */
  if (msg == NULL || path == NULL)
    {
      fprintf (stderr, "Ошибка: Сообщение (-m) и путь (-p) обязательны.\n");
      print_usage (argv[0]);
      exit (EXIT_FAILURE);
    }

  /* Попытка записи в журнал */
  if (mysyslog (msg, level, driver, format, path) != 0)
    {
      fprintf (stderr, "Ошибка: Не удалось записать в журнал.\n");
      exit (EXIT_FAILURE);
    }

  return 0;
}
