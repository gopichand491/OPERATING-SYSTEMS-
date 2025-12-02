#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int burst[n], waiting[n], turnaround[n];

    cout << "Enter burst times:\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i << ": ";
        cin >> burst[i];
    }

    waiting[0] = 0;
    for (int i = 1; i < n; i++) {
        waiting[i] = waiting[i-1] + burst[i-1];
    }

    for (int i = 0; i < n; i++) {
        turnaround[i] = waiting[i] + burst[i];
    }

    cout << "\nProcess\tBurst\tWaiting\tTurnaround\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i << "\t" << burst[i] << "\t"
             << waiting[i] << "\t" << turnaround[i] << endl;
    }

    return 0;
}

