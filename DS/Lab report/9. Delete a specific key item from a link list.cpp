// Delete a specific key item from a link list
#include <iostream>
using namespace std;

void DISPLAY(char info[], int link[], int start)
{
    int ptr = start;
    while (ptr != -1)
    {
        cout << info[ptr];
        ptr = link[ptr];
    }
}

void DELETE(char info[], int link[], int start)
{
    cout << "\nBefore deleting the item: ";
    DISPLAY(info, link, start);

    char item;
    cout << "\nEnter the item: ";
    cin >> item;

    if (item == info[start])
        start = link[start];
    else
    {
        int ptr = start, prevptr = start;
        while (ptr != -1)
        {
            ptr = link[ptr];
            if (item == info[ptr])
            {
                link[prevptr] = link[ptr];
                break;
            }
            prevptr = ptr;
        }
    }

    cout << "\nAfter deleting the item: ";
    DISPLAY(info, link, start);
}

int main()
{
    char info[13] = {"  OT  X NIE "};
    int link[13] = {-2, -2, 5, -1, -2, 10, 9, -2, 2, 3, 6, -2, -2};
    int start = 8;
    DELETE(info, link, start);
}