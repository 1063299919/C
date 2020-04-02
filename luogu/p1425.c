#include<stdio.h>
int main(int argc, char const *argv[])
{
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int len = (c * 60 + d) - (a * 60 + b);
    printf("%d %d", len / 60, len % 60);
    return 0;
}
