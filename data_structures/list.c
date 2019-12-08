#include<stdio.h>
#include<stdlib.h>
struct Book
{
    char title[100];
    struct Book *next;    
};

void getInput(struct Book *book)
{
    printf("����������");
    scanf("%s",book->title);
}

void addBook(struct Book **library)
{
    struct Book *book, *temp;
    book = (struct Book *)malloc(sizeof(struct Book));
    if(book == NULL)
    {
        printf("�ڴ����ʧ��\n");
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
        printf("����%s\n", book->title);
        book = book->next;
        count++;
    }
    
}
void releaseLibrary(struct Book *library)
{
    while ((library != NULL))
    {
        free(library);
        library = library->next;//library�Ѿ����ͷ��ˣ��˴�����
    }
    
}
int main()
{
    struct Book *library = NULL;
    int ch;
    while (1)
    {
        printf("�Ƿ���Ҫ¼���鼮��Ϣ��y/n) : \n");
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
    printf("�Ƿ���Ҫ��ӡ�鼮��Ϣ��y/n) : \n");
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