#include <stdio.h>
#include <stdlib.h>
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
    return 1;
}

// 判断顺序队是否为空
int isQueueEmpty(sqQueue d)
{
    if (d.front == d.rear)
    {
        return 1;
    }else{
        return 0;
    }
}

// 出队
int enQueue(sqQueue *d,int *n)
{
    if(d->rear == d->front){//队空无法出队
        return 0;
    }else{
        d->front = (d->front + 1) % MAXSIZE;
        *n = d->data[d->front];
        return 1;
    }
}
// 入队
int outQueue(sqQueue *d,int n)
{
    if ((d->rear + 1) % MAXSIZE == d->front)//队满无法入队
    {
        return 0;
    }else
    {
        /* code */
        d->rear = (d->rear + 1)% MAXSIZE;
        (d->data)[d->rear] == n;
        return 1;
    }
    
}

int main()
{
    sqQueue *a = (sqQueue *)malloc(sizeof(sqQueue));
    initQueue(a); //我叼你妈的总算对了
    // 定义一个栈
    isQueueEmpty(*a);
}