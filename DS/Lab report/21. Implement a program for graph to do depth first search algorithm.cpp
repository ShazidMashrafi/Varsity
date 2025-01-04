// Implement a program for graph to do depth first search algorithm
#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];
int vis[N];

void DFS(int vertex)
{
    cout << vertex << " ";
    vis[vertex] = true;
    for (int child : g[vertex])
    {
        if (!vis[child])
            DFS(child);
    }
}

int main()
{
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    int v;
    cout << "\nEnter staring vertex: ";
    cin >> v;
    cout << "\nNodes in order of DFS is: ";
    DFS(v);
}