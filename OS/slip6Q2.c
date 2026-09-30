#include <stdio.h>
#include <stdlib.h>

void cscan(int request[], int n, int head, int total)
{
    int i, j, temp;
    int movement = 0;

    /* Sort requests */
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(request[i] > request[j])
            {
                temp = request[i];
                request[i] = request[j];
                request[j] = temp;
            }
        }
    }

    printf("\nRequest Order:\n");
    printf("%d", head);

    /* Move right */
    for(i = 0; i < n; i++)
    {
        if(request[i] >= head)
        {
            movement += abs(request[i] - head);
            head = request[i];

            printf(" -> %d", head);
        }
    }

    /* Move to last block */
    if(head != total - 1)
    {
        movement += (total - 1) - head;
        head = total - 1;

        printf(" -> %d", head);
    }

    /* Jump to first block */
    movement += total - 1;
    head = 0;

    printf(" -> %d", head);

    /* Continue from beginning */
    for(i = 0; i < n; i++)
    {
        if(request[i] < head)
        {
            movement += abs(request[i] - head);
            head = request[i];

            printf(" -> %d", head);
        }
    }

    printf("\nTotal Head Movement = %d\n", movement);
}

int main()
{
    int total, n, i, head;
    int request[100];

    printf("Enter total number of disk blocks: ");
    scanf("%d", &total);

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter disk request string:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter current head position: ");
    scanf("%d", &head);

    cscan(request, n, head, total);

    return 0;
}