// Implement a queue where one can insert or delete item
#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

void DISPLAY(char (&queue)[][1000], int &front, int &rear, int max)
{
    if (front == -1)
    {
        cout << "Queue is empty." << endl << endl;
        return;
    }
    cout << "The data stored in the queue are:" << endl;
    if (front <= rear)
    {
        for (auto i = front; i <= rear; ++i)
            cout << queue[i] << endl;
    }
    else
    {
        for (int i = front; i < max; ++i)
            cout << queue[i] << endl;
        for (int i = 0; i <= rear; ++i)
            cout << queue[i] << endl;
    }
    cout << endl;
}

void INSERT(char (&queue)[][1000], int &front, int &rear, int max)
{
    if ((front == 0 && rear == max - 1) || front == rear + 1)
    {
        cout << "No space in queue." << endl << endl;
        return;
    }
    char data[1000];
    cin.ignore();
    cout << "Enter data: ";
    cin >> data;
    if (rear == -1)
        front = rear = 0;
    else if (rear == max - 1)
        rear = 0;
    else
        rear++;
    strcpy(queue[rear], data);
    cout << "Entry successful." << endl << endl;
}

void DELETE(char (&queue)[][1000], int &front, int &rear, int max)
{
    if (front == -1)
    {
        cout << "Queue is already empty." << endl << endl;
        return;
    }
    char data[1000];
    strcpy(data, queue[front]);
    if (front == rear)
        front = rear = -1;
    else if (front == max - 1)
        front = 0;
    else
        front++;
    cout << "Data remove successful." << endl;
    cout << "Removed data is: " << data << endl << endl;
}

void QUEUE(char (&queue)[][1000], int &front, int &rear, int max)
{
    cout << "What do you want to do?" << endl;
    cout << "1.Insert element" << endl;
    cout << "2.Delete element" << endl;
    cout << "3.Display queue" << endl;
    cout << "4.Exit" << endl;
    cout << "Enter your choice: ";
    int ch;
    cin >> ch;
    cout << endl;
    if(ch==1)
        INSERT(queue, front, rear, max);
    else if(ch==2)
        DELETE(queue, front, rear, max);
    else if(ch==3)
        DISPLAY(queue, front, rear, max);
    else if(ch==4)
        return;
    else
        cout << "Invalid input. Try again." << endl << endl;
    QUEUE(queue, front, rear, max);
}

int main()
{
    int max, front = -1, rear = -1;
    cout << "Enter the maximum size of queue: ";
    cin >> max;
    char queue[max][1000];
    QUEUE(queue, front, rear, max);
}