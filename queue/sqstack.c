#include <stdio.h>
#define MAXSIZE 100
#define DONE 1
#define ERROR 0

// 顺序栈
typedef struct sqstk
{
    int data[MAXSIZE];
    int top;
} sqstk;

// cpp特性是引用类型可以当函数形参传递，c语言不支持，只能用指针做形参。调用的时候用引用型做实参
void initsqs(sqstk *st)
{
    st.top=-1;
};

int initSqk(){

};

int main()
{
    sqstk a;
    // 定义一个栈
    a.length = 0;
}