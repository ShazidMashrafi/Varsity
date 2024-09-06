// Store a text message in a file using fixed length structure
#include <iostream>
#include <cstdio>
using namespace std;

void SAVE(char text[])
{
    FILE *outfile = fopen("output.txt", "w");
    fputs(text, outfile);
    fclose(outfile);
}

int main()
{
    int n;
    cout << "Enter length of the text: ";
    cin >> n;
    cin.ignore();
    char text[n + 1];
    cout << "\nEnter message: ";
    cin.getline(text, n);
    SAVE(text);
}