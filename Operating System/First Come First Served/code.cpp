#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    int total_waiting_time = 0, total_turnaround_time = 0;

    cout << "\nEnter the Burst Time for each process\n";
    for (int i = 0; i < n; i++)
    {
        processes[i].id = i + 1;
        cout << "Process " << i + 1 << ": ";
        cin >> processes[i].burst_time;
    }

    processes[0].waiting_time = 0;
    processes[0].turnaround_time = processes[0].burst_time;
    total_turnaround_time = processes[0].turnaround_time;

    for (int i = 1; i < n; i++)
    {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;

        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time";
    for (const auto &p : processes)
    {
        cout << "\nP[" << p.id << "]\t"
             << p.burst_time << "\t\t"
             << p.waiting_time << "\t\t"
             << p.turnaround_time;
    }

    float average_waiting_time = (float)total_waiting_time / n;
    float average_turnaround_time = (float)total_turnaround_time / n;

    cout << "\n\nAverage Waiting Time: " << average_waiting_time;
    cout << "\nAverage Turnaround Time: " << average_turnaround_time << endl;

    return 0;
}