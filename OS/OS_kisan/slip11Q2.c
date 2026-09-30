#include <stdio.h>

void optimal(int pages[], int n, int frames)
{
    int frame[20];
    int i, j, k;
    int pageFaults = 0;
    int found, pos, farthest;

    for(i = 0; i < frames; i++)
        frame[i] = -1;

    printf("\nPage\tFrames\t\tStatus\n");

    for(i = 0; i < n; i++)
    {
        found = 0;

        /* Check if page is already present */
        for(j = 0; j < frames; j++)
        {
            if(frame[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if(found == 0)
        {
            pageFaults++;

            /* Find empty frame */
            pos = -1;

            for(j = 0; j < frames; j++)
            {
                if(frame[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            /* If no empty frame, find page used farthest in future */
            if(pos == -1)
            {
                farthest = -1;

                for(j = 0; j < frames; j++)
                {
                    int next = 9999;

                    for(k = i + 1; k < n; k++)
                    {
                        if(frame[j] == pages[k])
                        {
                            next = k;
                            break;
                        }
                    }

                    if(next > farthest)
                    {
                        farthest = next;
                        pos = j;
                    }
                }
            }

            frame[pos] = pages[i];
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

    optimal(pages, n, frames);

    return 0;
}