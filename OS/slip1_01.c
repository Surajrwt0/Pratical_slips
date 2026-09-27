#include <stdio.h>
#define P 5
#define R 3
int allocation[P][R] = {
    {2, 3, 2},
    {4, 0, 0},
    {5, 0, 4},
    {4, 3, 3},
    {2, 2, 4}
};
int max[P][R] = {
    {9, 7, 5},
    {5, 2, 2},
    {1, 0, 4},
    {4, 4, 4},
    {6, 5, 5}
};
int available[R];
int need[P][R];

void calculateNeed()
{
    int i, j;

    for (i = 0; i < P; i++)
    {
        for (j = 0; j < R; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

void acceptAvailable()
{
    int i;

    printf("Enter Available resources (A B C): ");
    for (i = 0; i < R; i++)
    {
        scanf("%d", &available[i]);
    }

    printf("Available resources accepted successfully.\n");
}

void displayAllocationMax()
{
    int i;

    printf("\nProcess\tAllocation\tMax\n");

    for (i = 0; i < P; i++)
    {
        printf("P%d\t", i);

        printf("%d %d %d\t\t",
               allocation[i][0],
               allocation[i][1],
               allocation[i][2]);

        printf("%d %d %d\n",
               max[i][0],
               max[i][1],
               max[i][2]);
    }
}

void displayNeed()
{
    int i;

    calculateNeed();

    printf("\nNeed Matrix\n");
    printf("Process\tA B C\n");

    for (i = 0; i < P; i++)
    {
        printf("P%d\t%d %d %d\n",
               i,
               need[i][0],
               need[i][1],
               need[i][2]);
    }
}

void displayAvailable()
{
    printf("\nAvailable Resources\n");
    printf("A\tB\tC\n");
    printf("%d\t%d\t%d\n",
           available[0],
           available[1],
           available[2]);
}

int main()
{
    int choice;

    /* Given Available resources */
    available[0] = 3;
    available[1] = 3;
    available[2] = 2;
    calculateNeed();
    do
    {
        printf("\n===== BANKER'S ALGORITHM MENU =====\n");
        printf("1. Accept Available\n");
        printf("2. Display Allocation and Max\n");
        printf("3. Display Need Matrix\n");
        printf("4. Display Available\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                acceptAvailable();
                break;

            case 2:
                displayAllocationMax();
                break;

            case 3:
                displayNeed();
                break;

            case 4:
                displayAvailable();
                break;

            case 5:
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}
