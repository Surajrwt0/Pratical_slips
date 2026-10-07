// sahi hai bhai
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int n, i, j;
    int pid[20], at[20], bt1[20], bt2[20];
    int total_bt[20], ct[20], tat[20], wt[20];
    int currentTime = 0;
    float avgWT = 0, avgTAT = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    // Input Arrival Time and First CPU Burst
    for (i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        printf("\nEnter Arrival Time for P%d: ", pid[i]);
        scanf("%d", &at[i]);
        printf("Enter First CPU Burst for P%d: ", pid[i]);
        scanf("%d", &bt1[i]);
    }
    // Generate second CPU burst randomly
    srand(time(0));
    for (i = 0; i < n; i++)
    {
        bt2[i] = rand() % 10 + 1;   // Random burst from 1 to 10
        total_bt[i] = bt1[i] + bt2[i];
    }
    // Sort processes according to Arrival Time
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (at[i] > at[j])
            {
                int temp;
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
                temp = bt1[i];
                bt1[i] = bt1[j];
                bt1[j] = temp;
                temp = bt2[i];
                bt2[i] = bt2[j];
                bt2[j] = temp;
                temp = total_bt[i];
                total_bt[i] = total_bt[j];
                total_bt[j] = temp;
            }
        }
    }
    // FCFS Scheduling
    for (i = 0; i < n; i++)
    {
        // CPU remains idle if process has not arrived
        if (currentTime < at[i])
        {
            currentTime = at[i];
        }

        currentTime += total_bt[i];

        ct[i] = currentTime;

        tat[i] = ct[i] - at[i];

        wt[i] = tat[i] - total_bt[i];

        avgWT += wt[i];
        avgTAT += tat[i];
    }
    // Display process details
    printf("\n\nProcess\tAT\tBT1\tBT2\tTotal BT\tCT\tTAT\tWT");
    printf("\n-------------------------------------------------------------");
    for (i = 0; i < n; i++)
    {
        printf("\nP%d\t%d\t%d\t%d\t%d\t\t%d\t%d\t%d",
               pid[i], at[i], bt1[i], bt2[i],
               total_bt[i], ct[i], tat[i], wt[i]);
    }
    // Gantt Chart
    printf("\n\nGantt Chart:\n");
    for (i = 0; i < n; i++)
    {
        printf("   P%d   |", pid[i]);
    }
    avgWT = avgWT / n;
    avgTAT = avgTAT / n;
    printf("\n\nAverage Waiting Time = %.2f", avgWT);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT);
    return 0;
}