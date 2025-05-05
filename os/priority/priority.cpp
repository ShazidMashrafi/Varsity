#include <bits/stdc++.h>
using namespace std;

struct Process
{
    string name;
    int bt, priority, wt, tat;
};

bool cmp(Process a, Process b)
{
    return a.priority < b.priority;
}

int main()
{
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;
    vector<Process> p(n);

    for (int i = 0; i < n; i++)
        cin >> p[i].name >> p[i].bt >> p[i].priority;

    sort(p.begin(), p.end(), cmp);

    p[0].wt = 0;
    for (int i = 1; i < n; i++)
        p[i].wt = p[i - 1].wt + p[i - 1].bt;

    float totalWT = 0, totalTAT = 0;
    for (int i = 0; i < n; i++)
    {
        p[i].tat = p[i].wt + p[i].bt;
        totalWT += p[i].wt;
        totalTAT += p[i].tat;
    }

    cout << "Process\t\tBT\t\tPriority\t\tWT\t\tTAT\n";
    for (auto &pr : p)
        cout << pr.name << "\t\t\t" << pr.bt << "\t\t\t" << pr.priority << "\t\t\t" << pr.wt << "\t\t\t" << pr.tat
             << "\n";

    cout << "\nAverage Waiting Time: " << totalWT / n;
    cout << "\nAverage Turnaround Time: " << totalTAT / n << "\n";

    cout << "\nGantt Chart:\n";
    for (int i = 0; i < n; i++)
    {
        cout << p[i].name;
        if (i < n)
        {
            cout << " -> ";
        }
    }

    return 0;
}
