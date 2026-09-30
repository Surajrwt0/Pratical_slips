#include <stdio.h>

void fifo(int pages[], int n, int frames)
{
    int frame[20];
    int i, j;
    int pointer = 0;
    int pageFaults = 0;
    int found;

    for(i = 0; i < frames; i++)
        frame[i] = -1;

    printf("\nPage\tFrames\t\tStatus\n");

    for(i = 0; i < n; i++)
    {
        found = 0;

        /* Check whether page is already present */
        for(j = 0; j < frames; j++)
        {
            if(frame[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        /* Page fault */
        if(found == 0)
        {
            frame[pointer] = pages[i];
            pointer = (pointer + 1) % frames;
            pageFaults++;
        }

        printf("%d\t", pages[i]);

        for(j = 0; j < frames; j++)
        {
            if(frame[j] == -1)
                printf("- ");
            else
                printf("%d ", frame[j]);
        }

        if(found == 0)
            printf("\tPage Fault");
        else
            printf("\tHit");

        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);
}

int main()
{
    int n, frames, i;
    int pages[100];

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter reference string:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    fifo(pages, n, frames);

    return 0;
}