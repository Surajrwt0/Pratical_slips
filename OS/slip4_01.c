#include <stdio.h>
int main() {
    int alloc[5][3], max[5][3], need[5][3];
    int avail[3];
    int total[3] = {7, 2, 6};
    int choice, i, j;
    while (1) {
        printf("\n--- BANKER'S ALGORITHM ---\n");
        printf("1. Accept Allocation and Max\n");
        printf("2. Accept Available\n");
        printf("3. Display Allocation and Max\n");
        printf("4. Find and Display Need\n");
        printf("5. Display Available\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("\nEnter Allocation Matrix:\n");
            for (i = 0; i < 5; i++) {
                printf("P%d: ", i);
                for (j = 0; j < 3; j++)
                    scanf("%d", &alloc[i][j]);
            }
            printf("\nEnter Max Matrix:\n");
            for (i = 0; i < 5; i++) {
                printf("P%d: ", i);
                for (j = 0; j < 3; j++)
                    scanf("%d", &max[i][j]);
            }
            break;
        case 2:
            printf("\nEnter Available resources (A B C): ");
            scanf("%d %d %d", &avail[0], &avail[1], &avail[2]);
            break;
        case 3:
            printf("\nAllocation Matrix:\n");
            printf("     A B C\n");
            for (i = 0; i < 5; i++) {
                printf("P%d : ", i);
                for (j = 0; j < 3; j++)
                    printf("%d ", alloc[i][j]);
                printf("\n");
            }
            printf("\nMax Matrix:\n");
            printf("     A B C\n");
            for (i = 0; i < 5; i++) {
                printf("P%d : ", i);
                for (j = 0; j < 3; j++)
                    printf("%d ", max[i][j]);
                printf("\n");
            }
            break;
        case 4:
            printf("\nNeed Matrix:\n");
            printf("     A B C\n");
            for (i = 0; i < 5; i++) {
                printf("P%d : ", i);
                for (j = 0; j < 3; j++) {
                    need[i][j] = max[i][j] - alloc[i][j];
                    printf("%d ", need[i][j]);
                }
                printf("\n");
            }
            break;
        case 5:
            printf("\nAvailable Resources:\n");
            printf("A = %d  B = %d  C = %d\n",
                   avail[0], avail[1], avail[2]);
            break;
        case 6:
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}