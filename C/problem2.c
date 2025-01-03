// Sum of digits.
#include<stdio.h>
int main()
{
    int num,temp,r,sum=0;
    printf("Enter your three digit number: ");
    scanf("%d",&num);
    if(num>99 && num <1000)
    {
    temp=num;
    while(temp!=0)
    {
        r=temp%10;
        sum=sum+r;
        temp=temp/10;
    }
    printf("The sum of digits is: %d",sum);
    }
    return 0;
}