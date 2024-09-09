#include <bits/stdc++.h>
using namespace std;

void MinMax(int arr[], int low, int high, int &mn, int &mx) 
{
    if (low == high) 
    {
        mn = mx = arr[low];
        return;
    }
    if (high == low + 1) 
    {
        if (arr[low] < arr[high]) 
        {
            mn = arr[low];
            mx = arr[high];
        } 
        else
        {
            mn = arr[high];
            mx = arr[low];
        }
        return;
    }
    int mid = low + (high - low) / 2;
    int leftMin, leftMax, rightMin, rightMax;
    MinMax(arr, low, mid, leftMin, leftMax);
    MinMax(arr, mid + 1, high, rightMin, rightMax);
    mn = min(leftMin, rightMin);
    mx = max(leftMax, rightMax);
}

int main() 
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for(int i=0; i<n; ++i)  cin>>arr[i];
    int min=arr[0], max=arr[0];
    MinMax(arr, 0, n-1, min, max);
    cout << "Minimum element: " << min << endl;
    cout << "Maximum element: " << max << endl;
    return 0;
}