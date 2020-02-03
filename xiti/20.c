#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void mitoa(int x,char *str)
{
    int power = 1024; //暂时定为2的10次方
    while (x/power == 0)
    {
        power /= 2;
    }
    //得到x能除的了的最大2的n次方
    for (     ; power != 0; power /= 2) //每次power除2
    {
        *(str++) = (x / power) + '0'; //保存二进制数的最前面位数
        x %= power;
    }
    *str = '\0';//末尾一定要补充一个结束符
}

int main()
{
    unsigned int x = 255;
    unsigned int y = 16;
    
    int p = 3;
    int n = 4;
    scanf("%u %u %d %d", &x, &y, &p, &n);
    char stringx[9];
    char stringy[9];

    mitoa(x, stringx);
    mitoa(y, stringy);
    int lx = strlen(stringx);
    int ly = strlen(stringy);
    for (int i = 0; i < n ; i++)
    {
        stringx[i + (lx - p - 1)] = stringy[ly - n];
    }
    
    x = strtol(stringx, NULL, 2);
    
    //printf("x is %s\n", stringx);
    printf("%u\n", x);

    
}