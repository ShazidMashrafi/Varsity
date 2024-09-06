// Given a complete binary tree. Now store tree data
// in an array and print all the leaf nodes
#include <iostream>
using namespace std;

void LEAF(int tree[], int n)
{
    cout<<"\nThe leaf nodes are: ";
    for (int i = 1; i <= n; ++i)
    {
        if(2*i>n)
            cout<<i<<" ";
    }
}

int main()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    int tree[n];
    cout << "\nEnter nodes: ";
    for (int i = 0; i < n; ++i)
        cin >> tree[i];
    LEAF(tree, n);
}