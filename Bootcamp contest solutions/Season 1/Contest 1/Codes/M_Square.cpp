#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc = 1;
    // cin >> tc;
    while(tc--)
    {
        int n, m, a;
        cin >> n >> m >> a;
        cout << ((n + a - 1) / a) * ((m + a - 1) / a) << endl; 
    }
}