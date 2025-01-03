// Traverse items in a link list data structure
#include <iostream>
using namespace std;

void TRAVERSE(char info[], int link[], int start)
{
    int ptr = start;
    while(ptr != -1)
    {
        cout << info[ptr];
        ptr = link[ptr];
    }
}

int main()
{
    char info[13] = {"  OT  X NIE "};
    int link[13] = {-2, -2, 5, -1, -2, 10, 9, -2, 2, 3, 6, -2, -2};
    int start = 8;
    TRAVERSE(info, link, start);
}