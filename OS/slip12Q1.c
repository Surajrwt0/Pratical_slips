#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, i, j;
    int pid[20], at[20], bt[20];
    int ct[20], tat[20], wt[20];
    int temp;

    float avgTAT = 0, avgWT = 0;

    srand(time(0));

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        pid[i] = i + 1;

        printf("\nEnter Arrival Time of P%d: ", pid[i]);
        scanf("%d", &at[i]);

        printf("Enter First CPU Burst of P%d: ", pid[i]);
        scanf("%d", &bt[i]);

        /* Generate next CPU burst randomly */
        bt[i] = rand() % 10 + 1;
    }

    /* Sort according to Arrival Time */
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(at[i] > at[j])
            {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    int time = 0;

    printf("\nGantt Chart:\n");

    for(i = 0; i < n; i++)
    {
        if(time < at[i])
            time = at[i];

        printf("| P%d ", pid[i]);

        time = time + bt[i];
        ct[i] = time;

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avgTAT = avgTAT + tat[i];
        avgWT = avgWT + wt[i];
    }

    printf("|\n");

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i], at[i], bt[i],
        ct[i], tat[i], wt[i]);
    }

    avgTAT = avgTAT / n;
    avgWT = avgWT / n;

    printf("\nAverage TAT = %.2f", avgTAT);
    printf("\nAverage WT  = %.2f\n", avgWT);

    return 0;
}