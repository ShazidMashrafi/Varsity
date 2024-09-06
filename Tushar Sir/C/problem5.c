//Print N number of prime numbers
#include<stdio.h>
int main()
{
    int n,i=2,j,count=1,flag;
    printf("Enter N: ");
    scanf("%d",&n);
    while(count<=n)
    {
        flag=0;
        for(j=2;j<i;j++)
        {
            if(i%j==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("%d ",i);
            count++;
        }
        i++;
    }
}