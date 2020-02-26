#include <stdio.h>

typedef struct node
{
    int address;
    int data;
    int next;
    int order;
} node;

int main()
{
    int firstadress;
    int adress;
    int count = 0;
    int n;
    int k;
    int temp;
    scanf("%d %d %d", &firstadress, &n, &k);
    temp = firstadress;
    node list[100000];
    for (int i = 0; i < 100000; i++)
    {
        list[i].data = 0;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &adress);
        list[adress].address = adress;
        scanf("%d %d",  &list[adress].data, &list[adress].next);
    }
    for (int i = 1; list[temp].data!=0 ; i++)
    {
        list[temp].order = i;
        temp = list[temp].next;
        count++;
    }
    node list2[count];
    temp = firstadress;
    for (int i = 0; i < count; i++)
    {
        list2[i] = list[temp];
        temp = list[temp].next;
    }
    int position = k-1;

    for (int i = 0; i < count/k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            printf("%05d %d ", list2[position].address, list2[position].data);
            if (position - 1 == -1)
            {
                if (count/k>=2)
                {
                    if(list2[2*k-1].address == -1)
                        printf("-1\n");
                    else
                        printf("%05d\n", list2[2*k-1].address);
                }
                else if (count == k)
                {
                    if(list2[k-1].next == -1)
                        printf("-1\n");
                    else
                        printf("%05d\n", list2[k-1].next);
                }
                else if(count / k == 1 && count != k&&count != 2*k)
                {
                    if(list2[k].address == -1)
                        printf("-1\n");
                    else
                        printf("%05d\n", list2[k].address);
                }

            }
            else if (j == (k-1)&&(position + k)== count)
            {
                printf("-1\n");
            }
            else
            {
                printf("%05d\n", list2[position-1].address);
            }
            position--;
        }
        position += (k + 2);
    }
    if (count % k != 0)
    {
        for (int i = 0; i < count%k; i++)
        {
            if (list2[i + count-(count%k)].next == -1)
            {
                printf("%05d %d -1\n", list2[i + count-(count%k)].address, list2[i + count-(count%k)].data);
            }
            else
                printf("%05d %d %05d\n", list2[i + count-(count%k)].address, list2[i + count-(count%k)].data,list2[i + count-(count%k)].next);
        }

    }


}
