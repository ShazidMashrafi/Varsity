//Matrix Addition and Substraction.
#include<stdio.h>
int addMatrices (int M[10][10], int N[10][10],int r, int c)
{
    int C[10][10],i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
           C[i][j]=M[i][j]+N[i][j];
        }
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ",C[i][j]);
        }
        printf("\n\n");
    }
}
int main()
{
    int no_rows,no_cols,i,j;
    int A[10][10],B[10][10];
    printf("Enter the number of rows: ");
    scanf("%d",&no_rows);
    printf("Enter the number of columns: ");
    scanf("%d",&no_cols);

    printf("Enter the elements of Matrix A:\n");
    for(i=0;i<no_rows;i++)
    {
        for(j=0;j<no_cols;j++)
        {
            printf("A[%d][%d]: ",i,j);
            scanf("%d",&A[i][j]);
        }
        printf("\n");
    }
    printf("Enter the elements for Matrix B:\n");
   for(i=0;i<no_rows;i++)
    {
        for(j=0;j<no_cols;j++)
        {
            printf("B[%d][%d]: ",i,j);
            scanf("%d",&B[i][j]);
        }
        printf("\n");
    }
    addMatrices(A,B,no_rows,no_cols);
}