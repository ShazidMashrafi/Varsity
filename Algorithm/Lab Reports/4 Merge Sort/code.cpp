#include <iostream>
#include <vector>

using namespace std;

void Merge(vector<int> &a, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = a[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = a[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            ++i;
        }
        else
        {
            a[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1)
    {
        a[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2)
    {
        a[k] = R[j];
        ++j;
        ++k;
    }
}

void MergeSort(vector<int> &a, int l, int r)
{
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    MergeSort(a, l, m);
    MergeSort(a, m + 1, r);
    Merge(a, l, m, r);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    MergeSort(a, 0, n - 1);
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
}