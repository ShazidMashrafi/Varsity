//Matrix multiplication
#include<stdio.h>
int multiplyMatrices(int A[10][10],int B[10][10], int r1, int c1,int c2)
{
    int i,j,k,sum=0;
    int M[10][10];
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            for(k=0;k<c1;k++)
            {
                sum=sum+A[i][k]*B[k][j];
            }
            M[i][j]=sum;
            sum=0;
        }
    }
    printf("Multiplied matrix: \n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("%d ",M[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int r1,c1,r2,c2,i,j;
    int first[10][10],second[10][10];
    printf("Enter the number of rows and cols for first matrix: ");
    scanf("%d %d",&r1,&c1);
    printf("Enter the number of rows and cols for second matrix: ");
    scanf("%d %d",&r2,&c2);

    while(c1!=r2)
    {
        printf("\nDimension error!!\nNumber of rows for the second matrix need to be the same as number of columns of the first matrix.\nPlease input again.\n");
        printf("Enter the number of rows and cols for first matrix: ");
        scanf("%d %d",&r1,&c1);
        printf("Enter the number of rows and cols for second matrix: ");
        scanf("%d %d",&r2,&c2);
    }
    printf("Enter the elements for first matrix:\n");
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            printf("First matrix[%d][%d]: ",i+1,j+1);
            scanf("%d",&first[i][j]);
        }
        printf("\n");
    }
    printf("Enter the elements for second matrix:\n");
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            printf("Second matrix[%d][%d]: ",i+1,j+1);
            scanf("%d",&second[i][j]);
        }
        printf("\n");
    }
    multiplyMatrices(first,second,r1,c1,c2);
}