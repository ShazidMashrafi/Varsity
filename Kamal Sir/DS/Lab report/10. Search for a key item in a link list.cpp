// Search for a key item in a link list
#include <iostream>
using namespace std;

void FIND(char info[], int link[], int start)
{
    char key;
    cout << "\nEnter the key item: ";
    cin >> key;
    int ptr = start;
    while (ptr != -1)
    {
        if (info[ptr] == key)
        {
            cout << "\nFound at position: " << ptr + 1 << endl;
            return;
        }
        ptr = link[ptr];
    }
    cout << "\nKey not found" << endl;
}

int main()
{
    int start;
    char info[13] = {"  OT  X NIE "};
    int link[13] = {-2, -2, 5, -1, -2, 10, 9, -2, 2, 3, 6, -2, -2};
    start = 8;
    FIND(info, link, start);
}