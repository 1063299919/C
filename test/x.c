#include <stdio.h>

void strcpy(char *s , char *t)
{
    while (*s++ = *t++)
        ;
}

void my_strcpy(char *s , char *t, int n)
{
    while (*s++ = *t++)
        ;
}


int main()
{
    char *s = "qwertyuiop";
    char *t = "iop";
    //printf("%d ", strlen(s));
    strcpy(s, t);
    printf("%s", s);
    return 0;
}
