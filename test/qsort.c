#include <stdio.h>
#include <stdlib.h>

//void qsort(void *base,size_t num,size_t width,int (*compare)(const void*,const void*))
//qsort 函数一共有四个参数，
// 第一个参数是数组的首地址，
// 第二个参数是数组的元素个数，
// 第三个参数是每个元素的字节数，
// 第四个参数是一个指向函数的指针，
// 表示调用的比较函数的函数名。
// size_t代表unsigned int

int compare(const void* a,const void* b)
//比较函数，传入const void指针，返回值为int；
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int array[10] = {1, 4, 5, 3, 2, 8, 9, 7, 6, 0};
    qsort(array, sizeof(array)/sizeof(int), sizeof(int), compare);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", array[i]);
    }
    
}