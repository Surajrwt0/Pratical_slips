#include <stdio.h>

void calculateNeed(int allocation[][10], int max[][10],int need[][10], int n, int m)
{
    int i, j;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            need[i][j] = max[i][j] - allocation[i][j];
    }
}

void displayNeed(int need[][10], int n, int m)
{
    int i, j;

    printf("\nNeed Matrix:\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d: ", i);

        for(j = 0; j < m; j++)
            printf("%d ", need[i][j]);

        printf("\n");
    }
}

void requestResource(int allocation[][10], int need[][10],int available[], 
    int request[],int process, int m)
{
    int i;

    /* Check Request <= Need */
    for(i = 0; i < m; i++)
    {
        if(request[i] > need[process][i])
        {
            printf("\nRequest cannot be granted.");
            printf("\nRequest is greater than Need.");
            return;
        }
    }

    /* Check Request <= Available */
    for(i = 0; i < m; i++)
    {
        if(request[i] > available[i])
        {
            printf("\nRequest cannot be granted immediately.");
            printf("\nResources are not available.");
            return;
        }
    }

    printf("\nRequest can be granted immediately.");

    /* Temporarily allocate resources */
    for(i = 0; i < m; i++)
    {
        available[i] -= request[i];
        allocation[process][i] += request[i];
        need[process][i] -= request[i];
    }

    printf("\nResources allocated successfully.");
}

int main()
{
    int n, m, i, j;
    int process;
    int allocation[10][10];
    int max[10][10];
    int need[10][10];
    int available[10];
    int request[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("\nEnter Allocation Matrix:\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d: ", i);

        for(j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);
    }

    printf("\nEnter Max Matrix:\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d: ", i);

        for(j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    }

    printf("\nEnter Available:\n");

    for(j = 0; j < m; j++)
        scanf("%d", &available[j]);

    calculateNeed(allocation, max, need, n, m);

    displayNeed(need, n, m);

    printf("\nEnter process number making request: ");
    scanf("%d", &process);

    printf("Enter resource request:\n");

    for(j = 0; j < m; j++)
        scanf("%d", &request[j]);

    requestResource(allocation, need, available,request, process, m);
    return 0;
}