#include<stdio.h>
#include<string.h>
int main()
{
    char array[1000];
    char c;
    int length,count;
    for(int j= 0; j<3; j++)
    {
        count = 0;
        gets(array);
        for (int i = 0; i < (length = strlen(array)); i++)
        {
            putchar(array[i]);
            if (array[i] == ' '||array[i] == '\t')
            {
                if(length-i + count >= 10)
                {
                    printf("\n");
                    count = 0;
                }
            }
            count ++;
            if (count%10 == 0 && count >0)
            {
                printf("\n");
                count = 0;
            }    
        }
    }
    
    
    //printf("%d",strlen(array));
}