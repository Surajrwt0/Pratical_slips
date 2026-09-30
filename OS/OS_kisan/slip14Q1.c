#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void bubbleSort(int a[], int n)
{
    int i, j, temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, i, search;
    int a[20];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to search: ");
    scanf("%d", &search);

    bubbleSort(a, n);

    printf("\nSorted Array:\n");

    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

    int pid = fork();

    if(pid < 0)
    {
        printf("Fork failed\n");
    }
    else if(pid == 0)
    {
        char *args[25];
        char searchStr[10];
        char nStr[10];

        sprintf(nStr, "%d", n);
        sprintf(searchStr, "%d", search);

        args[0] = "./child";
        args[1] = nStr;

        for(i = 0; i < n; i++)
        {
            args[i + 2] = malloc(10);
            sprintf(args[i + 2], "%d", a[i]);
        }

        args[n + 2] = searchStr;
        args[n + 3] = NULL;

        execve("./child", args, NULL);

        printf("execve failed\n");
    }
    else
    {
        wait(NULL);
    }

    return 0;
}