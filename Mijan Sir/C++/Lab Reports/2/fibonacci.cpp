#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "How many numbers of the fibonacci series you want: ";
    cin >> n;
    if (n < 1)
    {
        cout << "Invalid input" << endl;
        return 0;
    }
    int first = 0, second = 1, next;
    cout << "The first " << n << " numbers of the fibonacci series is: ";
    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
        {
            cout << first << " ";
            continue;
        }
        if (i == 0)
        {
            cout << second << " ";
            continue;
        }
        next = first + second;
        first = second;
        second = next;
        cout << next << " ";
    }
    cout << endl;
}