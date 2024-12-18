//Average of two float, Bitwise-AND, Bitwise-OR, Left shifting, Right shifting.
#include<stdio.h>
int main()
{
    int i1,i2;
    float f1,f2,avg;
    printf("Please input i1: ");
    scanf("%d",&i1);
    printf("Please input i2: ");
    scanf("%d",&i2);
    printf("Please input f1: ");
    scanf("%f",&f1);
    printf("Please input f2: ");
    scanf("%f",&f2);

    avg=(f1+f2)/2;
    printf("\nAverage of f1 and f2 is: %.2f\n",avg);
    printf("Bitwise-OR and Bitwise-AND of i1 and i2 is: %d and %d\n", i1|i2, i1&i2);
    printf("i1 shifted left by 2 places: %d and i2 shifted right by 1 places is: %d\n\n",i1<<2,i2>>1);
    return 0;
}