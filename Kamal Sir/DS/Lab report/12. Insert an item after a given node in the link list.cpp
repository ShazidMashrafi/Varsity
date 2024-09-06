// Insert an item after a given node in the link list
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

void INSERT(char info[], int link[], int start, int avail)
{
    cout << "Before insertion of the item: ";
    DISPLAY(info, link, start);

    char item, node;
    cout << "\nEnter the node and item: ";
    cin >> node >> item;
    int ptr = start;
    int save;
    while (ptr != -1)
    {
        if (node == info[ptr])
        {
            info[avail] = item;
            save = link[avail];
            link[avail] = link[ptr];
            link[ptr] = avail;
            avail = save;
        }
        ptr = link[ptr];
    }

    cout << "\nAfter insertion of the item: ";
    DISPLAY(info, link, start);
}

int main()
{
    int start, avail;
    start = 8;
    avail = 4;
    char info[13] = {"  OT  X NIE "};
    int link[12] = {7, 11, 5, -1, 0, 10, 9, 1, 2, 3, 6, -1};
    INSERT(info, link, start, avail);
}