#include <iostream>
using namespace std;

class VariableDemo {
public:
    int instanceVar;
    static int staticVar;
    VariableDemo(int val) : instanceVar(val) {}
    void demonstrateVariables() 
    {
        int localVar = 10;
        cout << "Local Variable: " << localVar << endl;
        cout << "Instance Variable: " << instanceVar << endl;
        cout << "Static Variable: " << staticVar << endl;
    }
};

int VariableDemo::staticVar = 1;

int main() 
{
    VariableDemo obj(30);
    obj.demonstrateVariables();
    return 0;
}