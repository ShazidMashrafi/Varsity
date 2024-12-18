#include <iostream>
using namespace std;

int binarySearch(int arr[], int target, int start, int end)
{
    if (start > end)
        return -1;
    int mid = start + (end - start) / 2;
    if (arr[mid] == target)
        return mid;
    if (arr[mid] > target)
        return binarySearch(arr, target, start, mid - 1);
    return binarySearch(arr, target, mid + 1, end);
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements in non-decreasing order: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    int target;
    cout << "Enter the target element: ";
    cin >> target;
    int result = binarySearch(arr, target, 0, n - 1);
    if (result != -1)
        cout << "Element is present at index " << result + 1 << endl;
    else
        cout << "Element is not present in array" << endl;
    return 0;
}