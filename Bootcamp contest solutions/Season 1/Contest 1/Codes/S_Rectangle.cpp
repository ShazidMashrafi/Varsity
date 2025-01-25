#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        // int a, b, c, d;
        // cin >> a >> b >> c >> d;
        // if((a == b && c == d) || (a == c && b == d) || (a == d && b == c))
        //     cout <<"YES" << endl;
        // else
        //     cout << "NO" << endl;
        
        // int sides[4];
        // for(int i = 0; i < 4; ++i)
        //     cin >> sides[i];
        // sort(sides, sides + 4);
        // if(sides[0] == sides[1] && sides[2] == sides[3])
        //     cout << "YES" << endl;
        // else
        //     cout << "NO" << endl;

        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a ^ b ^ c ^ d)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}