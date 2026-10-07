#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
int main()
{
    char command[100];
    char *args[20];
    int i;

    while (1)
    {
        printf("$ ");
        fgets(command, sizeof(command), stdin);
        
        /* Exit command */
        if (strcmp(command, "exit") == 0)
            break;

        /* Tokenize command */
        i = 0;
        args[i] = strtok(command, " ");

        while (args[i] != NULL)
        {
            i++;
            args[i] = strtok(NULL, " ");
        }

        /* count command */
        if (args[0] != NULL && strcmp(args[0], "count") == 0)
        {
            FILE *fp;
            char ch;
            int count = 0;
            int inWord = 0;

            if (args[1] == NULL || args[2] == NULL)
            {
                printf("Usage: count c/w/l filename\n");
                continue;
            }

            fp = fopen(args[2], "r");

            if (fp == NULL)
            {
                printf("File not found!\n");
                continue;
            }

            if (strcmp(args[1], "c") == 0)
            {
                while ((ch = fgetc(fp)) != EOF)
                    count++;

                printf("Number of characters = %d\n", count);
            }

            else if (strcmp(args[1], "w") == 0)
            {
                while ((ch = fgetc(fp)) != EOF)
                {
                    if (ch == ' ' || ch == '\n' ||
                        ch == '\t')
                    {
                        inWord = 0;
                    }
                    else if (inWord == 0)
                    {
                        count++;
                        inWord = 1;
                    }
                }

                printf("Number of words = %d\n", count);
            }

            else if (strcmp(args[1], "l") == 0)
            {
                while ((ch = fgetc(fp)) != EOF)
                {
                    if (ch == '\n')
                        count++;
                }

                printf("Number of lines = %d\n", count);
            }

            else
            {
                printf("Invalid count option!\n");
                printf("Use c for characters, w for words, l for lines.\n");
            }

            fclose(fp);
        }

        /* Normal shell commands */
        else
        {
            pid_t pid = fork();

            if (pid < 0)
            {
                printf("Fork failed!\n");
            }
            else if (pid == 0)
            {
                /* Child process */
                execvp(args[0], args);

                printf("Command not found!\n");
                exit(1);
            }
            else
            {
                /* Parent process */
                wait(NULL);
            }
        }
    }

    return 0;
}