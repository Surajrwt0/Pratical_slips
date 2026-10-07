#include <stdio.h>

int main()
{
    int ref[] = {8,5,7,8,5,7,2,3,7,3,5,9,4,6,2};
    int n = 15, frames;
    int page[10], freq[10] = {0};
    int i, j, k, pos, faults = 0;
    int hit;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for (i = 0; i < frames; i++)
        page[i] = -1;

    printf("\nPage\tFrames\t\tStatus\n");

    for (i = 0; i < n; i++)
    {
        hit = 0;
        pos = -1;

        /* Check page hit */
        for (j = 0; j < frames; j++)
        {
            if (page[j] == ref[i])
            {
                hit = 1;
                pos = j;
                break;
            }
        }

        if (hit)
        {
            freq[pos]++;
        }
        else
        {
            faults++;

            /* Find empty frame */
            for (j = 0; j < frames; j++)
            {
                if (page[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            /* Find MFU page */
            if (pos == -1)
            {
                pos = 0;

                for (j = 1; j < frames; j++)
                {
                    if (freq[j] > freq[pos])
                        pos = j;
                }
            }

            page[pos] = ref[i];
            freq[pos] = 1;
        }

        printf("%d\t", ref[i]);

        for (k = 0; k < frames; k++)
            printf("%d ", page[k]);

        printf("\t%s\n", hit ? "Hit" : "Fault");
    }

    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}