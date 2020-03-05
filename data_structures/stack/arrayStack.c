/*栈也是一个抽象数据类型。 常用的栈运算有：
StackEmpty( );测试栈 S 是否为空。
StackFull( );测试栈 S 是否已满。
Stacktop( );返回栈 S 的栈顶元素。
Push( );在栈 S 的栈顶插入元素 $， 简称为将元素 入栈。
pop( );删除并返回栈 S 的栈顶元素， 简称为抛栈。
栈的应用非常广泛， 只要问题满足 LIFO原则， 就可以使用栈。 */
#include<stdio.h>
#include<stdlib.h>
typedef int StackItem;
typedef struct astack *Stack;
typedef struct astack
{
    int top;
    int maxtop;
    StackItem *data;
} Astack;

Stack StackInit(int size)
{
    Stack S = malloc(sizeof *S);
    S->data = malloc(size * sizeof(StackItem));
    S->maxtop = size;
    S->top = -1;
    return S;
}

int StackEmpty(Stack S)
{
    return S->top < 0;
}

int StackFull(Stack S)
{
    return S->top >= S->maxtop;
}

StackItem Stacktop(Stack S)
{
    if(StackEmpty(S))
        printf("Stack is empty");
    else
        return S->data[S->top];
}

void Push(StackItem x,Stack S)
{
    if (StackFull(S))
        printf("Stack is full");
    else
        S->data[++S->top] = x;
}

StackItem Pop(Stack S)
{
    if (StackEmpty(S))
        printf("Stack is empty");
    else
        return S->data[S->top--];
}
