#include<bits/stdc++.h>
using namespace std;

struct Process
{
    string name;
    int bt, wt, tat;
};

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<Process> p(n);

    for (int i = 0; i < n; i++)
        cin >> p[i].name >> p[i].bt;

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

    cout << "Process\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++)
        cout << p[i].name << "\t" << p[i].bt << "\t" << p[i].wt << "\t" << p[i].tat << "\n";

    cout << "\nAverage Waiting Time: " << totalWT / n;
    cout << "\nAverage Turnaround Time: " << totalTAT / n << "\n";

    // Gantt Chart
    cout << "\nGantt Chart:\n";
    for (int i = 0; i < n; i++)
    {
        cout << p[i].name;
        if (i + 1 < n)
        {
            cout << " -> ";
        }
    }
}
