#include <stdio.h>

int main()
{
    int n, m, i, j, k;
    int allocation[10][10], max[10][10], need[10][10];
    int available[10], work[10];
    int finish[10] = {0};
    int safe[10], count = 0, found;

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

    /* Calculate Need */

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            need[i][j] = max[i][j] - allocation[i][j];
    }

    printf("\nNeed Matrix:\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d: ", i);

        for(j = 0; j < m; j++)
            printf("%d ", need[i][j]);

        printf("\n");
    }

    for(j = 0; j < m; j++)
        work[j] = available[j];

    while(count < n)
    {
        found = 0;

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                for(j = 0; j < m; j++)
                {
                    if(need[i][j] > work[j])
                        break;
                }

                if(j == m)
                {
                    for(k = 0; k < m; k++)
                        work[k] += allocation[i][k];

                    safe[count] = i;
                    finish[i] = 1;
                    count++;
                    found = 1;
                }
            }
        }

        if(found == 0)
            break;
    }

    if(count == n)
    {
        printf("\nSystem is in SAFE state.");

        printf("\nSafe Sequence: ");

        for(i = 0; i < n; i++)
            printf("P%d ", safe[i]);
    }
    else
    {
        printf("\nSystem is NOT in SAFE state.");
    }

    return 0;
}