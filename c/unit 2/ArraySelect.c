#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAXSIZE 100
#define DONE 1
#define ERROR 0

/*将函数声明和结构体声明分开写上面为了防止一些调用问题而多浪费时间排序*/

// 线性表
typedef struct sqlist
{
    int data[MAXSIZE];
    int length;
} sqlist;
void printfSql(sqlist q);
void initArray(sqlist *q, int n);
void reverse(sqlist *q);

int main()
{
    // int a;
    // scanf("%d",&a);
    sqlist *a = (sqlist *)malloc(sizeof(sqlist));
    initArray(a, 10);
    // printfSql(*a);
    reverse(a);
    printfSql(*a);
}
// 从数组中选出最大和最小的两个数

// 初始化顺序表
void initArray(sqlist *q, int n)
{
    int a = 0;
    q->length = n;
    memset(q->data, 0, sizeof(q->data)); // 清空原有数组
    srand((unsigned)time(NULL));         // 初始化时间种子
    if (n > 0)
    {
        for (int i = 0; i < q->length; i++)
        {
            a = rand() % 30;
            q->data[i] = a;
        }
    }
    printfSql(*q);
}

// 打印顺序表
void printfSql(sqlist q)
{
    if (q.length > 0)
    {
        for (int i = 0; i < q.length; i++)
        {
            if (i == q.length - 1)
            {
                printf("%d\n", q.data[i]);
            }
            else
            {
                printf("%d,", q.data[i]);
            }
        }
    }
}

// 逆序输出
void reverse(sqlist *q) 
{
    static int n;
    int k = q->length - 1;
    for (int i = 0; i < (q->length) / 2; i++)
    {
        /* code */
        n = q->data[k - i];
        q->data[k - i] = q->data[i];
        q->data[i] = n;
    }
}

// 调用函数自变量空间不同
void testVar(){

}