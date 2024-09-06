#include <stdio.h>
int main()
{
    char s[100];
    int i, j, len, flag = 0;
    printf("Enter your string: ");
    scanf("%s",s);
    len=strlen(s);
    if (len > 1)
    {
        for (i = 0; i < len / 2; i++)
        {
            if (s[i] != s[len - i - 1])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            printf("The string is palindrome.\n");
        else
            printf("The string is not palindrome.\n");
    }
    else printf("Wrong input. Run again\n");
}