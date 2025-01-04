// Traverse items in an array data structure
#include <iostream>
using namespace std;

void TRAVERSE(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << "The elements of the array are: ";
    TRAVERSE(arr, n);
}