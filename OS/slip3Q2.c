#include <stdio.h>
#include <stdlib.h>

void sstf(int request[], int n, int head)
{
    int visited[100] = {0};
    int i, j, pos, distance;
    int movement = 0;

    printf("\nRequest Order:\n");
    printf("%d", head);

    for(i = 0; i < n; i++)
    {
        distance = 9999;
        pos = -1;

        for(j = 0; j < n; j++)
        {
            if(visited[j] == 0)
            {
                if(abs(request[j] - head) < distance)
                {
                    distance = abs(request[j] - head);
                    pos = j;
                }
            }
        }

        visited[pos] = 1;
        movement += distance;
        head = request[pos];

        printf(" -> %d", head);
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

    sstf(request, n, head);

    return 0;
}