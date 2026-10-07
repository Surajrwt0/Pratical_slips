//sahi hai bhai
#include <stdio.h>

int main()
{
    int allocation[20][20], max[20][20], need[20][20];
    int available[20];
    int n, m;
    int i, j, choice;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("\nEnter Allocation Matrix:\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d: ", i);
        for (j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("\nEnter Max Matrix:\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d: ", i);
        for (j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    /* Calculate Need = Max - Allocation */
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    do
    {
        printf("\n========== BANKER'S ALGORITHM ==========\n");
        printf("1. Accept Available\n");
        printf("2. Display Allocation, Max\n");
        printf("3. Display Need Matrix\n");
        printf("4. Display Available\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter Available resources:\n");

                for (j = 0; j < m; j++)
                {
                    printf("Available[%d]: ", j);
                    scanf("%d", &available[j]);
                }

                printf("Available resources accepted.\n");
                break;

            case 2:
                printf("\nProcess\tAllocation\tMax\n");

                for (i = 0; i < n; i++)
                {
                    printf("P%d\t", i);

                    for (j = 0; j < m; j++)
                    {
                        printf("%d ", allocation[i][j]);
                    }

                    printf("\t\t");

                    for (j = 0; j < m; j++)
                    {
                        printf("%d ", max[i][j]);
                    }

                    printf("\n");
                }
                break;

            case 3:
                printf("\n========== NEED MATRIX ==========\n");

                printf("Process\t");
                for (j = 0; j < m; j++)
                {
                    printf("R%d ", j);
                }
                printf("\n");

                for (i = 0; i < n; i++)
                {
                    printf("P%d\t", i);

                    for (j = 0; j < m; j++)
                    {
                        printf("%d ", need[i][j]);
                    }

                    printf("\n");
                }
                break;

            case 4:
                printf("\n========== AVAILABLE ==========\n");

                for (j = 0; j < m; j++)
                {
                    printf("R%d\t", j);
                }

                printf("\n");

                for (j = 0; j < m; j++)
                {
                    printf("%d\t", available[j]);
                }

                printf("\n");
                break;

            case 5:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}