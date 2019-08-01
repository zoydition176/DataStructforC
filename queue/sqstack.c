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
    st->top=0;
};

// 判断栈的状态,普通类型的参数
int isEmpty(sqstk st){
    if(st.top == 0){
        return 0;
    }
    else if (st.top == MAXSIZE)
    {
        return 2;
    }else{
        return 1;
    }
};

// 进栈，实参为引用型
int pushStack(sqstk *st,int n)
{
    int k = isEmpty(*st);
    if(k==2){
        return 0;
    }else{
        st->data[st->top]==n;
        (st->top)++;
        return 1;
    }
}




int main()
{
    sqstk a;
    // 定义一个栈
    a.top = 0;
}