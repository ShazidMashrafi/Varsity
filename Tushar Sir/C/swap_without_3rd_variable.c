//Swap numbers without third variable
#include<stdio.h>
int main()
{
    int num1,num2;
    printf("Enter two numbers: ");
    scanf("%d %d",&num1,&num2);
    printf("Before swaping numbers are %d %d\n\n",num1,num2);
    num1=num1+num2;
    num2=num1-num2;
    num1=num1-num2;

    printf("After swaping numbers are: %d %d\n",num1,num2);
    return 0;
}