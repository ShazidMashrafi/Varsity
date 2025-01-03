#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
const int INF = INT_MAX;
int cost[N][N];
int dist[N];
bool S[N];

int minIndex(int n)
{
    int min = INT_MAX, min_index = -1;
    for (int v = 1; v <= n; v++)
    {
        if (S[v] == false && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void ShortestPath(int n, int v)
{
    for (int i = 1; i <= n; i++)
    {
        S[i] = false;
        dist[i] = cost[v][i];
    }
    dist[v] = 0;
    S[v] = true;

    for (int i = 1; i <= n; i++)
    {
        int u = minIndex(n);
        if (u == -1)
            break;
        S[u] = true;
        for (int w = 1; w <= n; w++)
        {
            if (S[w] || cost[u][w] == INF)
                continue;
            dist[w] = min(dist[w], dist[u] + cost[u][w]);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (dist[i] == INF)
            cout << v << " to " << i << " is INF" << endl;
        else
            cout << v << " to " << i << " is " << dist[i] << endl;
    }
}

int main()
{
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cost[i][j] = INF;
        }
    }

    cout << "Enter the edges (u, v, w):" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> v >> u >> w;
        cost[v][u] = w;
    }

    int source;
    cout << "Enter the source node: ";
    cin >> source;
    ShortestPath(n, source);
    return 0;
}