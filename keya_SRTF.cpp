#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int pid[20], at[20], bt[20], rt[20], ct[20], tat[20], wt[20];
    int completed = 0, t = 0;
    float avg_tat = 0, avg_wt = 0;


    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cout << "Enter Arrival Time of P" << i + 1 << ": ";
        cin >> at[i];
        cout << "Enter Burst Time of P" << i + 1 << ": ";
        cin >> bt[i];
        rt[i] = bt[i];
    }


    while (completed != n) {
        int shortest = -1;
        int min_rt = 1e9;


        for (int i = 0; i < n; i++) {
            if (at[i] <= t && rt[i] > 0 && rt[i] < min_rt) {
                min_rt = rt[i];
                shortest = i;
            }
        }

        if (shortest == -1) {
            t++;
            continue;
        }

        rt[shortest]--;
        t++;

        if (rt[shortest] == 0) {
            completed++;
            ct[shortest] = t;
            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];
            avg_tat += tat[shortest];
            avg_wt += wt[shortest];
        }
    }


    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << pid[i] << "\t" << at[i] << "\t" << bt[i] << "\t"
             << ct[i] << "\t" << tat[i] << "\t" << wt[i] << endl;
    }

    cout << "\nAverage Turnaround Time = " << avg_tat / n;
    cout << "\nAverage Waiting Time = " << avg_wt / n << endl;

    return 0;
}

