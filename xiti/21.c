#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    unsigned int x = 16;
    int p = 3;
    int n = 4;
    int temp;
    int z;
    
    scanf("%u %d %d", &x, &p, &n);
    temp = (~(~0 << (p + 1)))>>(p+1-n)<<(p+1-n);
    
    z = x & temp;
    x = x & ~temp;
    z = ~z & temp;
    x = x | z;
    
    printf("%d",x);

    
    return 0;
}