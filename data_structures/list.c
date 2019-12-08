#include<stdio.h>
#include<stdlib.h>
struct Book
{
    char title[100];
    struct Book *next;    
};

void getInput(struct Book *book)
{
    printf("请输入书名");
    scanf("%s",book->title);
}

void addBook(struct Book **library)
{
    struct Book *book, *temp;
    book = (struct Book *)malloc(sizeof(struct Book));
    if(book == NULL)
    {
        printf("内存分配失败\n");
        exit(1);
    }
    getInput(book);
    if (*library != NULL)
    {
        temp = *library;
        *library = book;
        book->next = temp;
    }
    else
    {
        *library = book;
        book->next = NULL;
    }
    
}


void printLibaray(struct Book *library)
{
    struct Book *book;
    int count = 1;

    book = library;
    while (book != NULL)
    {
        printf("Book%d: ", count);
        printf("书名%s\n", book->title);
        book = book->next;
        count++;
    }
    
}
void releaseLibrary(struct Book *library)
{
    while ((library != NULL))
    {
        free(library);
        library = library->next;//library已经被释放了，此处有误。
    }
    
}
int main()
{
    struct Book *library = NULL;
    int ch;
    while (1)
    {
        printf("是否需要录入书籍信息（y/n) : \n");
        do
        {
            ch = getchar();
        } while (ch != 'y' && ch != 'n');

        if(ch == 'y')
        {
            addBook(&library);
        }
        else
        {
            break;
        }
        
    }
    printf("是否需要打印书籍信息（y/n) : \n");
    do
    {
        ch = getchar();
    }while (ch != 'y' && ch != 'n');
    if(ch == 'y')
    {
        printLibaray(library);
    }

    releaseLibrary(library);

    return 0;
}