#include <bits/stdc++.h>
using namespace std;
#define N 10
int parent[N];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionset(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskal(int cost[N][N], int n) {
    int mincost = 0;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    int count = 0;
    while (count < n-1 ) {
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (find(i) != find(j) && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        unionset(a, b);
        cout << a << "-------"<<b<< endl;
        mincost += min;
        count++;
        
    }
    cout << mincost << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    int cost[N][N] = {0};
    for (int i = 1; i <=m; i++) {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        cost[v1][v2] = w;
        cost[v2][v1] = w;
    }
    for (int i = 1; i <=n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j && cost[i][j] == 0)
                cost[i][j] = INT_MAX;
        }
    }
    kruskal(cost, n);
    return 0;
}
