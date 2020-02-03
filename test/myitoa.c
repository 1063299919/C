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
    int x = 255;
    char str[10];
    mitoa(x, str);
    printf("%s", str);
}