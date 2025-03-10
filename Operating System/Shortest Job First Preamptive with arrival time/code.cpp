#include <bits/stdc++.h>
using namespace std;

struct Process 
{
    string id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
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
    {
        cin >> processes[i].id >> processes[i].arrival_time >> processes[i].burst_time;
        processes[i].remaining_time = processes[i].burst_time;
    }

    int completed = 0;
    int current_time = 0;
    vector<bool> is_completed(n, false);
    float total_waiting_time = 0;
    float total_turnaround_time = 0;
    
    string gantt_chart = "";
    int current_process = -1;
    
    sort(processes.begin(), processes.end(),
         [](const Process &a, const Process &b) {
             return a.arrival_time < b.arrival_time;
         });

    while (completed != n) 
    {
        int shortest_job = -1;
        int shortest_time = INT_MAX;

        for (int i = 0; i < n; i++) 
        {
            if (processes[i].arrival_time <= current_time && !is_completed[i]) 
            {
                if (processes[i].remaining_time < shortest_time) 
                {
                    shortest_time = processes[i].remaining_time;
                    shortest_job = i;
                }
            }
        }

        if (shortest_job == -1) 
        {
            current_time++;
            continue;
        }
        
        if (shortest_job != current_process) {
            if (gantt_chart.empty()) {
                gantt_chart = processes[shortest_job].id;
            } else {
                gantt_chart += " -> " + processes[shortest_job].id;
            }
            current_process = shortest_job;
        }

        processes[shortest_job].remaining_time--;
        current_time++;

        if (processes[shortest_job].remaining_time == 0) 
        {
            completed++;
            is_completed[shortest_job] = true;
            
            processes[shortest_job].completion_time = current_time;
            processes[shortest_job].turnaround_time = 
                processes[shortest_job].completion_time - processes[shortest_job].arrival_time;
            processes[shortest_job].waiting_time = 
                processes[shortest_job].turnaround_time - processes[shortest_job].burst_time;

            total_waiting_time += processes[shortest_job].waiting_time;
            total_turnaround_time += processes[shortest_job].turnaround_time;
            current_process = -1;
        }
    }

    sort(processes.begin(), processes.end(),
         [](const Process &a, const Process &b) {
             return a.id < b.id;
         });

    cout << "\nProcess\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time" << endl;
    for (const auto &p : processes) {
        cout << p.id << "\t" 
             << p.arrival_time << "\t\t"
             << p.burst_time << "\t\t"
             << p.completion_time << "\t\t"
             << p.waiting_time << "\t\t"
             << p.turnaround_time << endl;
    }
    
    cout << "\n\nGantt Chart:" << endl;
    cout << gantt_chart << endl;

    float average_waiting_time = total_waiting_time / n;
    float average_turnaround_time = total_turnaround_time / n;
    
    cout << "\n\nAverage Waiting Time: " << average_waiting_time;
    cout << "\nAverage Turnaround Time: " << average_turnaround_time << endl;

    return 0;
}