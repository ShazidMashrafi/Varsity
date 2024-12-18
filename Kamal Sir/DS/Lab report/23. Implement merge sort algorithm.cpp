// Implement merge sort algorithm
#include <iostream>
using namespace std;

void MERGE(int arr[], int l, int m, int r)
{
    int len1 = m - l + 1;
    int len2 = r - m;
    int first[len1], second[len2];
    int k = l;
    for (int i = 0; i < len1; i++)
        first[i] = arr[k++];
    k = m + 1;
    for (int i = 0; i < len2; i++)
        second[i] = arr[k++];
    int i = 0, j = 0;
    k = l;
    while (i < len1 && j < len2)
    {
        if (first[i] <= second[j])
            arr[k++] = first[i++];
        else
            arr[k++] = second[j++];
    }
    while (i < len1)
        arr[k++] = first[i++];
    while (j < len2)
        arr[k++] = second[j++];
}

void MERGE_SORT(int arr[], int l, int r)
{
    if (l >= r) return;
    int m = l + (r - l) / 2;
    MERGE_SORT(arr, l, m);
    MERGE_SORT(arr, m + 1, r);
    MERGE(arr, l, m, r);
}

void DISPLAY(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
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

    cout << "\nBefore sorting: ";
    DISPLAY(arr, n);
    MERGE_SORT(arr, 0, n - 1);
    cout << "\nAfter sorting: ";
    DISPLAY(arr, n);
}