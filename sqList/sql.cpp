#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 常量定义 */ 
#define MAXSIZE 100
#define DONE 1
#define ERROR 0

struct sqList
{
    struct sqList *address;
    int data[MAXSIZE];
    int length;
};

// 初始化一个随机的顺序表，最大表长100
void sqListFilling(sqList *&k,int q)
{
    // k = (sqList *)malloc(sizeof(sqList));
    k->address = k;
    k->length = q;
    int n = 0;
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
        // printf("THE ELEMENT YOU FIND IS %d\n", k->data[i]);
        return k->data[i];
    }else{
        return ERROR;
    }
};

int main()
{
    int start = DONE;
    int choice;
    sqList *q = (sqList *)malloc(sizeof(sqList));
    // sqList *q = (sqList *)malloc(sizeof(sqList));
    // q->address = q;
    while (start)
    {
        printf("*****欢迎使用c与数据结构第一章线性表操作演示程序*****\n");
        printf("*****请选择操作*****\n");
        printf("*****按 1 :初始化顺序表*****\n");
        printf("*****按 2 :获取下标对应顺序表元素*****\n");
        printf("*****按 9： 退出顺序表操作演示程序*****\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                int name;
                printf("您选择了1号操作:初始化顺序表\n");
                printf("请输入顺序表的表长：\n");
                scanf("%d", &name);
                // sqList *L = (sqList *)malloc(sizeof(sqList));
                sqListFilling(q, name);       
                for (int i=0;i<=q->length;i++)
                {
                    printf(" %d ||", q->data[i]);
                };
                printf("长度为 %d 成功!\n", q->address);
                printf("长度为 %d 的顺序表初始化成功!\n", name);
                system("pause");
                break;
            case 2:
                int num,res;
                printf("您选择了2号操作:获取顺序表元素\n");
                printf("请输入下标：\n");
                scanf("%d", &num);
                res = findElement(q, num);
                if (res)
                {
                    printf("下标%d的元素为：%d \n", num, res);
                }else{
                    printf("输入值不合法!\n");
                }
                system("pause");
                break;
            case 9:
                start = ERROR;
                break;
        }
    }
    printf("演示程序结束！\n");
}