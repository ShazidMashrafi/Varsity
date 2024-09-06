//Grading point of Bangladeshi universities using switch

#include<stdio.h>
int main()
{
    int marks,m,r;
    float grade;
    printf("Enter the marks of the student: ");
    scanf("%d",&marks);
    while(marks>100)
    {
        printf("Wrong input\nEnter corrct marks: ");
        scanf("%d",&marks);
    }
    m=marks/10;
    r=marks%10;
    switch(m)
    {
        case 10:
        case 9:
        case 8:
                grade=4;
                break;
        case 7:
            if(r>=5)
                grade=3.75;
            else grade=3.50;
            break;
        case 6:
            if(r>=5)
                grade=3.25;
            else grade=3.00;
            break;
        case 5:
            if(r>=5)
                grade=2.75;
            else grade=2.50;
            break;
        case 4:
            if(r>=5)
                grade=2.25;
            else grade=2.00;
            break;
        case 3:
        case 2:
        case 1:
        case 0:
            grade=0.00;
            break;
    }
    printf("Obtained grade is %.2f",grade);
}