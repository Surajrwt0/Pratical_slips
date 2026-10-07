#include <stdio.h>

int main()
{
    int ref[] = {3,5,7,2,5,1,2,3,1,3,5,3,1,6,2};
    int frames, page[10], count[10] = {0};
    int n = 15, i, j, k, pos, time = 0, faults = 0;
    int hit;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for (i = 0; i < frames; i++)
        page[i] = -1;

    printf("\nPage\tFrames\t\tStatus\n");

    for (i = 0; i < n; i++)
    {
        time++;
        hit = 0;
        pos = -1;

        /* Check page */
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
            count[pos] = time;
        }
        else
        {
            faults++;

            /* Empty frame */
            for (j = 0; j < frames; j++)
            {
                if (page[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            /* LRU page */
            if (pos == -1)
            {
                pos = 0;

                for (j = 1; j < frames; j++)
                    if (count[j] < count[pos])
                        pos = j;
            }

            page[pos] = ref[i];
            count[pos] = time;
        }

        printf("%d\t", ref[i]);

        for (k = 0; k < frames; k++)
            printf("%d ", page[k]);

        printf("\t%s\n", hit ? "Hit" : "Fault");
    }

    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}