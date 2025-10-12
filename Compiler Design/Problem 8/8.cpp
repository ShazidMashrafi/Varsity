#include<bits/stdc++.h>
using namespace std;

bool isOperator(string token) {
    string operators[] = {"+", "-", "*", "/", "%", 
                        "==", "!=", ">", "<", ">=", "<=", 
                        "&&", "||", "!", "=", 
                        "|", "&", "~", "^",
                        "++", "--"};
    for(string s : operators) {
        if(s == token) {
            return true;
            break;
        }
    }
    return false;
}

bool  isConstant(string token) {
    bool f = true;
    for(char ch : token) {
        if(!isdigit(ch)) {
            if(f && ch == '.') {
                f = false;
            }
            else {
                return false;
            }
        }
    }
    return true;
}

bool isIdentifier(string token) {
    if(!isalpha(token[0]) && token[0] != '_') return false;
    for(int i = 1; i < token.size(); ++i) {
        if(!isalnum(token[i]) && token[i] != '_') return false;
    }
    return true;
}

int main()
{
    while(true) {
        string token;
        cout <<"Enter a token: ";
        cin >> token;

        if(isOperator(token)) {
            cout << token << " is an operator" << endl;
        } else if(isConstant(token)) {
            cout << token << " is a constant" << endl;
        } else if(isIdentifier(token)) {
            cout << token << " is an identifier" << endl;
        } else {
            cout << token << " is not recognized as operator, constant or identifier" << endl;
        }
    }
}