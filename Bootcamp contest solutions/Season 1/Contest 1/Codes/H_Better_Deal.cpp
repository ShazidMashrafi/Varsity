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
        int first = 100 - a;
        int second = 200 - 2*b;
        if(first < second)
            cout << "FIRST" << endl;
        else if(first > second)
            cout << "SECOND" << endl;
        else
            cout << "BOTH" << endl;
    }
}