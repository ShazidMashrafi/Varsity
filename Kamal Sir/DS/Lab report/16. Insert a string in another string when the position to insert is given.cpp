// Insert a string in another string when the position to insert is given
#include <iostream>
using namespace std;

void DISPLAY(char s[])
{
    cout << s << endl;
}

void INSERT(char text[], int n, char subtext[], int m)
{
    cout << "\nBefore insertion: ";
    DISPLAY(text);

    int pos;
    cout << "\nGive the postion to insert: ";
    cin >> pos;
    pos--;
    for (int i = n; i >= pos; --i)
        text[i + m] = text[i];
    for (int i = 0; i < m; ++i)
        text[pos + i] = subtext[i];

    cout << "\nAfter insertion: ";
    DISPLAY(text);
}

int main()
{
    int n, m;
    cout << "Enter the length of the string and substring: ";
    cin >> n >> m;
    cin.ignore();
    char text[n + m + 1], subtext[m + 1];
    cout << "\nEnter string: ";
    cin.getline(text, n + 1);
    cout << "\nEnter substring: ";
    cin.getline(subtext, m + 1);
    cerr << text << endl
         << subtext << endl;
    INSERT(text, n, subtext, m);
}