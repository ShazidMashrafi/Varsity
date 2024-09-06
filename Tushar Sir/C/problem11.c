#include<stdio.h>
int fact(int n)
{
    if(n==1)
        return 1;
    else
        return n*fact(n-1);
}
int main()
{
   int num,result;
   printf("Enter N: ");
   scanf("%d",&num);
   result=fact(num);
   printf("Factorial of %d is %d",num,result);
}