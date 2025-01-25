#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc = 1;
    cin >> tc;
    while(tc--)
    {
        int a, b;
        cin >> a >> b;
        if(a + b < 3)
            cout << 1 << endl;
        else if(a + b <= 10)
            cout << 2 << endl;
        else if(a + b <= 60)
            cout << 3 << endl;
        else
            cout << 4 << endl;
    }
}