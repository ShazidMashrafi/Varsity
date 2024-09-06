#include<stdio.h>
int main()
{
    int i=0,n,sum=0;
    printf("Enter N:");
    scanf("%d",&n);
    do
    {
        sum=sum+i;
        i++;
    }while(i<=n);
    printf("Sum= %d\n",sum);
    return 0;
}