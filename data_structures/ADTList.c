#include<stdio.h>
#include<stdlib.h>
/*
用数组实现表时，为了适应表元素类型的变化，将表类型list定义为一个结构。在该结构
中，用ListItem来表示用户指定的元素类型。其数据成员为n,maxsize和元素数组table
用L记录表长。当表为空时n的值为0,maxsize表示表的最大长度。table是记录表中元素
的数组。表中第k个元素(1<=k<=n)存储在数组的第k-1个单元中.
*/

typedef int Listitem;

typedef struct alist *List;
typedef struct alist 
{
    int n;
    int maxsize;
    Listitem *table;   //表的元素数组
}Alist;


List ListInit( int size);                   //表结构初始化
int ListEmpty( List L);                    //测试表L是否为空
int ListLength( List L);                   //表L的长度
Listitem ListRetrieve( int k, List L);     //返回表L的位置k处的元素
int ListLocate( Listitem x, List L);       //元素x在表L中的位置
void listinsert(int k, Listitem x, List L);//在表L的位置k之后插入元素x
Listitem ListDelete( int k, List L);       //从表L中删除位置k处的元素
void Printlist( List L);                   //按位置次序输出表L中元素


List ListInit( int size)
{
    List L = malloc(sizeof *L);
    L->table = malloc(size*sizeof(Listitem));
    L->maxsize = size;
    L->n = 0;
    return L;
}//表结构初始化函数List ListInit( int size)分配大小为size的空间给表数组table并返回初始化为空的表。

int ListEmpty(List L)
{
    return L->n == 0;
}//测试表L是否为空

int ListLength(List L)
{
    return L->n;
}//表L的长度

int ListLocate( Listitem x, List L)
{
    int i;
    for (int i = 0; i < (L->n); i++)
    {
        if (L->table[i] == x)
        {
            return ++i;
        }
    }
    return 0;
}//返回表L的位置k处的元素

Listitem ListRetrieve( int k, List L)
{
    if(k <1 || k > (L->n))
        Error("out of bound");
    return L-> table[k - 1];
}//返回表L的位置k处的元素

void listinsert(int k, Listitem x, List L)
{
    int i;
    if( k<0 || k>(L->n))
        Error("out of bound");
    if( L->n == L->maxsize)
        Error("out of bound");
    for (int i = (L->n) - 1; i > k; i++)
    {
        L->table[i+1] = L->table[i];
    }
    L->table[k] = x;
    (L->n) ++;
    
}//在表L的位置k之后插入元素x

Listitem ListDelete( int k, List L)
{
    int i;
    Listitem x;
    if( k<1 || k>(L->n))
        Error("out of bound");
    x = L->table[k-1];
    for (int i = k; i < L->n; i++)
    {
        L->table[i-1] = L->table[i];
    }
    L->n --;
    return x;
    
}//从表L中删除位置k处的元素

void PrintList(List L)
{
    int i;
    for (int i = 0; i < L->n; i++)
    {
        ItemShow(L->table[i]);
    }
    
}