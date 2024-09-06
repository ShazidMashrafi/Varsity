// Implement quicksort algorithm
#include <iostream>
using namespace std;

void DISPLAY(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int partition(int arr[], int s, int e)
{
    int pivot = arr[s];
    int ct = 0;
    for(int i = s + 1; i <= e; ++i)
    {
        if(arr[i] <= pivot)
            ct++;
    }
    int ind = s + ct;
    swap(arr[ind], arr[s]);
    int i = s, j = e;
    while(i < ind && j > ind)
    {
        while(arr[i] < pivot)   i++;
        while(arr[j] > pivot)   j--;
        if(i < ind && j > ind)
            swap(arr[i++], arr[j--]);
    }
    return ind;
}

void quickSort(int arr[], int s, int e)
{
    if (s >= e)  return;
    int p = partition(arr, s, e);
    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << "\nBefore sorting: ";
    DISPLAY(arr, n);
    quickSort(arr, 0, n - 1);
    cout << "\nAfter sorting: ";
    DISPLAY(arr, n);
}