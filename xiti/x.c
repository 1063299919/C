#include<stdio.h>

void printd(int n);

int main()
{
    printd(985);
}

void printd(int n)
{
    if(n < 0)
    {
        putchar('-');
        n = -1;
    }
}