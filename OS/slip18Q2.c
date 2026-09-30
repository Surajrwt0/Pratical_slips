#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid;

    pid = fork();

    if(pid < 0)
    {
        printf("Fork failed\n");
    }
    else if(pid == 0)
    {
        printf("Child Process\n");
        printf("Child PID = %d\n", getpid());
        printf("Parent PID = %d\n", getppid());

        sleep(5);

        printf("\nAfter Parent Terminates:\n");
        printf("Child PID = %d\n", getpid());
        printf("New Parent PID = %d\n", getppid());
    }
    else
    {
        printf("Parent Process\n");
        printf("Parent PID = %d\n", getpid());

        sleep(2);

        printf("Parent process terminated\n");
    }

    return 0;
}