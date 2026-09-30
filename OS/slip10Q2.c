#include <stdio.h>
#include <stdlib.h>

void look(int request[], int n, int head, char direction)
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
        /* Move left */
        for(i = n - 1; i >= 0; i--)
        {
            if(request[i] < head)
            {
                movement += abs(head - request[i]);
                head = request[i];

                printf(" -> %d", head);
            }
        }

        /* Then move right */
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
        /* Move right */
        for(i = 0; i < n; i++)
        {
            if(request[i] > head)
            {
                movement += abs(head - request[i]);
                head = request[i];

                printf(" -> %d", head);
            }
        }

        /* Then move left */
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

    look(request, n, head, direction);

    return 0;
}