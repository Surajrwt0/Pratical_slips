#include <stdio.h>

int main()
{
    int pid[20], at[20], bt[20];
    int remaining[20], ct[20], tat[20], wt[20];

    int n, quantum;
    int time = 0;
    int completed = 0;
    int i, found;

    float avgTAT = 0, avgWT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    /* Accept process details */
    for(i = 0; i < n; i++)
    {
        pid[i] = i + 1;

        printf("\nEnter Arrival Time of P%d: ", i + 1);
        scanf("%d", &at[i]);

        printf("Enter CPU Burst of P%d: ", i + 1);
        scanf("%d", &bt[i]);

        remaining[i] = bt[i];
    }

    /* Round Robin */
    printf("\nGantt Chart:\n");

    while(completed < n)
    {
        found = 0;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && remaining[i] > 0)
            {
                found = 1;

                printf("| P%d ", pid[i]);

                if(remaining[i] > quantum)
                {
                    time = time + quantum;
                    remaining[i] = remaining[i] - quantum;
                }
                else
                {
                    time = time + remaining[i];
                    remaining[i] = 0;

                    ct[i] = time;

                    tat[i] = ct[i] - at[i];

                    wt[i] = tat[i] - bt[i];

                    avgTAT = avgTAT + tat[i];
                    avgWT = avgWT + wt[i];

                    completed++;
                }
            }
        }

        if(found == 0)
        {
            time++;
        }
    }

    printf("|\n");

    /* Display results */
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",pid[i],at[i],bt[i],
        ct[i],tat[i],wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f",avgTAT / n);

    printf("\nAverage Waiting Time = %.2f\n",avgWT / n);

    return 0;
}