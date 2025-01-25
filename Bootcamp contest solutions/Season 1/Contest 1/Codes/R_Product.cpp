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
        int ct = 0;
        bool zero = 0;
        for(int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            if(x<0)
                ct++;
            if(x == 0)
                zero = 1;
        }
        if(zero)
            cout << 0 << endl;
        else
            cout << (ct & 1) << endl;
    }
}
