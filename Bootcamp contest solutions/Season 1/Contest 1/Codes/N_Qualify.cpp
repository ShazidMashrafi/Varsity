#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc = 1;
    cin >> tc;
    while(tc--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if(y <= x + 2 * z)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}