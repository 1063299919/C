#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    unsigned int x = 255;
    unsigned int y = 16;
    int p = 3;
    int n = 4;
    //scanf("%u %u %d %d", &x, &y, &p, &n);
    x >>= (p+1);
    x <<= (p+1);
    y &= ~(~0<<n);
    x |= y;
    printf("%u\n", x);
   
}