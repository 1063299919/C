#include <stdio.h>
#include<conio.h>
int main()
{
    int c;
    c = getchar();
    while (c != EOF)
    {
        if(c!=32)
            putch(c);
        else
            printf("\n");
        //printf("%d",(c != EOF));
        c = getchar();
    }
    return 0;
}
