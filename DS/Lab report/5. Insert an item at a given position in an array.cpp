// Insert an item at a given position in an array
#include <iostream>
using namespace std;

void DISPLAY(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void INSERT(int arr[], int n)
{
    cout << "\nBefore insertion the array is: ";
    DISPLAY(arr,n);

    int pos, item;
    cout << "\nEnter the position and the item: ";
    cin >> pos >> item;
    pos--;
    for (int i = n - 1; i >= pos; --i)
        arr[i + 1] = arr[i];
    arr[pos] = item;
    n++;

    cout << "\nAfter insertion the array is: ";
    DISPLAY(arr,n);
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n + 10];
    cout << "\nEnter the elements: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    INSERT(arr, n);
}