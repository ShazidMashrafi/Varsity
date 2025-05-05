#include <bits/stdc++.h>
using namespace std;

struct Process
{
    string id;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
};

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;

    vector<Process> processes(n);

    for (int i = 0; i < n; i++) {
        cin >> processes[i].id >> processes[i].burst_time;
        processes[i].remaining_time = processes[i].burst_time;
    }

    int time_quantum;
    cin >> time_quantum;

    int current_time = 0;
    queue<int> ready_queue;
    vector<bool> is_completed(n, false);
    int completed = 0;
    float total_waiting_time = 0;
    float total_turnaround_time = 0;
    string gantt_chart = "";

    for (int i = 0; i < n; i++) {
        ready_queue.push(i);
    }

    while (completed != n) {
        if (ready_queue.empty()) {
            current_time++;
            continue;
        }

        int current_process = ready_queue.front();
        ready_queue.pop();

        if (gantt_chart.empty()) {
            gantt_chart = processes[current_process].id;
        } else {
            gantt_chart += " -> " + processes[current_process].id;
        }

        int execute_time = min(time_quantum, processes[current_process].remaining_time);
        current_time += execute_time;
        processes[current_process].remaining_time -= execute_time;

        if (processes[current_process].remaining_time == 0) {
            completed++;
            is_completed[current_process] = true;
            processes[current_process].completion_time = current_time;
            processes[current_process].turnaround_time = processes[current_process].completion_time;
            processes[current_process].waiting_time = processes[current_process].turnaround_time - processes[current_process].burst_time;

            total_waiting_time += processes[current_process].waiting_time;
            total_turnaround_time += processes[current_process].turnaround_time;
        } else {
            ready_queue.push(current_process);
        }
    }

    sort(processes.begin(), processes.end(),
         [](const Process &a, const Process &b) {
             return a.id < b.id;
         });

    cout << "\nProcess\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time" << endl;
    for (const auto &p : processes) {
        cout << p.id << "\t" 
             << p.burst_time << "\t\t"
             << p.completion_time << "\t\t"
             << p.waiting_time << "\t\t"
             << p.turnaround_time << endl;
    }
    
    cout << "\n\nGantt Chart:" << endl;
    cout << gantt_chart << endl;

    float average_waiting_time = total_waiting_time / n;
    float average_turnaround_time = total_turnaround_time / n;
    
    cout << "\nTotal Waiting Time: " << total_waiting_time;
    cout << "\nAverage Waiting Time: " << average_waiting_time;
    cout << "\nTotal Turn Around Time: " << total_turnaround_time;
    cout << "\nAverage Turnaround Time: " << average_turnaround_time << endl;
    cout << "\nTime Quantum: " << time_quantum << endl;

    return 0;
}