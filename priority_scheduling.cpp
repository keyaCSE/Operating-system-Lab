#include <iostream>
#include <vector>
using namespace std;

int main() {
    int no_of_process;
    cout << "Enter number of processes: ";
    cin >> no_of_process;

    vector<int> BT(no_of_process), P(no_of_process);
    vector<int> CT(no_of_process), TAT(no_of_process), WT(no_of_process);
    vector<bool> visited(no_of_process, false);

    cout << "Enter Burst Time and Priority for each process:\n";
    for (int i = 0; i < no_of_process; i++) {
        cin >> BT[i] >> P[i];
    }

    int timeStamp = 0;
    for (int i = 0; i < no_of_process; i++) {
        int current_highest = -1;


        for (int j = 0; j < no_of_process; j++) {
            if (!visited[j]) {
                if (current_highest == -1 || P[j] < P[current_highest]) {
                    current_highest = j;
                }
            }
        }

        visited[current_highest] = true;
        timeStamp += BT[current_highest];
        CT[current_highest] = timeStamp;
        TAT[current_highest] = CT[current_highest];
        WT[current_highest] = TAT[current_highest] - BT[current_highest];
    }

    cout << "\nProcess\tBT\tPriority\tCT\tTAT\tWT\n";
    for (int i = 0; i < no_of_process; i++) {
        cout << "P" << i + 1 << "\t"
             << BT[i] << "\t" << P[i] << "\t\t"
             << CT[i] << "\t" << TAT[i] << "\t" << WT[i] << endl;
    }

    float avgTAT = 0, avgWT = 0;
    for (int i = 0; i < no_of_process; i++) {
        avgTAT += TAT[i];
        avgWT += WT[i];
    }
    avgTAT /= no_of_process;
    avgWT /= no_of_process;

    cout << "\nAverage TAT = " << avgTAT;
    cout << "\nAverage WT  = " << avgWT << endl;

    return 0;
}
