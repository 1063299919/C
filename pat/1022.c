#include <stdio.h>

int main()
{
    int a,b,d;
    long long sum,result;
    scanf("%d %d %d",&a,&b,&d);
    sum = a+b;
    for (int i = 1; sum != 0; i*=10)
    {
        result += sum%d*i;
        sum /= d;
    }
    printf("%lld",result);
}