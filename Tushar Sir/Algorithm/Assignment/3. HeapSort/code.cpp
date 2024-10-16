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
}

void Heapify(int n)
// Readjust the elements in a[1:n] to form a heap
{
    for (int i = n / 2; i >= 1; --i)
    {
        Adjust(i, n);
    }
}

void HeapSort(int n)
// HeapSort rearranges in non decreasing order
{
    Heapify(n);
    cout<<"Created Heap: ";
    display(n);
    // Continually remove maximum value
    for (int i = n; i >= 1; --i)
    {
        int t= a[i];
        a[i]=a[1];
        a[1]=t;
        cout<<"Deleted the max element: "<<t<<endl; 
        Adjust(1, i - 1);
        cout<<"After deleting the heap is: ";
        display(i-1);
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    HeapSort(n);
}
