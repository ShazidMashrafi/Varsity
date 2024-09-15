#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
double p[N], w[N], x[N];

double GreedyKnapsack(int m, int n)
{
    double profit = 0.0;
    int ind = -1;
    for (int i = 0; i < n; ++i)
    {
        ind = i;
        if (w[ind] > m)
            break;
        x[ind] = 1.0;
        m -= w[ind];
        profit += p[ind];
    }
    if (ind < n)
    {
        x[ind] = m / w[ind];
        profit += p[ind] * (m / w[ind]);
    }
    return profit;
}

int main()
{
    double n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    for (int i = 0; i < n; ++i)
        cin >> w[i];
    double profit = GreedyKnapsack(m, n);
    cout << "Profit: " << profit << endl;
    cout << "Solution vector: ";
    for (int i = 0; i < n; ++i)
        cout << x[i] << " ";
    cout << endl;
}