#include <stdio.h>

int main() {
    int alloc[5][4] = {
        {0, 0, 1, 2},
        {1, 0, 0, 0},
        {1, 3, 5, 4},
        {0, 6, 3, 2},
        {0, 0, 1, 4}
    };

    int max[5][4] = {
        {0, 0, 1, 2},
        {1, 7, 5, 0},
        {2, 3, 5, 6},
        {0, 6, 5, 2},
        {0, 6, 5, 6}
    };

    int avail[4] = {1, 5, 2, 0};
    int need[5][4];
    int finish[5] = {0};
    int safe[5];
    int i, j, k = 0, count = 0, found;

    /* Calculate Need Matrix */
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    printf("Need Matrix:\n");
    printf("     A B C D\n");

    for (i = 0; i < 5; i++) {
        printf("P%d : ", i);
        for (j = 0; j < 4; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }

    /* Banker's Algorithm */
    while (count < 5) {
        found = 0;

        for (i = 0; i < 5; i++) {

            if (finish[i] == 0) {
                for (j = 0; j < 4; j++) {
                    if (need[i][j] > avail[j])
                        break;
                }

                if (j == 4) {
                    for (j = 0; j < 4; j++)
                        avail[j] += alloc[i][j];

                    safe[k++] = i;
                    finish[i] = 1;
                    count++;
                    found = 1;
                }
            }
        }

        if (found == 0)
            break;
    }

    if (count == 5) {
        printf("\nSystem is in SAFE state.\n");
        printf("Safe Sequence: ");

        for (i = 0; i < 5; i++)
            printf("P%d ", safe[i]);

        printf("\n");
    }
    else {
        printf("\nSystem is NOT in safe state.\n");
    }

    return 0;
}