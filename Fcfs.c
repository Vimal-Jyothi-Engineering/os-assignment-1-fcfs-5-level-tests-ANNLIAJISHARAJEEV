#include <stdio.h>
#include <string.h>

typedef struct {
    char pid[10];
    int arrival;
    int burst;
    int waiting;
    int turnaround;
} Process;

int main() {
    int n;
    scanf("%d", &n);

    Process p[n];

    // Input
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", p[i].pid, &p[i].arrival, &p[i].burst);
    }

    // Sort by arrival time (Bubble Sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].arrival > p[j + 1].arrival) {
                Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    int currentTime = 0;
    float totalWaiting = 0, totalTurnaround = 0;

    // Calculate waiting time and turnaround time
    for (int i = 0; i < n; i++) {

        if (currentTime < p[i].arrival)
            currentTime = p[i].arrival;

        p[i].waiting = currentTime - p[i].arrival;
        p[i].turnaround = p[i].waiting + p[i].burst;

        currentTime += p[i].burst;

        totalWaiting += p[i].waiting;
        totalTurnaround += p[i].turnaround;
    }

    // Output
    printf("\nPID\tArrival\tBurst\tWaiting\tTurnaround\n");

    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrival,
               p[i].burst,
               p[i].waiting,
               p[i].turnaround);
    }

    printf("\nAverage Waiting Time = %.2f", totalWaiting / n);
    printf("\nAverage Turnaround Time = %.2f\n", totalTurnaround / n);

    return 0;
}
