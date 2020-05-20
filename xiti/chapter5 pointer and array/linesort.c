#include <stdio.h>
#include <string.h>

#define MAX_ARRAY_NUM	10
#define MAX_LINE_LEN	100
#define MAX_DEST_NUM	1000

char *g_szArray[MAX_ARRAY_NUM];
char g_szDest[MAX_DEST_NUM];

int GetLine(char *szLine, int *pnLineLen);
int ReadLines(char *szArray[], int *pnArrayNum);
void Swap(char *v[], int i, int j);
void Qsort(char *v[], int left, int right);
void WriteLines(char *szArray[], int nArrayNum);

int main()
{
	int nArrayNum = 0;

	if (ReadLines(g_szArray, &nArrayNum) >= 0)
	{
		Qsort(g_szArray, 0, nArrayNum-1);
		WriteLines(g_szArray, nArrayNum);
	}
	else
		printf("error: read lines too big to sort\n");

	return 0;
}

int ReadLines(char *szArray[], int *pnArrayNum)
{
	char szLine[MAX_LINE_LEN] = {0};
	int nLineLen = 0;
	char *pDest = g_szDest;
	char *pDestStop = g_szDest + MAX_DEST_NUM;

	while (GetLine(szLine, &nLineLen) > 0)
	{
		if (*pnArrayNum >= MAX_ARRAY_NUM || pDest + nLineLen >= pDestStop)
			return -1;
		else
		{
			szLine[nLineLen-1] = '\0';
			strcpy(pDest, szLine);
			szArray[(*pnArrayNum)++] = pDest;
			pDest += nLineLen;
		}
	}

	return *pnArrayNum;
}

int GetLine(char *szLine, int *pnLineLen)
{
	int c = 0;
	char *pLine = szLine;
	int nMaxLen = MAX_LINE_LEN;

	while (--nMaxLen > 0 && (c = getchar()) != EOF && c != '\n')
		*szLine++ = c;
	if (c == '\n')
		*szLine++ = c;
	*szLine = '\0';
	*pnLineLen = szLine - pLine;

	return *pnLineLen;
}

void Qsort(char *v[], int left, int right)
{
	int i = 0;
	int last = 0;

	if (left >= right)
		return;
	Swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			Swap(v, ++last, i);
	Swap(v, left, last);
	Qsort(v, left, last-1);
	Qsort(v, last+1, right);
}

void Swap(char *v[], int i, int j)
{
	char *temp = NULL;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void WriteLines(char *szArray[], int nArrayNum)
{
	while (nArrayNum-- > 0)
		printf("%s\n", *szArray++);
}
