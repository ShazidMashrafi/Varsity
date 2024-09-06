// Search for a key item in an array
#include <iostream>
using namespace std;

void SEARCH(int arr[], int n)
{
    int key;
    cout << "\nEnter the key: ";
    cin >> key;
    for (int i = 0; i < n; ++i)
    {
        if (key == arr[i])
        {
            cout << "\nThe element is found at position: " << i + 1 << endl;
            return;
        }
    }
    cout << "\nThe key was not found in the array" << endl;
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
    SEARCH(arr, n);
}