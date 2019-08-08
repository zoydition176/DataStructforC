#include <stdio.h>
#define MAXSIZE 100
#define DONE 1
#define ERROR 0

// 顺序队
typedef struct sqQueue
{
    int data[MAXSIZE];
    int front;
    int rear;
} sqQueue;

// 初始化顺序队
int initQueue(sqQueue *d)
{
    d->front = d->rear = 0;
}

// 判断顺序队是否为空
int isQueueEmpty(sqQueue d)
{
    d.front==d.rear;
}

int main()
{
    sqQueue a;
    // 定义一个栈
    
}