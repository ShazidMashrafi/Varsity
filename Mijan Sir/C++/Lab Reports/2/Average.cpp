#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of values to average: ";
    cin >> n;
    if (n <= 0)
    {
        cout << "The number of values must be positive." << endl;
        return 1;
    }
    double sum = 0, num;
    for (int i = 0; i < n; ++i)
    {
        cout << "Enter value " << (i + 1) << ": ";
        cin >> num;
        sum += num;
    }
    double avg = sum / n;
    cout << "Average: " << avg << endl;
    return 0;
}