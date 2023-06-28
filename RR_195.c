#include<stdio.h>

void main(){
    int n, proc[100], burst_time[100], wait_time[100], tq, i, burst_update[100], t=0, turnaround[100], c, tot_wt=0, tot_tt=0;

    printf("Enter the number of process: ");
    scanf("%d", &n);
    c = n;
    printf("Enter the Time Quantum: ");
    scanf("%d", &tq);

    printf("Enter the burst times!\n");
    for(i=0; i<n; i++){
        proc[i] = i+1;
        printf("Enter the burst time of process %d: ");
        scanf("%d", &burst_time[i]);
        burst_update[i] = burst_time[i];
    }
    i = 0;
    while(c!=0){
        if(proc[i]!=0){
            if(burst_update[i]>tq){
                burst_update[i] -= tq;
                t += tq;

            }
            else{
                t += burst_update[i];
                burst_update[i] = 0;
                proc[i] = 0;
                turnaround[i] = t;
                c--;
                wait_time[i] = turnaround[i] - burst_time[i];
            }
        }
        i = (i+1)%n;
    }

    for(i=0; i<n; i++){
        tot_tt += turnaround[i];
        tot_wt += wait_time[i];
    }

    printf("\n\nProcess\t\tBurst Time\t\tWait Time\t\tTurnaround Time\n");
    for(i=0; i<n; i++)
        printf("%d\t\t%d\t\t\t%d\t\t\t%d\n",i+1, burst_time[i], wait_time[i], turnaround[i]);

    printf("\n\nAverage Turn Around time is: %d\n", tot_tt/n);
    printf("Average Waiting Time is: %d\n", tot_wt/n);
}
