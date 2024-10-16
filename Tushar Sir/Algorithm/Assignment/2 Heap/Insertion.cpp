#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N];

void display(int n)
{
    // Displays the current heap
    for (int i = 1; i <= n; ++i)
        cout << a[i] << " ";
    cout << endl;
}

int insert(int n)
{
    // Inserts a[n] into the heap which is stored in a[1:n-1]
    int i = n;
    int item = a[n];
    while (i > 1 && a[i / 2] < item)
    {
        a[i] = a[i / 2];
        i = i / 2;
    }
    a[i] = item;
    return true;
}

int main()
{
    int n = 0;
    int ele;
    while (cin >> ele)
    {
        cout << "Inserting " << ele << " into heap" << endl;
        n++;
        a[n] = ele;
        cout << "After insertion: " << ele << " : ";
        display(n);
    }
}