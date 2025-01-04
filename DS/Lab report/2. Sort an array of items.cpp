// Sort an array of items
#include <iostream>
using namespace std;

void TRAVERSE(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void SORT(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout << "\nArray after sorting: ";
    TRAVERSE(arr, n);
}

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];
    cout << "\nEnter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    SORT(arr, n);
}