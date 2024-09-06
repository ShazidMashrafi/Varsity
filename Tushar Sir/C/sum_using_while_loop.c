#include<stdio.h>
int main()
{
    int i=0,n,sum=0;
    printf("Enter N:");
    scanf("%d",&n);
    while(i<=n)
    {
        sum=sum+i;
        i++;
    }
    printf("Sum= %d\n",sum);
    return 0;
}