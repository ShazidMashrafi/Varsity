// Find the index of a sub string in a string using patten function
#include <iostream>
#include <string.h>
using namespace std;

void INDEX(char s[], char sub[])
{
    int len = strlen(s);
    int slen = strlen(sub);
    for (int i = 0; i <= len - slen; ++i)
    {
        for (int j = 0; j < slen; ++j)
        {
            if (s[i + j] != sub[j])
                break;
            if (j + 1 == slen)
            {
                cout << "\nPattern found at position: " << i + 1 << endl;
                return;
            }
        }
    }
    cout << "\nPattern not found" << endl;
}

int main()
{
    char s[1000], sub[100];
    cout << "Enter string: ";
    cin.getline(s, 1000);
    cout << "\nEnter substring: ";
    cin.getline(sub, 100);
    INDEX(s, sub);
}