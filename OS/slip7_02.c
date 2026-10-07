#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
    pid_t pid;
    int priority;
    pid = fork();
    if (pid < 0)
    {
        printf("Fork failed\n");
        return 1;
    }
    if (pid == 0)
    {
        /* Child process */
        printf("Child process started\n");
        printf("Child PID: %d\n", getpid());
        priority = nice(-5);
        printf("Child nice value after nice(): %d\n", priority);
        printf("Child process priority increased\n");
    }
    else
    {
        /* Parent process */
        printf("Parent process started\n");
        printf("Parent PID: %d\n", getpid());
        wait(NULL);
        printf("Child process completed\n");
    }
    return 0;
}