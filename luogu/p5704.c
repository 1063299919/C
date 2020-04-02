#include<stdio.h>
#include<ctype.h>

int main(int argc, char const *argv[])
{
    char ch;
    scanf("%c", &ch);
    printf("%c", toupper(ch));
    return 0;
}
