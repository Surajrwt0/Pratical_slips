// sahi hai bhai
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, r;
    int req[50];
    int head;
    int i, j, temp;
    int totalMovement = 0;

    printf("Enter total number of disk blocks: ");
    scanf("%d", &n);

    printf("Enter number of disk requests: ");
    scanf("%d", &r);

    printf("Enter disk request string:\n");
    for (i = 0; i < r; i++)
    {
        scanf("%d", &req[i]);
    }

    printf("Enter current head position: ");
    scanf("%d", &head);

    /* Sort requests */
    for (i = 0; i < r - 1; i++)
    {
        for (j = i + 1; j < r; j++)
        {
            if (req[i] > req[j])
            {
                temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }

    printf("\nOrder of requests served:\n");
    printf("%d", head);

    /* Direction = LEFT */

    /* Serve all requests smaller than initial head */
    for (i = r - 1; i >= 0; i--)
    {
        if (req[i] < head)
        {
            totalMovement += abs(head - req[i]);
            head = req[i];

            printf(" -> %d", head);
        }
    }

    /*
       Now reverse direction.
       Only requests greater than the ORIGINAL head
       are remaining, so serve them from smallest to largest.
    */

    for (i = 0; i < r; i++)
    {
        if (req[i] > 100)
        {
            totalMovement += abs(head - req[i]);
            head = req[i];

            printf(" -> %d", head);
        }
    }

    printf("\n\nTotal head movement = %d\n", totalMovement);

    return 0;
}