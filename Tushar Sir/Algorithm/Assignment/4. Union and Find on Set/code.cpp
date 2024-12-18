#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int p[N];

int SimpleFind(int v)
{
    while (p[v] > 0)
    {
        v = p[v];
    }
    return v;
}

void SimpleUnion(int v, int u)
{
    v = SimpleFind(v);
    u = SimpleFind(u);
    p[u] = v;
}

int main()
{
    int n,m;
    cout<<"Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the number of union operations: ";
    cin >> m;

    cout << "Enter the union operations (pairs of nodes):" << endl;
    for (int i = 0; i < m; ++i) 
    {
        int u, v;
        cin >> u >> v;
        SimpleUnion(u, v);
    }


    for (int i = 1; i <= n; ++i)
    {
        cout << "Parent of " << i << " is: " << p[i] << endl;
    }
}
