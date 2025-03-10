#include <bits/stdc++.h>
using namespace std;

struct Process
{
    string id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;

    vector<Process> processes(n);

    for (int i = 0; i < n; i++)
        cin >> processes[i].id >> processes[i].burst_time;

    sort(processes.begin(), processes.end(),
         [](const Process &a, const Process &b)
         {
             return a.burst_time < b.burst_time;
         });

    processes[0].waiting_time = 0;
    processes[0].turnaround_time = processes[0].burst_time;

    float total_waiting_time = 0;
    float total_turnaround_time = processes[0].turnaround_time;
    string gantt_chart = processes[0].id;

    for (int i = 1; i < n; i++)
    {
        processes[i].waiting_time = processes[i-1].waiting_time + processes[i-1].burst_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        
        gantt_chart += " -> " + processes[i].id;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    sort(processes.begin(), processes.end(),
         [](const Process &a, const Process &b)
         {
             return a.id < b.id;
         });

    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time" << endl;
    for (const auto &p : processes)
    {
        cout << "P[" << p.id << "]\t"
             << p.burst_time << "\t\t"
             << p.waiting_time << "\t\t"
             << p.turnaround_time << endl;
    }

    cout << endl << endl << "Gantt Chart:" << endl;
    cout << gantt_chart << endl;

    float average_waiting_time = total_waiting_time / n;
    float average_turnaround_time = total_turnaround_time / n;

    cout << "\nAverage Waiting Time: " << average_waiting_time;
    cout << "\nAverage Turnaround Time: " << average_turnaround_time << endl;

    return 0;
}