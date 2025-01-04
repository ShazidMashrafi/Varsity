// Find a pair with the given sum in an array
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int hsh[N];

void FIND_SUM(int arr[], int n)
{
    int k;
    cout << "\nEnter sum: ";
    cin >> k;
    for (int i = 0; i < n; ++i)
    {
        if (hsh[arr[i]])
        {
            cout << "\nThe two numbers are: " << arr[i] << " " << k - arr[i] << endl;
            return;
        }
        hsh[k - arr[i]] = 1;
    }
    cout << "\nPair not found" << endl;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "\nEnter the elements: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    FIND_SUM(arr, n);
}