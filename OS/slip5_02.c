#include <stdio.h>
int main() {
    int n, m, i, j, p;
    int total[10], alloc[10][10], max[10][10], need[10][10];
    int avail[10], request[10];
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource types: ");
    scanf("%d", &m);
    printf("Enter total instances of each resource:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &total[i]);
    printf("\nEnter Allocation Matrix:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);
    }
    printf("\nEnter Max Matrix:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i);
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    }
    /* Calculate Available */
    for (j = 0; j < m; j++) {
        avail[j] = total[j];

        for (i = 0; i < n; i++)
            avail[j] -= alloc[i][j];
    }
    /* Calculate Need */
    printf("\nNeed Matrix:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i);

        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%d ", need[i][j]);
        }

        printf("\n");
    }
    /* Resource Request */
    printf("\nEnter process number making request: ");
    scanf("%d", &p);
    printf("Enter request for P%d:\n", p);
    for (j = 0; j < m; j++)
        scanf("%d", &request[j]);
    /* Check Request <= Need */
    for (j = 0; j < m; j++) {
        if (request[j] > need[p][j]) {
            printf("\nError: Request is greater than Need.\n");
            return 0;
        }
    }
    /* Check Request <= Available */
    for (j = 0; j < m; j++) {
        if (request[j] > avail[j]) {
            printf("\nRequest cannot be granted immediately.\n");
            return 0;
        }
    }
    printf("\nRequest can be granted immediately.\n");
    return 0;
}