#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, i, t = 0, done = 0, p;
    int at[20], bt1[20], bt2[20], bt[20], rem[20], pri[20];
    int ct[20], tat[20], wt[20];
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    srand(time(0));

    for (i = 0; i < n; i++)
    {
        printf("\nP%d Arrival Time: ", i + 1);
        scanf("%d", &at[i]);

        printf("P%d First CPU Burst: ", i + 1);
        scanf("%d", &bt1[i]);

        printf("P%d Priority: ", i + 1);
        scanf("%d", &pri[i]);

        bt2[i] = rand() % 10 + 1;
        bt[i] = bt1[i] + bt2[i];
        rem[i] = bt[i];
    }

    printf("\nGantt Chart:\n");

    while (done < n)
    {
        p = -1;

        for (i = 0; i < n; i++)
            if (at[i] <= t && rem[i] > 0 &&
                (p == -1 || pri[i] < pri[p]))
                p = i;

        if (p == -1)
        {
            t++;
            continue;
        }

        printf("| P%d ", p + 1);

        rem[p]--;
        t++;

        if (rem[p] == 0)
        {
            ct[p] = t;
            done++;
        }
    }

    printf("|\n");

    printf("\nProcess\tAT\tBT1\tBT2\tPri\tCT\tTAT\tWT\n");

    for (i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        awt += wt[i];
        atat += tat[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt1[i], bt2[i],
               pri[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f", awt / n);
    printf("\nAverage Turnaround Time = %.2f\n", atat / n);

    return 0;
}