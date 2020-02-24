#include <stdio.h>

#define MAXLEN 100

int strlen(char *s)
{
    char *p = s;

    while( *p++ )
        ;
    return p - s;
}

void strncpy(char *s , char *t, int n)
{
    for (int i = 0; i < n; i++)
        *s++ = *t++;
}


/* strcmp:  return <0 if s<t, 0 if s==t, >0 if s>t */
int strncmp(char *s ,char *t,int n)
{
    for (int i = 0;*s == *t && i< n; s++,t++,i++)
        if (*s == '\0' || *t == '\0')
            return 0;
    return *s - *t;
}


//将t复制到s尾部
void strncat(char *s ,char *t,int n)
{
    while (*s)
        s++;
    for (int i = 0; i < n; i++)
        *s++ = *t++;
    *s = '\0';
}


int main()
{
    char s[MAXLEN] = "?(~△~?)";
    char t[MAXLEN] = "(?~△~)?";
    //scanf("%s", s);
    //scanf("%s", t);
    int customarylens = strlen(s)-1;
    int customarylent = strlen(t)-1;
    int cmp;

    cmp = strncmp(s, t, customarylent);
    if (cmp > 0)
        printf("s > t");
    else if (cmp == 0)
        printf("s == t");
    else if (cmp < 0)
        printf("s < t");
    putchar('\n');

    strncat(s, t, customarylent);
    printf("%s\n", s);

    strncat(t, s+customarylent, customarylens);
    printf("%s\n", t);

    strncpy(t, s, customarylent);
    printf("%s\n", t);

    cmp = strncmp(s, t, customarylent);
    if (cmp > 0)
        printf("s > t");
    else if (cmp == 0)
        printf("s == t");
    else if (cmp < 0)
        printf("s < t");
    putchar('\n');

}
