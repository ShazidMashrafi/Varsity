#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc = 1;
    // cin >> tc;
    while(tc--)
    {
        char c;
        cin >> c;
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            cout << "Vowel" << endl;
        else
            cout << "Consonant" << endl;
    }
}