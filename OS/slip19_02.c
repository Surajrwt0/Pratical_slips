#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        printf("Fork failed!\n");
        return 1;
    }

    if (pid == 0)
    {
        printf("Child Process\n");
        printf("Old Nice Value: %d\n", nice(0));

        if (nice(-5) == -1)
            perror("nice");

        printf("New Nice Value: %d\n", nice(0));

        for (int i = 1; i <= 5; i++)
            printf("Child: %d\n", i);
    }
    else
    {
        printf("Parent Process\n");

        for (int i = 1; i <= 5; i++)
            printf("Parent: %d\n", i);

        wait(NULL);
    }

    return 0;
}