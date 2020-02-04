#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    unsigned int x = 170;
    int n = 1;
    scanf("%u %d", &x, &n);
    int temp;
    temp = (~(~0 << n) & x)<<n;
    x >>= n;
    x |= temp;
    printf("%d",x);

    
    return 0;
}