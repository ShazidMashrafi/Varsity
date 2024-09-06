// Implement selection sort algorithm
#include <iostream>
using namespace std;

void SELECTION_SORT(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(arr[min], arr[i]);
    }
}

void DISPLAY(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
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
    cout << "\nAfter sorting: ";
    DISPLAY(arr, n);
    SELECTION_SORT(arr, n);
    cout << "\nAfter sorting: ";
    DISPLAY(arr, n);
}