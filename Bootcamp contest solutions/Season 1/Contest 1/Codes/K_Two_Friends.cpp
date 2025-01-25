#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc = 1;
    // cin >> tc;
    while(tc--)
    {
        int w;
        cin >> w;
        if(w & 1 || w<4)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}