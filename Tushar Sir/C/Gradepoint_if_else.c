//Grading point for Bangladesh universities using if else

#include<stdio.h>
int main()
{
    int marks;
    float grade;
    printf("Enter the marks of the student: ");
    scanf("%d",&marks);
    while(marks>100)
    {
        printf("Wrong input\nEnter corrct marks: ");
        scanf("%d",&marks);
    }
    if(marks>=80) grade=4.0;
    else if(marks>=75) grade=3.75;
    else if(marks>=70) grade=3.50;
    else if(marks>=65) grade=3.25;
    else if(marks>=60) grade=3.00;
    else if(marks>=55) grade=2.75;
    else if(marks>=50) grade=2.50;
    else if(marks>=45) grade=2.25;
    else if(marks>=40) grade=2.00;
    else grade=0.00;
    printf("The obtained grade is %.2f",grade);
}