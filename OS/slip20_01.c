// sahi hai bhai
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
void bubbleSort(int a[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
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

    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

void display(int a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
}

int main()
{
    int n, i;
    int a[100], b[100];

    printf("Enter number of integers: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];       // Copy for child process
    }

    pid_t pid = fork();

    if (pid < 0)
    {
        printf("Fork failed!\n");
        return 1;
    }

    else if (pid == 0)
    {
        // Child process
        printf("\nChild Process (Insertion Sort)\n");

        insertionSort(b, n);

        printf("Sorted array using Insertion Sort: ");
        display(b, n);

        exit(0);
    }

    else
    {
        // Parent process
        printf("\nParent Process (Bubble Sort)\n");

        bubbleSort(a, n);

        printf("Sorted array using Bubble Sort: ");
        display(a, n);

        // Parent waits for child
        wait(NULL);

        printf("\nParent process: Child process completed.\n");
    }

    return 0;
}