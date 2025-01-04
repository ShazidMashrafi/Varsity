// Printing a number triangle that has palindrome rows

#include <stdio.h>
int main()
{
    int no_rows, row, col;
input:
    printf("Enter the number of rows: ");
    scanf("%d", &no_rows);

    if (no_rows > 1)
    {
        for (row = 1; row <= no_rows; row++)
        {
            for(col=no_rows;col>row;col--)
            {
                printf("   ");
            }
            for (col = row; col < 2 * row; col++)
            {
                printf("%2d ", col);
            }
            for (col = 2 * (row - 1); col >= row; col--)
            {
                printf("%2d ", col);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Invalid input");
        goto input;
    }
}