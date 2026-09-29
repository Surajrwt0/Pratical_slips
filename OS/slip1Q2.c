#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main()
{
    char cmd[100], *a[10], *p;
    int i, fd, ch, c, w, l;

    while(1)
    {
        printf("$ ");
        fgets(cmd, 100, stdin);
        cmd[strlen(cmd)-1] = '\0';

        if(strcmp(cmd, "exit") == 0)
            break;

        i = 0;
        p = strtok(cmd, " ");

        while(p != NULL)
        {
            a[i++] = p;
            p = strtok(NULL, " ");
        }
        a[i] = NULL;

        if(strcmp(a[0], "count") == 0)
        {
            fd = open(a[2], O_RDONLY);

            if(fd == -1)
            {
                printf("File not found\n");
                continue;
            }

            c = w = l = 0;

            while(read(fd, &ch, 1) > 0)
            {
                c++;

                if(ch == ' ' || ch == '\n' || ch == '\t')
                    w++;

                if(ch == '\n')
                    l++;
            }

            close(fd);

            if(strcmp(a[1], "c") == 0)
                printf("Characters = %d\n", c);

            else if(strcmp(a[1], "w") == 0)
                printf("Words = %d\n", w);

            else if(strcmp(a[1], "l") == 0)
                printf("Lines = %d\n", l);
        }
        else
        {
            if(fork() == 0)
                execvp(a[0], a);
            else
                wait(NULL);
        }
    }

    return 0;
}