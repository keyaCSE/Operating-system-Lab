#include <stdio.h>
void findWaitingTime(int n, int bt[], int wt[]) {
wt[0] = 0;
for (int i = 1; i < n; i++) {
wt[i] = bt[i-1] + wt[i-1];
}
}

void findTurnaroundTime (int n, int bt[], int wt[], int tat[]) {
for (int i = 0; i < n; i++) {
tat[i] = bt[i] + wt[i];
}
}

void findAverageTime (int n, int bt[]) {
int wt[n], tat[n];
int total_wt = 0, total_tat = 0;
findWaitingTime (n, bt, wt);
findTurnaroundTime (n, bt, wt, tat);
printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

for (int i=0; i < n; i++) {
    total_wt += wt[i];
total_tat += tat[i];

printf("P%d\t%d\t\t%d\t\t%d\n", i+1, bt[i], wt[i], tat[i]);}

printf("Average Waiting Time = %.2f\n", (float)total_wt / n);
 printf("Average Turnaround Time=%.2f\n", (float) total_tat / n);

}
void sortProcessesByBurstTime(int n, int bt[]) {
int temp;

for (int i = 0; i < n-1; i++) {
for (int j = 0; j < n-i-1; j++) {
if (bt[j] > bt [j+1]) {

temp = bt[j];
bt[j] = bt[j+1];
bt[j+1] = temp;
}
}
}
}



int main() {
int n;
printf("Enter number of processes: ");
scanf("%d", &n);
int burst_time[n];
printf("Enter burst times for each process: \n");
for (int i = 0; i < n; i++) {
    printf("P%d: ", i+1);
scanf("%d", &burst_time[i]);
}

sortProcessesByBurst Time (n, burst_time);
findAverageTime (n, burst_time);
return 0;
}











