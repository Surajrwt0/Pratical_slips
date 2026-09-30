#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    pid = fork();

    if(pid < 0)
    {
        printf("Fork failed.");
    }
    else if(pid == 0)
    {
        /* Child process */
        nice(-5);

        printf("Child Process\n");
        printf("Child PID = %d\n", getpid());
        printf("Child Priority = %d\n", nice(0));
    }
    else
    {
        /* Parent process */
        wait(NULL);

        printf("Parent Process\n");
        printf("Parent PID = %d\n", getpid());
        printf("Parent Priority = %d\n", nice(0));
    }

    return 0;
}