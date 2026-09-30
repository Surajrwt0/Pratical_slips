#include <stdio.h>
#include <stdlib.h>

void fcfs(int request[], int n, int head)
{
    int i, movement = 0;

    printf("\nRequest Order:\n");
    printf("%d", head);

    for(i = 0; i < n; i++)
    {
        movement += abs(request[i] - head);
        head = request[i];

        printf(" -> %d", request[i]);
    }

    printf("\n\nTotal Head Movement = %d", movement);
}

int main()
{
    int total, n, i, head;
    int request[100];

    printf("Enter total number of disk blocks: ");
    scanf("%d", &total);

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter disk request string:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter current head position: ");
    scanf("%d", &head);

    fcfs(request, n, head);

    return 0;
}