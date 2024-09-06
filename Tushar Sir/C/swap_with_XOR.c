//Swap two numbers using bitwise XOR
#include<stdio.h>
int main()
{
    int a,b;
    printf("Enter first number: ");
    scanf("%d",&a);
    printf("Enter second number: ");
    scanf("%d",&b);
    printf("Before swaping numbers are %d %d\n",a,b);
    a=a^b;
    b=a^b;
    a=a^b;
    printf("After swaping numbers are %d %d\n",a,b);
    return 0;
}