#include <stdio.h>
#include <stdlib.h>

void scan(int request[], int n, int head, int total, char direction)
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

    if(direction == 'L' || direction == 'l')
    {
        /* Move towards left */
        for(i = n - 1; i >= 0; i--)
        {
            if(request[i] < head)
            {
                movement += abs(head - request[i]);
                head = request[i];

                printf(" -> %d", head);
            }
        }

        /* Go to beginning of disk */
        if(head != 0)
        {
            movement += head;
            head = 0;
            printf(" -> %d", head);
        }

        /* Move towards right */
        for(i = 0; i < n; i++)
        {
            if(request[i] > head)
            {
                movement += abs(head - request[i]);
                head = request[i];

                printf(" -> %d", head);
            }
        }
    }
    else
    {
        /* Move towards right */
        for(i = 0; i < n; i++)
        {
            if(request[i] > head)
            {
                movement += abs(head - request[i]);
                head = request[i];

                printf(" -> %d", head);
            }
        }

        /* Go to end of disk */
        if(head != total - 1)
        {
            movement += (total - 1) - head;
            head = total - 1;
            printf(" -> %d", head);
        }

        /* Move towards left */
        for(i = n - 1; i >= 0; i--)
        {
            if(request[i] < head)
            {
                movement += abs(head - request[i]);
                head = request[i];

                printf(" -> %d", head);
            }
        }
    }

    printf("\nTotal Head Movement = %d\n", movement);
}

int main()
{
    int total, n, i, head;
    char direction;
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

    printf("Enter direction (L/R): ");
    scanf(" %c", &direction);

    scan(request, n, head, total, direction);

    return 0;
}