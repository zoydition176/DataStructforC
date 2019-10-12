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
void findelement(sqlist q);
void findmiddle(sqlist q);
int *initArr();
void selectElement(int *n);
int testVar();

int main()
{
    // int a;
    // scanf("%d",&a);
    sqlist *a = (sqlist *)malloc(sizeof(sqlist));
    initArray(a, 10);
    reverse(a);
    printfSql(*a);
    findelement(*a);
    testVar(5);
    findmiddle(*a);
    int *k = initArr();
    selectElement(k);
    // printf("是%d,%p", k[1], &k);
}

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
// 从数组中选出最大和最小的两个数
void findelement(sqlist q)
{
    static int max;
    int min = q.data[0];
    for(int i=0;i<q.length;i++){
        max = q.data[i] > max ? q.data[i] : max;
        min = q.data[i] < min ? q.data[i] : min;
    }
    printf("数组最大值为:%d,数组最小值为:%d\n",max,min);
}

// 求数组中数值居中的数
void findmiddle(sqlist q) 
{
    int arr[q.length];
    int p;
    for(int i = 0;i<q.length;i++){
        arr[i] = q.data[i];
    }
    for(int j = 0;j<q.length;j++){//冒泡排序
        for(int x =0;x<q.length-j-1;x++){
            if(arr[x]>=arr[x+1]){
                p = arr[x];
                arr[x] = arr[x+1];
                arr[x+1] = p;
            }
        }
    }
    printf("排序结果为：\n");
    for(int y = 0;y<q.length;y++){
        printf("%d ",arr[y]);
    }
    if((q.length)%2==0){
        printf("中位数为：%d\n", arr[q.length/2]);
    }else{
        printf("中位数为：%d\n",arr[(q.length+1)/2]);
    }  
}

// 挑选出百位数值大于十位与个位数值之和的元素
int *initArr(){// 初始化一个随机的三位数数组，返回整型指针
    static int arr[9];// 注意：c语言子函数不能返回局部变量的地址，因为局部变量的地址在函数出栈的时候就被清空了。
    int n = 0;
    int a, b;
    // int *point = &arr;
    srand((unsigned)time(NULL));
    for(int i=0;i<9;i++){
        a = rand() % 10;
        b = rand() % 10;
        arr[i] = (i+1)*100+a*10+b;
        printf("%d\n",arr[i]);
    }
    return arr;
}

void selectElement(int *n){// 从数组元素中挑选出百位数值比十位个位之和还要大的元素
    int m = 0;
    for(int i=0;i<9;i++){
        if(((n[i]/100)%10)>((n[i]/10)%10)+(n[i]%10)){
            printf("符合规则的数是%d\n",n[i]);
            m++;
        }
    }
    if(m<1){
        printf("数组没有符合规则的数");
    }
}

// 调用函数自变量空间不同，原理是调用函数的时候保持函数的变量不出栈
int testVar(int n){
    int a = 0;
    if(n == 0){
        return n;
    }else{   
        printf("a in %x,a is %d\n", &a, a);
        n--;
        testVar(n);
    }
}
/*
函数形参只能是自动局部变量，不能是静态局部变量，为什么？
答：因为静态局部变量的生命周期是从初始化到整个程序结束，静态局部变量在内存中的静态存储区。
当函数反复调用而实参重新给作为形参的静态局部变量初始化时，主程序没有结束，无法初始化形参。顺便提一下，静态局部变量能作为函数的返回值被返回。
*/

