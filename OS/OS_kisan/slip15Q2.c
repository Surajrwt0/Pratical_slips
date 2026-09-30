#include <stdio.h>

int main()
{
    int pid[20], at[20], bt[20], priority[20];
    int remaining[20], ct[20], tat[20], wt[20];

    int n, i;
    int time = 0, completed = 0;
    int current, highest;

    float avgTAT = 0, avgWT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    /* Accept process details */
    for(i = 0; i < n; i++)
    {
        pid[i] = i + 1;

        printf("\nEnter Arrival Time of P%d: ", i + 1);
        scanf("%d", &at[i]);

        printf("Enter CPU Burst of P%d: ", i + 1);
        scanf("%d", &bt[i]);

        printf("Enter Priority of P%d: ", i + 1);
        scanf("%d", &priority[i]);

        remaining[i] = bt[i];
        ct[i] = 0;
    }

    printf("\nGantt Chart:\n");

    while(completed < n)
    {
        highest = 9999;
        current = -1;

        /* Find highest-priority arrived process */
        for(i = 0; i < n; i++)
        {
            if(at[i] <= time &&
               remaining[i] > 0 &&
               priority[i] < highest)
            {
                highest = priority[i];
                current = i;
            }
        }

        /* If no process has arrived */
        if(current == -1)
        {
            time++;
            continue;
        }

        printf("| P%d ", pid[current]);

        /* Execute for one unit */
        remaining[current]--;
        time++;

        /* Process completed */
        if(remaining[current] == 0)
        {
            ct[current] = time;
            completed++;
        }
    }

    printf("|\n");

    /* Calculate TAT and WT */
    for(i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];

        wt[i] = tat[i] - bt[i];

        avgTAT = avgTAT + tat[i];
        avgWT = avgWT + wt[i];
    }

    /* Display result */
    printf("\nPID\tAT\tBT\tPriority\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n",
        pid[i],at[i],bt[i],priority[i],ct[i],tat[i],wt[i]);
    }

    printf("\nAverage TAT = %.2f", avgTAT / n);
    printf("\nAverage WT  = %.2f\n", avgWT / n);

    return 0;
}