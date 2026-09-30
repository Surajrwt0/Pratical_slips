#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Process
{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int done;
};

void sjf(struct Process p[], int n)
{
    int completed = 0;
    int time = 0;
    int i, index;
    float avgTAT = 0, avgWT = 0;

    printf("\nGantt Chart:\n");

    while(completed < n)
    {
        index = -1;

        /* Find shortest burst among arrived processes */
        for(i = 0; i < n; i++)
        {
            if(p[i].done == 0 && p[i].at <= time)
            {
                if(index == -1 || p[i].bt < p[index].bt)
                    index = i;
            }
        }

        /* If no process has arrived */
        if(index == -1)
        {
            time++;
            continue;
        }

        printf("| P%d ", p[index].pid);

        time += p[index].bt;

        p[index].ct = time;
        p[index].tat = p[index].ct - p[index].at;
        p[index].wt = p[index].tat - p[index].bt;

        p[index].done = 1;
        completed++;

        avgTAT += p[index].tat;
        avgWT += p[index].wt;
    }

    printf("|\n");

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].at,
               p[i].bt,
               p[i].ct,
               p[i].tat,
               p[i].wt);
    }

    printf("\nAverage Turnaround Time = %.2f",
           avgTAT / n);

    printf("\nAverage Waiting Time = %.2f\n",
           avgWT / n);
}

int main()
{
    struct Process p[20];
    int n, i;

    srand(time(0));

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        p[i].done = 0;

        printf("\nEnter Arrival Time of P%d: ", i + 1);
        scanf("%d", &p[i].at);

        printf("Enter First CPU Burst of P%d: ", i + 1);
        scanf("%d", &p[i].bt);

        /* Generate next CPU burst randomly */
        p[i].bt = rand() % 10 + 1;
    }

    sjf(p, n);

    return 0;
}