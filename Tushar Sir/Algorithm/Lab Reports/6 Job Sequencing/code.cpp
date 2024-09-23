#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int j[N], d[N], p[N];

int JS(int n, vector<int> &ans)
{
    d[0] = j[0] = 0;
    int profit = p[1];
    j[1] = 1;
    ans.push_back(1);
    int k = 1;
    for (int i = 2; i <= n; ++i)
    {
        int r = k;
        while (d[j[r]] > d[i] && d[j[r]] != r)
            r--;
        if (d[j[r]] <= d[i] && d[i] > r)
        {
            for (int q = k; q >= r + 1; q--)
                j[q + 1] = j[q];
            j[r + 1] = i;
            ans.push_back(i); 
            profit += p[i];
            k++;
        }
    }
    return profit;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> d[i];
    }
    vector<int> ans;
    int profit = JS(n, ans);
    cout << "Profit: " << profit << endl;
    cout << "Jobs Taken: ";
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
    cout<<"Job sequence is: ";
    for(int i=1; i<=n; ++i)
        cout<<j[i]<<" ";
    cout<<endl;
}