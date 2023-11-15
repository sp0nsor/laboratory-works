#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    int opt;
    char buffer[MAX_BUFF_SIZE];
    int output_fd;
    int append_mode = 0;

    // Обработка опций командной строки
    while ((opt = getopt(argc, argv, "a")) != -1) {
        switch (opt) {
            case 'a':
                // Включить режим добавления в файл (append mode)
                append_mode = 1;
                break;
            default:
                fprintf(stderr, "Использование: %s [-a] [file ...]\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    // Открываем файлы для записи
    for (int i = optind; i < argc; i++) {
        if (append_mode) {
            output_fd = open(argv[i], O_WRONLY | O_CREAT | O_APPEND, 0644);
        } else {
            output_fd = open(argv[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        }

        if (output_fd == -1) {
            perror("Не удалось открыть файл");
            exit(EXIT_FAILURE);
        }

        // Чтение со стандартного ввода и запись в файл
        ssize_t bytesRead;
        while ((bytesRead = read(STDIN_FILENO, buffer, MAX_BUFF_SIZE)) > 0) {
            if (write(STDOUT_FILENO, buffer, bytesRead) == -1) {
                perror("Ошибка записи в стандартный вывод");
                exit(EXIT_FAILURE);
            }

            if (write(output_fd, buffer, bytesRead) == -1) {
                perror("Ошибка записи в файл");
                exit(EXIT_FAILURE);
            }
        }

        if (bytesRead == -1) {
            perror("Ошибка чтения со стандартного ввода");
            exit(EXIT_FAILURE);
        }

        // Закрываем файл
        if (close(output_fd) == -1) {
            perror("Ошибка закрытия файла");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
