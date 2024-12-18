#include <iostream>
using namespace std;

int x[20];
bool all_placed = false;

bool Place(int k, int i)
{
    for (int j = 1; j < k; j++)
    {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
        {
            return false;
        }
    }
    return true;
}

void Display(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

bool NQueens(int k, int n)
{
    bool placed = false;
    for (int i = 1; i <= n; i++)
    {
        if (Place(k, i))
        {
            x[k] = i;
            cout << "Placed queen at row " << k << ", column " << i << endl;
            placed = true;
            if (k == n)
            {
                Display(n);
                return true;
            }
            NQueens(k + 1, n);
            cout << "Backtracking from row " << k << ", column " << i << endl;
        }
    }
    if (!placed && k == 1)
    {
        cout << "Not a valid sequence" << endl;
    }
    return false;
}

int main()
{
    int n = 4;
    NQueens(1, n);
    return 0;
}