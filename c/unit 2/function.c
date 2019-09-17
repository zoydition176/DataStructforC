#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define DONE 1
#define ERROR 0

typedef struct sqList
{
    int data[MAXSIZE];
    int length;
} sqList;

void reverse(sqList *q)
{
    // printf("%d,", q->data[0]);
    int n;
    for(int i=0;i<(q->length)/2;i++){
        n = q->data[q->length-1-i];
        q->data[q->length-i] = q->data[i];
        q->data[i] = n;
        printf("%d,", q->data[i]);
        n = 0;
    }   
}

int main()
{
    sqList *k = (sqList *)malloc(sizeof(sqList));
    k->length = 10;
    // k->data[0] = 1;
    for (int i = 0; i < k->length; i++)
    {
        k->data[i] = i;
        printf("%d,", k->data[i]);
    }
    // printf("%d,", k->data[0]);
    printf("\n");
    reverse(k);
    return 0;
};