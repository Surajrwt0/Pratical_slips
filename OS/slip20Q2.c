#include <stdio.h>

int main()
{
    int frames[10], counter[10];
    int n, pages, i, j;
    int page, found, pos;
    int time = 0;
    int faults = 0;

    printf("Enter number of frames: ");
    scanf("%d", &n);

    printf("Enter number of pages: ");
    scanf("%d", &pages);

    for(i = 0; i < n; i++)
    {
        frames[i] = -1;
        counter[i] = 0;
    }

    printf("Enter reference string:\n");

    for(i = 0; i < pages; i++)
    {
        scanf("%d", &page);

        time++;
        found = 0;

        /* Check whether page is already present */
        for(j = 0; j < n; j++)
        {
            if(frames[j] == page)
            {
                found = 1;
                counter[j] = time;
                break;
            }
        }

        /* Page fault */
        if(found == 0)
        {
            faults++;

            /* Find empty frame */
            pos = -1;

            for(j = 0; j < n; j++)
            {
                if(frames[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            /* If no empty frame, find least recently used */
            if(pos == -1)
            {
                pos = 0;

                for(j = 1; j < n; j++)
                {
                    if(counter[j] < counter[pos])
                        pos = j;
                }
            }

            frames[pos] = page;
            counter[pos] = time;
        }

        printf("\nPage %d: ", page);

        for(j = 0; j < n; j++)
        {
            if(frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
        }

        if(found == 0)
            printf("  Page Fault");
        else
            printf("  Hit");
    }

    printf("\n\nTotal Page Faults = %d\n", faults);

    return 0;
}