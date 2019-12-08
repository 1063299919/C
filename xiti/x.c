#include<stdio.h>
int main()
{
    int c;
    int i = 0;
    int wordsNumber[16] = {0,};
    int maxNumber = 0;
    c = getchar();
    while(c != EOF)
    {
        if ((c != 9)&&(c != 10)&&(c != 32))
        {
            i++; 
        }
        else
        {
            if(i>=15)
                wordsNumber[15] +=1;
            else
                wordsNumber[i] += 1;
            i = 0;
        }
        
        c = getchar();
    }
    for (int i = 1; i < 15; i++)
    {
        if(maxNumber <= wordsNumber[i])
            maxNumber = wordsNumber[i];
    }
    
    for (int i = 1; i <= 14; i++)
    {
        printf("%5d - %5d : ",i,wordsNumber[i]);
        for (int j = 0; j < (wordsNumber[i]*15/maxNumber); j++)
        {
            printf("*");
        }
        printf("\n");
    }
    if(wordsNumber[15] != 0)
        printf("There are %d words >= 15",wordsNumber[15]);
    return 0;
}