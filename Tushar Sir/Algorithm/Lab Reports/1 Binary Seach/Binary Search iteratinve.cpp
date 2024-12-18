#include <iostream>
using namespace std;

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

    int result = -1;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            result = mid;
            break;
        }
        if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (result != -1)
        cout << "Element is present at index " << result + 1 << endl;
    else
        cout << "Element is not present in array" << endl;
    return 0;
}