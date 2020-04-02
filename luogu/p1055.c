#include<stdio.h>
#include<ctype.h>
int main(int argc, char const *argv[])
{
    char chs[14];
    scanf("%s", chs);
    int sum;
    char last;
    for (int i = 0,j = 1; i < 11; i++)
    {
        if (isdigit(chs[i]))
        {
            sum += (chs[i] - '0') * j++;
        }
    }
    if (sum%11==10)
    {
        last = 'X';
    }
    else{
        last = sum % 11 + '0';
    }

    if (chs[12] == last)
    {
        printf("Right");
    }
    else
    {
        chs[12] = last;
        printf("%s", chs);
    }

}
