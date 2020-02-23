#include <stdio.h>

void istrcpy(char *s , char *t)
{
    while (*s++ = *t++)
        ;
}

int main()
{
    char *s = "qwe";
    char t[] = "iop";
    char *ps = s;
    char *pt = t;
    istrcpy(t, s);

    return 0;
}
