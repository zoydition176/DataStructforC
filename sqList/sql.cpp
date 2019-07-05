#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 常量定义 */ 
#define MAXSIZE 100


struct sqList
{
    // int *element;
    int data[MAXSIZE];
    int length;
};

// 初始化一个随机的顺序表，最大表长100
void sqListFilling(sqList *&k,int q)
{
    int n = 0;
    k->length = q;
    srand((unsigned)time(NULL));
    if (q > 0)
    {
        for (int i = 0; i < k->length; i++)
        {
            n = rand()%30;
            k->data[i] = n;
        }
    }
};

// 顺序表元素获取
int getElement(int i){

}

int main()
{
    sqList *L = (sqList *)malloc(sizeof(sqList));
    sqListFilling(L,10);
    for (int i = 0; i < L->length; i++)
    {
        printf("%d\n", L->data[i]);
    }
}