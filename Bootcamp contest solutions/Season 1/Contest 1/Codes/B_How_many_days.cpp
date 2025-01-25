#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc = 1;
    // cin >> tc;
    while(tc--)
    {
        int year;
        cin >> year;
        if(year % 400 == 0)
            cout << 366 << endl;
        else if(year % 4 == 0 && year % 100)
            cout << 366 << endl;
        else
            cout << 365 << endl;
    }
}