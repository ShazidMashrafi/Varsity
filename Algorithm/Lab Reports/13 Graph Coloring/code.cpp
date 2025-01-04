#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int graph[N][N];
int x[N];

void NextValue(int k, int n, int m)
{
    while (true)
    {
        x[k] = (x[k] + 1) % (m + 1);
        if(x[k] == 0) return;
        int j;
        for(j=0; j<n; ++j)
        {
            if(graph[k][j] && x[k] == x[j]) break;
        }
        if(j = n + 1) return;
    }
}

void mColoring(int k, int n, int m)
{
    while (true)
    {
        NextValue(k, n, m);
        if (x[k] == 0)
            return;
        if (k == n)
        {
            for (int i = 0; i < n; ++i)
            {
                cout << x[i] << " ";
            }
            cout << endl;
        }
        else
            mColoring(k + 1, n, m);
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; ++i)
    {
        int v, u;
        cin >> v >> u;
        graph[v][u] = 1;
        graph[u][v] = 1;
    }
    int m;
    cin >> m;

    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    mColoring(0, n, m);
}