// SAhi code hai bhai
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int n, i, j;
    int at[10], bt1[10], bt2[10], total[10];
    int ct[10], wt[10], tat[10];
    int currentTime = 0;
    float avgwt = 0, avgtat = 0;
    srand(time(NULL));
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("\nProcess %d\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("First CPU Burst: ");
        scanf("%d", &bt1[i]);
        bt2[i] = rand() % 5 + 1;     // Random CPU Burst
        total[i] = bt1[i] + bt2[i];
    }
    int pid[10];
    for(i = 0; i < n; i++) {
    pid[i] = i + 1;   
}

    printf("before sorting \n");
    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt1[i], bt2[i],total[i]);
               }
    // Sort according to Total Burst Time (SJF)
    printf("after sorting \n");
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(total[i] > total[j])
            {
                int temp;
                temp = total[i];
                total[i] = total[j];
                total[j] = temp;
                
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                
                temp = bt1[i];
                bt1[i] = bt1[j];
                bt1[j] = temp;

                temp = bt2[i];
                bt2[i] = bt2[j];
                bt2[j] = temp;
                
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;

            }
        }
    }
    if(at[0] > 0)
        currentTime = at[0];
    currentTime = currentTime + total[0];
    ct[0] = currentTime;
    tat[0] = ct[0] - at[0];
    wt[0] = tat[0] - total[0];
    for(i = 1; i < n; i++)
    {
        if(currentTime < at[i])
            currentTime = at[i];
        currentTime = currentTime + total[i];
        ct[i] = currentTime;
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - total[i];
    }
    printf("\nGantt Chart\n|");
    for(i = 0; i < n; i++)
    {
        printf(" P%d |", pid[i]);
    }
    printf("\n");
    printf("\nProcess\tAT\tCPU1\tCPU2\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt1[i], bt2[i], ct[i],tat[i], wt[i]);

        avgwt += wt[i];
        avgtat += tat[i];
    }
    avgwt = avgwt / n;
    avgtat = avgtat / n;
    printf("\nAverage Waiting Time = %.2f", avgwt);
    printf("\nAverage Turnaround Time = %.2f\n", avgtat);
    return 0;
}