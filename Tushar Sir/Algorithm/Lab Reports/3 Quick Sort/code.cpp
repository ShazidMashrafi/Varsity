#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int arr[N];

int Partition(int l, int r)
{
    int i, j;
    i = l, j = r;
    while (i < j)
    {
        while (arr[l] > arr[i])
            i++;
        while (arr[l] < arr[j])
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[l], arr[j]);
    return j;
}

void quickSort(int l, int r)
{
    if (l < r)
    {
        int m = Partition(l, r);
        quickSort(l, m - 1);
        quickSort(m + 1, r);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    arr[n] = INT_MAX;
    quickSort(0, n);
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}