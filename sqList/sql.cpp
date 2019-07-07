#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 常量定义 */ 
#define MAXSIZE 100
#define DONE 1
#define ERROR 0

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

// 顺序表对应下标元素获取
int findElement(sqList *k, int i)
{
    if(i>=0 && i<=k->length){
        printf("THE ELEMENT YOU FIND IS %d\n", k->data[i]);
        return DONE;
    }else{
        return ERROR;
    }
};

int main()
{
    int start = DONE;
    int choice;
    sqList *L = (sqList *)malloc(sizeof(sqList));
    sqListFilling(L,10);
    // for (int i = 0; i < L->length; i++)
    // {
    //     printf("%d\n", L->data[i]);
    // }
    while (start)
    {
        printf("*****欢迎使用c与数据结构第一章线性表操作演示程序*****\n");
        printf("*****请选择操作*****\n");
        printf("*****按 1 :创建顺序表*****\n");
        printf("*****按 1 :创建顺序表*****\n");
        printf("按 9： 退出顺序表操作演示程序\n");
        scanf("%d", &choice);
        switch (choice)
        {
            
        }
    }
    
}