#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, r;
    int req[50];
    int head, originalHead;
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

    originalHead = head;

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

    /* Direction = RIGHT */

    /* Serve all requests greater than initial head */
    for (i = 0; i < r; i++)
    {
        if (req[i] > originalHead)
        {
            totalMovement += abs(head - req[i]);
            head = req[i];

            printf(" -> %d", head);
        }
    }

    /*
       Now reverse direction.
       Only requests smaller than the ORIGINAL head
       are remaining, so serve them from largest to smallest.
    */

    for (i = r - 1; i >= 0; i--)
    {
        if (req[i] < originalHead)
        {
            totalMovement += abs(head - req[i]);
            head = req[i];

            printf(" -> %d", head);
        }
    }

    printf("\n\nTotal head movement = %d\n", totalMovement);

    return 0;
}