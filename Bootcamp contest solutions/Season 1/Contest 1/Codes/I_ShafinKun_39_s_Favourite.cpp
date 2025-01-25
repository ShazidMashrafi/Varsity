#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc = 1;
    // cin >> tc;
    while(tc--)
    {
        // string s;
        // cin >> s;
        // reverse(all(s));
        // cout << s << endl; 

        char s[25];
        cin >> s;
        int len = strlen(s);
        while(len--)
            cout << s[len];
        cout << endl; 
    }
}