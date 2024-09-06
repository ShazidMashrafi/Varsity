// Palindrome check using array
#include<stdio.h>
int main()
{
    int i,n,len=0,flag=0;
    int arr[20];
    printf("Enter your number: ");
    scanf("%d",&n);
    for(i=0;n>0;i++)
    {
        arr[i]=n%10;
        n/=10;
        len++;
    } 
    for(i=0;i<len/2;i++)
    {
        if(arr[i]!=arr[len-1-i])
        {
            flag++;
            break;
        }
    }
    if(flag==0) printf("The number is palindrome.\n");
    else printf("The number is not palindrome.\n");
}