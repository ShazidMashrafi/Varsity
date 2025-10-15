#include<bits/stdc++.h>
using namespace std;

int main()
{
    ifstream file("input.txt");
    
    int charCount = 0, wordCount = 0, lineCount = 0;
    string line;
    
    while(getline(file, line)) {
        lineCount++;
        charCount += line.length();
        
        bool inWord = false;
        for(char ch : line) {
            if(isspace(ch)) {
                inWord = false;
            } else if(!inWord) {
                wordCount++;
                inWord = true;
            }
        }
    }
    
    file.close();
    
    cout << "Number of characters: " << charCount << endl;
    cout << "Number of words: " << wordCount << endl;
    cout << "Number of lines: " << lineCount << endl;
    
    return 0;
}