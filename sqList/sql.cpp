#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct sqList
{
    // int *element;
    int data[10];
    int length;
};

void sqListFilling(sqList *&k)
{
    int n = 0;
    srand((unsigned)time(NULL));
    if(k->length>0){
        for (int i = 0; i < k->length; i++)
        {
            n = rand()%20;
            k->data[i] = n;
        }
    }
};
int main()
{
    sqList *L = (sqList *)malloc(sizeof(sqList));
    L->length = 20;
    sqListFilling(L);
    for (int i = 0; i < L->length; i++)
    {
        printf("%d\n", L->data[i]);
    }
}