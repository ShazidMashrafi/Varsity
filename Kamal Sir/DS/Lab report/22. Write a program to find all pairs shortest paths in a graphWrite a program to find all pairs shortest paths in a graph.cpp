// Write a program to find all pairs shortest paths in a graph
#include <iostream>
using namespace std;

const int N = 510;
const int INF = 1e9 + 10;
int dist[N][N];

void SET_DIST()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }
}

void SHORTEST(int n)
{
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 0; i <= n; ++i)
        {
            for (int j = 0; j <= n; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }
}

void DISPLAY(int n)
{
    cout << "\nAll pair and their shortest path:" << endl;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (dist[i][j] != INF)
            {
                cout << "Pair " << i << " and " << j 
                    << ": " << dist[i][j] << endl;
            }
        }
        cout << endl;
    }
}

int main()
{
    SET_DIST();
    int n, m;
    cout << "Enter the number of edges and vertices: ";
    cin >> n >> m;
    cout << "\nEnter nodes and their weights: " << endl;
    for (int i = 0; i < m; ++i)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        dist[x][y] = wt;
    }
    SHORTEST(n);
    DISPLAY(n);
}