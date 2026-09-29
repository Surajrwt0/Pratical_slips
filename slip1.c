// 1,4,11 

#include <stdio.h>

int main()
{
    int n, m, i, j, choice;
    int allocation[10][10], max[10][10];
    int need[10][10], available[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d: ", i);
        for(j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("\nEnter Max Matrix:\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d: ", i);
        for(j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    do
    {
        printf("\n1. Accept Available");
        printf("\n2. Display Allocation and Max");
        printf("\n3. Display Need");
        printf("\n4. Display Available");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter Available: ");
                for(j = 0; j < m; j++)
                {
                    scanf("%d", &available[j]);
                }
                break;

            case 2:
                printf("\nAllocation\tMax\n");
                for(i = 0; i < n; i++)
                {
                    printf("P%d\t", i);
                    for(j = 0; j < m; j++)
                    {
                        printf("%d ", allocation[i][j]);
                    }

                    printf("\t");

                    for(j = 0; j < m; j++)
                    {
                        printf("%d ", max[i][j]);
                    }

                    printf("\n");
                }
                break;

            case 3:
                printf("\nNeed Matrix:\n");
                for(i = 0; i < n; i++)
                {
                    printf("P%d: ", i);
                    for(j = 0; j < m; j++)
                    {
                        printf("%d ", need[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 4:
                printf("\nAvailable: ");
                for(j = 0; j < m; j++)
                {
                    printf("%d ", available[j]);
                }
                break;

            case 5:
                printf("Exit");
                break;

            default:
                printf("\nInvalid choice");
        }

    } while(choice != 5);

    return 0;
}