// Implement a stack where one can push and pop data
#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

void DISPLAY(char (&stack)[][1000], int &top, int max)
{
    if (top == -1)
    {
        cout << "Stack is empty." << endl << endl;
        return;    
    }
    cout << "The data stored in the stack are:" << endl;
    for (auto i = top; i >= 0; --i)
        cout << stack[i] << endl;
    cout << endl;
}

void PUSH(char (&stack)[][1000], int &top, int max)
{
    if (top == max - 1)
    {    
        cout << "No space in stack." << endl <<endl;
        return;
    }
    char data[1000];
    cin.ignore();
    cout << "Enter data: ";
    cin >> data;
    strcpy(stack[++top], data);
    cout << "Entry successful." << endl << endl;
}

void POP(char (&stack)[][1000], int &top, int max)
{
    if (top < 0)
    {
        cout << "Stack is already empty." << endl << endl;
        return;
    }
    char data[1000];
    strcpy(data, stack[top--]);
    cout << "Data remove successful." << endl;
    cout << "Removed data is: " << data << endl << endl;
}

void STACK(char (&stack)[][1000], int &top, int max)
{
    cout << "What do you want to do?" << endl;
    cout << "1.Push element" << endl;
    cout << "2.Pop element" << endl;
    cout << "3.Display stack" << endl;
    cout << "4.Exit" << endl;
    cout << "Enter your choice: ";
    int ch;
    cin >> ch;
    cout << endl;
    if(ch==1)
        PUSH(stack, top, max);
    else if(ch==2)
        POP(stack, top, max);
    else if(ch==3)
        DISPLAY(stack, top, max);
    else if(ch==4)
        return;
    else
        cout << "Invalid input. Try again." << endl << endl;
    STACK(stack, top, max);
}

int main()
{
    int max, top = -1;
    cout << "Enter the maximum size of stack: ";
    cin >> max;
    char stack[max][1000];
    STACK(stack, top, max);
}