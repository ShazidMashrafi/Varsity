// Delete the first item from a link list
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
    cout << "\nBefore deleting the first item: ";
    DISPLAY(info, link, start);

    start = link[start];

    cout << "\nAfter deleting the first item: ";
    DISPLAY(info, link, start);
}

int main()
{
    char info[13] = {"  OT  X NIE "};
    int link[13] = {-2, -2, 5, -1, -2, 10, 9, -2, 2, 3, 6, -2, -2};
    int start = 8;
    DELETE(info, link, start);
}