// Insert an item at the beginning of a link list
#include <iostream>
using namespace std;

void DISPLAY(char info[], int link[], int start)
{
    int ptr=start;
    while(ptr!=-1)
    {
        cout<<info[ptr];
        ptr=link[ptr];
    }
}

void INSERT(char info[], int link[], int start,int avail)
{
    cout<<"Before insertion of the item: ";
    DISPLAY(info,link,start);
    
    char item;
    cout<<"\nEnter the item: ";
    cin>>item;
    info[avail]=item;
    link[avail]=start;
    start=avail;
    avail=link[avail];

    cout<<"\nAfter insertion of the item: ";
    DISPLAY(info,link,start);
}

int main()
{
    int start,avail;
    start=8;
    avail=4;
    char info[13]={"  OT  X NIE "};
    int link[13]={11,12,5,-1,7,10,9,0,2,3,6,1,-1};
    INSERT(info,link,start,avail);
}