// Implement binary search algorithm
#include<iostream>
#include<algorithm>
using namespace std;

void BINARY_SEARCH(int arr[], int n, int k)
{
    int l = 0, r = n - 1;
    while(l <= r)
    {
        int mid = l + (r - l) / 2;
        if(arr[mid] == k)
        {
            cout << "\nTarget found at position: " << mid + 1 << endl;
            return;
        }
        else if(arr[mid] < k)
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout<<"\nTarget not found"<<endl;
}

int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"\nEnter the elements: ";
    for(int i=0; i<n; ++i)
        cin>>arr[i];
    sort(arr, arr+n);
    int k;
    cout<<"\nEnter target value: ";
    cin>>k;
    BINARY_SEARCH(arr,n,k);
}