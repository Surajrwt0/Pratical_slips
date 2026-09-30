#include <stdio.h>

int main()
{
    int pid[20], at[20], bt[20];
    int ct[20], tat[20], wt[20];
    int done[20];

    int n, i, time = 0;
    int completed = 0;
    int index;

    float avgTAT = 0, avgWT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    /* Accept process details */
    for(i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        done[i] = 0;

        printf("\nEnter Arrival Time of P%d: ", i + 1);
        scanf("%d", &at[i]);

        printf("Enter CPU Burst of P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    /* SJF Non-Preemptive */
    printf("\nGantt Chart:\n");

    while(completed < n)
    {
        index = -1;

        /* Find shortest burst among arrived processes */
        for(i = 0; i < n; i++)
        {
            if(done[i] == 0 && at[i] <= time)
            {
                if(index == -1 || bt[i] < bt[index])
                {
                    index = i;
                }
            }
        }

        /* If no process has arrived */
        if(index == -1)
        {
            time++;
            continue;
        }

        printf("| P%d ", pid[index]);

        time = time + bt[index];

        ct[index] = time;

        tat[index] = ct[index] - at[index];

        wt[index] = tat[index] - bt[index];

        done[index] = 1;

        completed++;

        avgTAT = avgTAT + tat[index];
        avgWT = avgWT + wt[index];
    }

    printf("|\n");

    /* Display results */
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f",avgTAT / n);

    printf("\nAverage Waiting Time = %.2f\n",avgWT / n);

    return 0;
}