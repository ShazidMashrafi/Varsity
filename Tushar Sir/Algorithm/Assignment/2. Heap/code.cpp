#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
int a[MAX_SIZE];

void display(int n)
// Displays the current heap
{
    for (int i = 1; i <= n; ++i)
        cout << a[i] << " ";
    cout << endl;
}

int insert(int n)
// Inserts a[n] into the heap which is stored in a[1:n-1]
{
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

void Adjust(int i, int n)
// Adjust the heap after the max element is deleted
{
    int item = a[i];
    int j = 2 * i;
    while (j <= n)
    {
        if (j < n && a[j] < a[j + 1])
            j++;
        if (item >= a[j])
            break;
        a[j / 2] = a[j];
        j = 2 * j;
    }
    a[j / 2] = item;
    display(n);
}

bool DelMax(int n)
// Delete the maximum element
{
    if (n == 0)
    {
        cout << "Heap is empty" << endl;
        return false;
    }
    display(n);
    int x = a[1];
    a[1] = a[n];
    Adjust(1, n - 1);
    return true;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int ele;
        cout << "Enter the element: ";
        cin >> ele;
        cout << "Inserting " << ele << " into heap" << endl;
        a[i] = ele;
        insert(i);
        cout << "After insertion: ";
        display(i);
    }

    int del;
    cout << "Enter the number of elements you want to remove: ";
    cin >> del;
    while (del--)
    {
        DelMax(n);
        n--;
    }

    return 0;
}