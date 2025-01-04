// Reverse a given string
#include <iostream>
using namespace std;

void DISPLAY(char text[])
{
    cout << text << endl;
}

void REVERSE(char text[], int n)
{
    cout << "\nBefore reversing: ";
    DISPLAY(text);

    for (int i = 0; i < n / 2; ++i)
    {
        char temp = text[i];
        text[i] = text[n - i - 1];
        text[n - i - 1] = temp;
    }

    cout << "\nAfter reversing: ";
    DISPLAY(text);
}

int main()
{
    int n;
    cout << "Enter length of the string: ";
    cin >> n;
    cin.ignore();
    char text[n + 1];
    cout << "\nEnter string: ";
    cin.getline(text, n + 1);
    REVERSE(text, n);
}