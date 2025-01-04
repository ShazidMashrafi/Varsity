#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int w[N], x[N];

void SumOfSub(int s, int k, int r, int m, int n)
{
    x[k] = 1;
    if (s + w[k] == m)
    {
        for (int i = 0; i <= k; ++i)
        {
            cout << x[i] << " ";
        }
        cout << endl;
    }
    else if (s + w[k] + w[k + 1] <= m)
    {
        SumOfSub(s + w[k], k + 1, r - w[k], m, n);
    }
    x[k] = 0;
    if (s + r - w[k] >= m && s + w[k + 1] <= m)
    {
        SumOfSub(s, k + 1, r - w[k], m, n);
    }
}

int main()
{
    int n;
    cin >> n;
    int total = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> w[i];
        total += w[i];
    }
    int m;
    cin >> m;
    sort(w, w + n);
    SumOfSub(0, 0, total, m, n);
}