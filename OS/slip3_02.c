#include <stdio.h>
#include <stdlib.h>
int main() {
    int n, r, head, i, j;
    int req[100], visited[100] = {0};
    int total = 0, min, pos, distance;
    printf("Enter total number of disk blocks: ");
    scanf("%d", &n);
    printf("Enter number of requests: ");
    scanf("%d", &r);
    printf("Enter disk request string:\n");
    for (i = 0; i < r; i++)
        scanf("%d", &req[i]);
    printf("Enter current head position: ");
    scanf("%d", &head);
    printf("\nOrder of requests served:\n");
    printf("%d", head);
    for (i = 0; i < r; i++) {
        min = 9999;
        pos = -1;
        /* Find nearest request */
        for (j = 0; j < r; j++) {
            if (visited[j] == 0) {
                distance = abs(head - req[j]);
                if (distance < min) {
                    min = distance;
                    pos = j;
                }
            }
        }
        visited[pos] = 1;
        total += min;
        head = req[pos];

        printf(" -> %d", head);
    }
    printf("\n\nTotal head movement = %d\n", total);
    return 0;
}