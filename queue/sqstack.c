#include <stdio.h>
#define MAXSIZE 100
#define DONE 1
#define ERROR 0

typedef struct sqstk
{
    int data[MAXSIZE];
    int length;
} sqstk;

// cpp特性是引用类型可以当函数形参传递，c语言不支持，只能用指针做形参。调用的时候用引用型做实参
void sqs(sqstk *st)
{
    printf("");
};

int main()
{
    sqstk a;
    // 定义一个栈
    a.length = 0;
}