#include <bits/stdc++.h>
using namespace std;

int minIndex(int n, long long int *dist, bool *flag)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++)
        if (flag[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void shrotPath(int n, vector<vector<int>> cost, int v)
{
    bool S[n + 1];
    long long int dist[n + 1];
    int path[n + 1];
    for (int i = 0; i <= n; i++)
    {
        S[i] = false;
        dist[i] = cost[v][i];
        path[i] = v;
    }
    S[v] = true;
    dist[v] = 0;
    
//     I   50   45   10    I    I
//     I    I   10   15    I    I
//     I    I    I    I   30    I
//    20    I    I    I   15    I
//     I   20   35    I    I    I
//     I    I    I    I    3    I

// 0 50 45 10 I I 
// 4
// 5
// 3
// 2
// 0

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INT_MAX)
            cerr << "I ";
        else
            cerr << dist[i]<<" ";
    }
    cerr<<endl;
    for (int i = 1; i <= n; i++)
    {
        int u = minIndex(n, dist, S);
        S[u] = true;
        cerr<<u<<endl;
        for (int w = 1; w <= n; w++)
        {
            if (!S[w] && dist[w] > dist[u] + cost[u][w])
            {
                dist[w] = dist[u] + cost[u][w];
                path[w] = u;
            }
        }
    }
    cout << "node | prev | dist \n";
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] < INT_MAX)
            cout << setw(5) << i << "|" << setw(5) << path[i] << " |" << setw(5) << dist[i] << endl;
        else
            cout << setw(5) << i << "|" << setw(5) << path[i] << " |" << setw(5) << "INF" << endl;
    }
}

int main()
{
    int n, m;
    cout << "Enter the number of nodes : ";
    cin >> n;
    cout << "Enter the number of edges : ";
    cin >> m;
    vector<vector<int>> cost(n + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 0; i < m; i++)
    {
        int v1, v2, weight;
        cout << "Enter from to and weight of the node : ";
        cin >> v1 >> v2 >> weight;
        cost[v1][v2] = weight;
    }
    cout << "The weight matrix form of the graph is - " << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << setw(5);
            if (cost[i][j] == INT_MAX)
                cout << "I";
            else
                cout << cost[i][j];
        }
        cout << endl;
    }
    int start;
    cout << "Enter the starting node : ";
    cin >> start;
    shrotPath(n, cost, start);
    return 0;
}