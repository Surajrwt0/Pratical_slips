#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, r, head, i, j, temp;
    int req[100];
    int total = 0;

    printf("Enter total number of disk blocks: ");
    scanf("%d", &n);

    printf("Enter number of requests: ");
    scanf("%d", &r);

    printf("Enter disk request string:\n");
    for (i = 0; i < r; i++)
        scanf("%d", &req[i]);

    printf("Enter current head position: ");
    scanf("%d", &head);
    /* Sort requests */
    for (i = 0; i < r - 1; i++) {
        for (j = i + 1; j < r; j++) {
            if (req[i] > req[j]) {
                temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }
    printf("\nHead Movement:\n");
    /* Move RIGHT */
    for (i = 0; i < r; i++) {
        if (req[i] >= head) {
            int movement = abs(head - req[i]);

            printf("%d -> %d = %d\n", head, req[i], movement);

            total += movement;
            head = req[i];
        }
    }
    /* Move to end of disk */
    if (head != n - 1) {
        printf("%d -> %d = %d\n", head, n - 1, (n - 1) - head);

        total += (n - 1) - head;
        head = n - 1;
    }
    /* Circular jump to beginning */
    printf("%d -> 0 = %d\n", head, head);
    total += head;
    head = 0;
    /* Continue moving RIGHT */
    for (i = 0; i < r; i++) {
        if (req[i] < head) {
            int movement = abs(head - req[i]);

            printf("%d -> %d = %d\n", head, req[i], movement);

            total += movement;
            head = req[i];
        }
    }
    printf("\nTotal head movement = %d\n", total);
    return 0;
}