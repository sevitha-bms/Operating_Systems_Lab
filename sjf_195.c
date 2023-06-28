#include <stdio.h>

struct Process {
    int pid;  // Process ID
    int bt;   // Burst Time
    int at;   // Arrival Time
};

void findAvgTime(struct Process proc[], int n) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Sort the processes based on arrival time and burst time (Shortest Job First)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (proc[j].at > proc[j + 1].at || (proc[j].at == proc[j + 1].at && proc[j].bt > proc[j + 1].bt)) {
                struct Process temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }

    // Calculate waiting time and turnaround time
    int completion_time = proc[0].at + proc[0].bt;
    wt[0] = 0;  // Waiting time for the first process is 0
    tat[0] = proc[0].bt;  // Turnaround time for the first process is its burst time
    total_wt += wt[0];
    total_tat += tat[0];

    for (int i = 1; i < n; i++) {
        if (completion_time < proc[i].at) {
            completion_time = proc[i].at;
        }
        wt[i] = completion_time - proc[i].at;
        tat[i] = wt[i] + proc[i].bt;
        completion_time += proc[i].bt;
        total_wt += wt[i];
        total_tat += tat[i];
    }

    // Display processes along with all details
    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].bt, proc[i].at, wt[i], tat[i]);
    }

    // Calculate and display average waiting time and average turnaround time
    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;
    printf("\nAverage waiting time: %.2f", avg_wt);
    printf("\nAverage turnaround time: %.2f", avg_tat);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time for Process %d: ", i + 1);
        scanf("%d", &proc[i].at);
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &proc[i].bt);
        proc[i].pid = i + 1;
    }

    // Perform SJF scheduling algorithm
    findAvgTime(proc, n);

    return 0;
}

