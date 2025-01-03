#include <iostream>
using namespace std;
int main()
{
    char op;
    int num1, num2;
    cout << "Enter the type of operation you want to do(+,-,*,/): ";
    cin >> op;
    cout << "Enter first and second  number: ";
    cin >> num1 >> num2;
    if (num2 == 0)
    {
        cout << "Division by zero is not defined" << endl;
        return -1;
    }
    int ans;
    bool f = 0;
    switch (op)
    {
    case '+':
        ans = num1 + num2;
        break;
    case '-':
        ans = num1 - num2;
        break;
    case '*':
        ans = num1 * num2;
        break;
    case '/':
        ans = num1 / num2;
        break;
    case '%':
        ans = num1 % num2;
        break;
    default:
        f = 1;
        break;
    }
    if (f)
        cout << "Invalid operation" << endl;
    else
        cout << "Result is: " << ans << endl;
}