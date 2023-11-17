#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Создаем новый процесс
    pid_t child_pid = fork();

    if (child_pid == -1) {
        // Обработка ошибки fork
        perror("Ошибка при вызове fork()");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        // Код, выполняемый дочерним процессом

        // Пример исполнения gnome-editor (замените на нужную вам программу)
        char *program = "gnome-editor";
        char *const args[] = {program, NULL};

        // Заменяем текущий процесс на новый, исполняющий указанную программу
        execve(program, args, NULL);

        // Если execve() вернул ошибку, то выводим сообщение об ошибке
        perror("Ошибка при вызове execve()");
        exit(EXIT_FAILURE);
    } else {
        // Код, выполняемый родительским процессом

        // Ожидание завершения дочернего процесса
        wait(NULL);

        printf("Родительский процесс завершен.\n");
    }

    return 0;
}
