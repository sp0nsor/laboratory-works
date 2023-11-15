#include <stdio.h>
#include <unistd.h>

int main() {
    // Получение и вывод PID и PPID
    pid_t pid = getpid();
    pid_t ppid = getppid();
    
    printf("PID: %d\n", pid);
    printf("PPID: %d\n", ppid);

    // Использование fork для создания нового процесса
    pid_t child_pid = fork();

    if (child_pid == 0) {
        // Код, выполняемый дочерним процессом
        printf("Дочерний процесс. PID: %d, PPID: %d\n", getpid(), getppid());
    } else if (child_pid > 0) {
        // Код, выполняемый родительским процессом
        printf("Родительский процесс. PID: %d, PPID: %d\n", getpid(), getppid());
    } else {
        // Обработка ошибки fork()
        fprintf(stderr, "Ошибка при вызове fork()\n");
        return 1;
    }

    // Ожидание завершения дочернего процесса
    wait(NULL);

    return 0;
}