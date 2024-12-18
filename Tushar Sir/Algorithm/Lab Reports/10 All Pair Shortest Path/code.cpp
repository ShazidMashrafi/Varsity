#include <iostream>
using namespace std;

const int N = 510;
const int INF = 1e9 + 10;
int cost[N][N];
int dist[N][N];

void AllPaths(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (cost[i][j])
                dist[i][j] = cost[i][j];
            else if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    cout<<"Adjacency Matrix:"<<endl;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (dist[i][j] == INF)
                cout << "I ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    cout << endl<< "All pair shortest path:" << endl;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (dist[i][j] == INF)
                cout << "I ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        cost[v1][v2] = w;
    }
    
    AllPaths(n);
}