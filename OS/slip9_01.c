#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, i;
    int at[10], bt1[10], bt2[10], bt[10];
    int rem[10], ct[10], tat[10], wt[10];
    int pid[10];

    int quantum;
    int currentTime = 0;
    int completed = 0;

    float avgwt = 0, avgtat = 0;

    srand(time(NULL));

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    for(i = 0; i < n; i++)
    {
        pid[i] = i + 1;

        printf("\nProcess %d\n", i + 1);

        printf("Arrival Time: ");
        scanf("%d", &at[i]);

        printf("First CPU Burst: ");
        scanf("%d", &bt1[i]);

        bt2[i] = rand() % 5 + 1;

        bt[i] = bt1[i] + bt2[i];

        rem[i] = bt[i];
    }

    printf("\nRandom Second CPU Bursts:\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d = %d\n", pid[i], bt2[i]);
    }

    printf("\nGantt Chart\n");

    while(completed < n)
    {
        int found = 0;

        for(i = 0; i < n; i++)
        {
            if(rem[i] > 0 && at[i] <= currentTime)
            {
                found = 1;

                printf("| P%d ", pid[i]);

                if(rem[i] <= quantum)
                {
                    currentTime = currentTime + rem[i];

                    rem[i] = 0;

                    ct[i] = currentTime;

                    tat[i] = ct[i] - at[i];

                    wt[i] = tat[i] - bt[i];

                    completed++;
                }
                else
                {
                    currentTime = currentTime + quantum;

                    rem[i] = rem[i] - quantum;
                }
            }
        }

        if(found == 0)
        {
            currentTime++;
        }
    }

    printf("|\n");

    printf("\nProcess\tAT\tCPU1\tCPU2\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i],
               at[i],
               bt1[i],
               bt2[i],
               bt[i],
               ct[i],
               tat[i],
               wt[i]);

        avgwt = avgwt + wt[i];
        avgtat = avgtat + tat[i];
    }

    avgwt = avgwt / n;
    avgtat = avgtat / n;

    printf("\nAverage Waiting Time = %.2f", avgwt);
    printf("\nAverage Turnaround Time = %.2f\n", avgtat);

    return 0;
}