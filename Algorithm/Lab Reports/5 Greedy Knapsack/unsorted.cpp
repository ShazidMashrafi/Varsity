#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<double, double> a, pair<double, double> b)
{
    return a.first > b.first;
}

double GreedyKnapsack(vector<double> &p, vector<double> &w, vector<double> &x, int m, int n)
{
    vector<pair<double, double>> v(n);
    for (int i = 0; i < n; ++i)
    {
        double val = p[i] / w[i];
        v[i] = {val, i};
    }
    sort(v.begin(), v.end(), cmp);
    int ind = -1;
    double profit = 0.0;
    for (int i = 0; i < n; ++i)
    {
        ind = v[i].second;
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
    vector<double> p(n), w(n), x(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> p[i];
    for (int i = 0; i < n; ++i)
        cin >> w[i];
    double profit = GreedyKnapsack(p, w, x, m, n);
    cout << "Profit: " << profit << endl;
    cout << "Solution vector: ";
    for (int i = 0; i < n; ++i)
        cout << x[i] << " ";
    cout << endl;
}