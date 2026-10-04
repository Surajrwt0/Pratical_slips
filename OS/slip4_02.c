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
    printf("\nOrder of requests served:\n");
    printf("%d", head);
    /* Move LEFT */
    for (i = r - 1; i >= 0; i--) {
        if (req[i] < head) {
            total += abs(head - req[i]);
            head = req[i];
            printf(" -> %d", head);
        }
    }
    /* Go to beginning of disk */
    total += head;
    head = 0;
    printf(" -> %d", head);
    /* Move RIGHT */
    for (i = 0; i < r; i++) {
        if (req[i] > head) {
            total += abs(head - req[i]);
            head = req[i];
            printf(" -> %d", head);
        }
    }
    printf("\n\nTotal head movement = %d\n", total);
    return 0;
}