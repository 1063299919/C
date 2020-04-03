#include<stdio.h>

int factorial(int x)
{
    int sum = 1;
    for (int i = 1; i <= x; i++)
    {
        sum *= i;
    }
    return sum;
}

int main(int argc, char const *argv[])
{

    int sum = 0;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        sum += factorial(i);
    }
    printf("%d", sum);
    return 0;
}
