#include <stdio.h>

int main()
{
    int ref[] = {3,5,7,2,5,1,2,3,1,3,5,3,1,6,2};
    int n = 15, frames, i, j, k;
    int page[10], counter[10] = {0};
    int time = 0, fault = 0, pos;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for (i = 0; i < frames; i++)
        page[i] = -1;

    printf("\nPage\tFrames\t\tStatus\n");

    for (i = 0; i < n; i++)
    {
        time++;
        pos = -1;

        // Check if page is already present
        for (j = 0; j < frames; j++)
        {
            if (page[j] == ref[i])
            {
                pos = j;
                break;
            }
        }

        if (pos != -1)
        {
            // Page hit
            counter[pos] = time;
            printf("%d\t", ref[i]);

            for (k = 0; k < frames; k++)
                printf("%d ", page[k]);

            printf("\tHit\n");
        }
        else
        {
            // Page fault
            fault++;

            // Find empty frame
            pos = -1;
            for (j = 0; j < frames; j++)
            {
                if (page[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            // If no empty frame, find least recently used page
            if (pos == -1)
            {
                pos = 0;

                for (j = 1; j < frames; j++)
                {
                    if (counter[j] < counter[pos])
                        pos = j;
                }
            }

            page[pos] = ref[i];
            counter[pos] = time;

            printf("%d\t", ref[i]);

            for (k = 0; k < frames; k++)
                printf("%d ", page[k]);

            printf("\tFault\n");
        }
    }

    printf("\nTotal Page Faults = %d\n", fault);

    return 0;
}