#include <stdio.h>

int main() {
    int frame[20], ref[50];
    int n, r, i, j, k = 0;
    int pageFault = 0, found;

    printf("Enter number of frames: ");
    scanf("%d", &n);

    printf("Enter number of pages: ");
    scanf("%d", &r);

    printf("Enter reference string:\n");
    for (i = 0; i < r; i++)
        scanf("%d", &ref[i]);

    /* Initialize frames */
    for (i = 0; i < n; i++)
        frame[i] = -1;

    printf("\nPage\tFrames\t\tStatus\n");

    for (i = 0; i < r; i++) {
        found = 0;

        /* Check if page is already present */
        for (j = 0; j < n; j++) {
            if (frame[j] == ref[i]) {
                found = 1;
                break;
            }
        }

        /* Page fault */
        if (found == 0) {
            frame[k] = ref[i];
            k = (k + 1) % n;
            pageFault++;
        }

        printf("%d\t", ref[i]);

        for (j = 0; j < n; j++) {
            if (frame[j] == -1)
                printf("- ");
            else
                printf("%d ", frame[j]);
        }

        if (found == 0)
            printf("\tPage Fault");
        else
            printf("\tHit");

        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFault);
    printf("Total Page Hits = %d\n", r - pageFault);

    return 0;
}