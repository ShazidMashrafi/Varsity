#include <iostream>
#include <chrono>
#include <math.h>
using namespace std;

int LasVegas()
{
    int i;
    while (true)
    {
        i = rand();
        if (i % 2 == 1)
            return i;
    }
}

bool Prime1(int n, int k)
{
    for (int i = 0; i < k; ++i)
    {
        int m = pow(n, 0.5);
        int j = rand() % (m + 2);
        if (n % j == 0)
            return false;
    }
    return true;
}

void MonteCarlo(int n, int k)
{
    if (Prime1(n, k))
        cout << "Number " << n << " is probably prime." << endl;
    else
        cout << "Number " << n << " is not prime." << endl;
}

int main()
{
    int n;
    cout << "Finding odd number using Las Vegas Algorithm: " << endl;
    cout << "Enter the number of times to run: ";
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cout << "Run: " << i << endl;
        auto start = chrono::high_resolution_clock::now();
        cout << "LasVegas found an odd number: " << LasVegas() << endl;
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, nano> duration = end - start;
        cout << "Took " << duration.count() << " nanoseconds" << endl;
    }
    cout << endl;

    cout << "Finding the primality using Monte Carlo Algorithm: " << endl;
    int number, t;
    cout << "Enter the number to check primality for: ";
    cin >> number;
    cout << "Enter the number of times to run: ";
    cin >> n;
    cout << "Enter the number of iterations per run: ";
    cin >> t;
    for (int i = 1; i <= n; ++i)
    {
        cout << "Run: " << i << endl;
        auto start = chrono::high_resolution_clock::now();
        MonteCarlo(number, t);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double, nano> duration = end - start;
        cout << "Took " << duration.count() << " nanoseconds" << endl;
    }
    return 0;
}