#include <stdio.h>

int main()
{
    char c;

    while ((c = getchar ()) != EOF)
    {
        putchar(c);
        printf("  %d\n" ,(getchar () != EOF));
    }
    return 0;
}
