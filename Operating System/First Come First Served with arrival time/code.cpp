#include <bits/stdc++.h>
using namespace std;

struct Process 
{
    int id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
};

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    cout << "\nEnter the Arrival Time and Burst Time for each process\n";
    for(int i = 0; i < n; i++) 
    {
        processes[i].id = i + 1;
        cout << "\nProcess " << i + 1 << "\n";
        cout << "Arrival Time: ";
        cin >> processes[i].arrival_time;
        cout << "Burst Time: ";
        cin >> processes[i].burst_time;
    }

    sort(processes.begin(), processes.end(), 
    [](const Process& a, const Process& b) 
    {
        return a.arrival_time < b.arrival_time;
    });

    int current_time = 0;
    float total_waiting_time = 0;
    float total_turnaround_time = 0;

    for(int i = 0; i < n; i++) 
    {
        if(current_time < processes[i].arrival_time)
            current_time = processes[i].arrival_time;
        
        processes[i].completion_time = current_time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        
        current_time = processes[i].completion_time;
        
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    cout << "\nProcess\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time";
    for(const auto& p : processes) 
    {
        cout << "\nP[" << p.id << "]\t" 
             << p.arrival_time << "\t\t"
             << p.burst_time << "\t\t"
             << p.completion_time << "\t\t"
             << p.waiting_time << "\t\t"
             << p.turnaround_time;
    }

    float average_waiting_time = total_waiting_time / n;
    float average_turnaround_time = total_turnaround_time / n;
    
    cout << "\n\nAverage Waiting Time: " << average_waiting_time;
    cout << "\nAverage Turnaround Time: " << average_turnaround_time << endl;

    return 0;
}