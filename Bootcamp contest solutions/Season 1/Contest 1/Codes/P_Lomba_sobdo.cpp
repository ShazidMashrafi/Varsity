#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc = 1;
    cin >> tc;
    while(tc--)
    {
        string s;
        cin >> s;
        int len = s.length();
        if(len <= 10)
            cout << s << endl;
        else
            cout << s[0] << len - 2 << s[len-1] << endl;
    }
}