#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[])
{
    char chs[20];
    scanf("%s", chs);
    int len = strlen(chs);
    for (int i = 0; i < len; i++)
    {
        putchar(chs[len - i - 1]);
    }

    return 0;
}
