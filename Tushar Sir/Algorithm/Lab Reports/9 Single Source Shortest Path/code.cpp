#include <iostream>
#include <climits>
using namespace std;

const int N = 1e3 + 10;
const int INF = INT_MAX;
int cost[N][N];
int dist[N];
bool S[N];

void ShortestPath(int n, int v)
{
    for (int i = 1; i <= n; i++)
    {
        S[i] = false;
        dist[i] = cost[v][i];
    }
    S[v] = true;
    dist[v] = 0;

    for (int i = 1; i < n; i++)
    {
        int u = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!S[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        }

        if (u == -1 || dist[u] == INF)
            break;

        S[u] = true;

        for (int w = 1; w <= n; w++)
        {
            if (!S[w] && cost[u][w] != INF && dist[u] + cost[u][w] < dist[w])
            {
                dist[w] = dist[u] + cost[u][w];
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (dist[i] == INF)
            cout << "Distance from " << v << " to " << i << " is INF" << endl;
        else
            cout << "Distance from " << v << " to " << i << " is " << dist[i] << endl;
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
        cin >> u >> v >> w;
        cost[u][v] = w;
        cost[v][u] = w;
    }

    int source;
    cout << "Enter the source node: ";
    cin >> source;
    ShortestPath(n, source);
    return 0;
}