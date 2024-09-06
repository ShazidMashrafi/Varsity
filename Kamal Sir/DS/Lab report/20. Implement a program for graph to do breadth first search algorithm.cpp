// Implement a program for graph to do breadth first search algorithm
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
int vis[N];

void BFS(int source)
{
    cout << "\nThe graph in order of BFS: ";
    queue<int> q;
    q.push(source);
    vis[source] = 1;
    while (!q.empty())
    {
        int vertex = q.front();
        cout << vertex << " ";
        q.pop();
        for (int child : g[vertex])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = 1;
            }
        }
    }
}

int main()
{
    int n, e;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> e;
    for (int i = 0; i < e; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int v;
    cout << "Enter starting vertex: ";
    cin >> v;
    BFS(v);
}