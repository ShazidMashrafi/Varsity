// Delete an item from a define place in an array
#include <iostream>
using namespace std;

void DISPLAY(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int DELETE(int arr[], int n, int k)
{
    cout << "Before deleting the element the array is: ";
    DISPLAY(arr,n);

    int item = arr[k];
    for (int i = k; i < n - 1; ++i)
        arr[i] = arr[i + 1];
    n--;

    cout << "After deleting the element the array is: ";
    DISPLAY(arr,n);
    cout << "The deleted item is: " << item << endl;
}

int main()
{
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "\nEnter the elements: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << "\nEnter the position: ";
    cin >> k;
    DELETE(arr, n, k - 1);
}