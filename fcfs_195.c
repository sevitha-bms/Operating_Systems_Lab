#include<stdio.h>
#include<stdlib.h>
int proc[10],burst_time[10],arrival[10],tat[10],n; double avg,avg1; int t,total_tat;

void main()
{
printf("\n Enter the size of n:");
scanf("%d",&n);
for(int i=0;i<n;i++)
{
printf("\n Enter the processor number:");
scanf("%d",&proc[i]);
printf("\n Enter the burst time and arrival time :");
scanf("%d%d",&burst_time[i],&arrival[i]);
}//for loop
t=burst_time[0]-arrival[0];//t is completion time for P1 t=3
avgtime(proc,n,burst_time,arrival);
}//main


void avgtime(int proc[],int n,int burst_time[],int arrival[])
{
int wait_time[n],tat[n],total_wt=0;
waitingtime(proc,n,burst_time,wait_time,arrival);

for(int i=0;i<n;i++)
{
total_wt+=wait_time[i];
}
avg=(double)total_wt/n;
avg1=(double)total_tat/n;
printf("\n Average wait time:%lf \n Average TAT:%lf",avg,avg1);
}//average wait time

void waitingtime(int proc[],int n,int burst_time[],int wait_time[],int arrival[])
{
wait_time[0]=0; int temp;
for(int i=1;i<=n;i++)
{
    temp=wait_time[i-1]+arrival[i-1];
wait_time[i]=(burst_time[i-1]+temp)-arrival[i];
printf("wait time for %d is %d \n",i,wait_time[i-1]);

}//for loop for wait

for(int i=0;i<n;i++)
{
tat[i]=t-arrival[i];
total_tat+=tat[i];
t=t+burst_time[i+1];
}//for loop for tat
for(int j=0;j<n;j++)
printf("TAT for %d is %d \n",j+1 ,tat[j]);
}



