#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc = 1;
    cin >> tc;
    while(tc--)
    {
        int a, b, c, x;
        cin >> a >> b >> c >> x;
        if(a + b >= x || b + c >= x || a + c >= x)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}