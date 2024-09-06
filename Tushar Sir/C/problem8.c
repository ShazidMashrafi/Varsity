#include<stdio.h>
int main()
{
    int n,i,j;
    printf("Please input N: ");
    scanf("%d",&n);
    for(i=n;i>=1;i--)
    {
        for(j=1;j<=n-i;j++)
        {
            printf("  ");
        }
        for(j=1;j<2*i;j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}