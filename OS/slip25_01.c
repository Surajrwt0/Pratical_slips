#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define IO_TIME 2
struct Process {
    int pid;
    int at;
    int burst;
    int rem;
    int ct;
    int tat;
    int wt;
    int done;
};
int main() {
    int n, tq, i, time = 0, completed = 0;
    struct Process p[20];
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);
    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("\nEnter Arrival Time of P%d: ", i + 1);
        scanf("%d", &p[i].at);
        printf("Enter First CPU Burst of P%d: ", i + 1);
        scanf("%d", &p[i].burst);
        p[i].rem = p[i].burst;
        p[i].done = 0;
    }
    printf("\n\nGantt Chart:\n");
    while (completed < n) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].rem > 0) {
                found = 1;
                printf("| P%d ", p[i].pid);
                if (p[i].rem > tq) {
                    time += tq;
                    p[i].rem -= tq;
                    /* Simulate I/O waiting */
                    time += IO_TIME;
                    /* Generate next CPU burst randomly */
                    if (p[i].rem > 0)
                        p[i].rem += rand() % 5 + 1;
                }
                else {
                    time += p[i].rem;
                    p[i].rem = 0;
                    p[i].ct = time;
                    p[i].tat = p[i].ct - p[i].at;
                    p[i].wt = p[i].tat - p[i].burst;
                    completed++;
                }
            }
        }
        if (!found)
            time++;
    }
    printf("|\n");
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    float avgwt = 0, avgtat = 0;
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].at,
               p[i].burst,
               p[i].ct,
               p[i].tat,
               p[i].wt);
        avgwt += p[i].wt;
        avgtat += p[i].tat;
    }
    printf("\nAverage Waiting Time = %.2f", avgwt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avgtat / n);
    return 0;
}