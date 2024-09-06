#include<stdio.h>
int main()
{
    int i,j,k,n,c;
    printf("Enter N: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        c=1;
        for(k=n-i;k>0;k--)
        {
            printf("  ");
        }
        for(j=1;j<=i;j++)
        {
            printf("%2d  ",c);
            c=c*(i-j)/j;
        }
        printf("\n");
    }
}