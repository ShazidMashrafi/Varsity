#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc = 1;
    cin >> tc;
    while(tc--)
    {
    int n;
    cin >> n;
    bool good = 1;
    for(int i = 0; i< n; ++i)
    {
        int x;
        cin >> x;
        if(x<5)
            good = 0;
    }
    if(good)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    }
}