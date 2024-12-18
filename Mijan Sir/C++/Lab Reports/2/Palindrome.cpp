#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    string s, t;
    cout << "Enter string: ";
    cin >> s;
    t = s;
    reverse(t.begin(), t.end());
    if (s == t)
        cout << "String is palindrome" << endl;
    else
        cout << "String is not palindrome";
}