#include <stdio.h>
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

void insertionSort(int a[], int n)
{
    int i, j, key;

    for(i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while(j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

int main()
{
    int n, i;
    int a[50], b[50];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }

    int pid = fork();

    if(pid < 0)
    {
        printf("Fork failed\n");
    }
    else if(pid == 0)
    {
        /* Child process */
        insertionSort(b, n);

        printf("\nChild Process - Insertion Sort:\n");

        for(i = 0; i < n; i++)
            printf("%d ", b[i]);

        printf("\n");
    }
    else
    {
        /* Parent process */
        bubbleSort(a, n);

        printf("\nParent Process - Bubble Sort:\n");

        for(i = 0; i < n; i++)
            printf("%d ", a[i]);

        printf("\n");

        wait(NULL);
    }

    return 0;
}