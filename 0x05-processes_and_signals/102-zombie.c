#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int infinite_while(void)
{
    while (1)
    {
        sleep(1);
    }
    return (0);
}

int main(void)
{
    int i = 0;
    pid_t pid;

    while (i < 5)
    {
        pid = fork();
        if (pid == 0)
        {
            printf("Zombie process created, PID: %d\n", getpid());
            return (0);
        }
        else
        {
            wait(NULL);
            i++;
        }
    }

    infinite_while();
    return (0);
}
