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
    if(marks>=80) printf("A+\n");
    else if(marks>=75) printf("A\n");
    else if(marks>=70) printf("A-\n");
    else if(marks>=65) printf("B+\n");
    else if(marks>=60) printf("B\n");
    else if(marks>=55) printf("B-\n");
    else if(marks>=50) printf("C+\n");
    else if(marks>=45) printf("C\n");
    else if(marks>=40) printf("D\n");
    else printf("F\n");
    printf("The obtained grade is %.2f",grade);
}