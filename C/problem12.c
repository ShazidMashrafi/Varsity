#include <stdio.h>

int fibo(int n)
{
    if (n <= 0)
        return 0;
    else if (n == 1 || n == 2)
        return 1;
    else
        return fibo(n - 1) + fibo(n - 2);
}

int main()
{
    int num, i, ans;
    printf("Enter N: ");
    scanf("%d", &num);

    for (i = 1; i <= num; i++)
    {
        ans = fibo(i);
        printf("%d ", ans);
    }
    return 0;
}