//Palindrome String
#include<stdio.h>
#include<string.h>
int main()
{
    char s[100],s2[100];
    printf("Enter your string: ");
    gets(s);
    strcpy(s2,s);
    strrev(s2);

    int d= strcmp(s,s2);
    if(d==0) printf("Your input is palindrome.");
    else printf("Your input is not palindrome.");
}