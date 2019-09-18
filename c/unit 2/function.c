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

void reverse(sqList *q)// ÄæÐòÊä³ö
{
    int n;
    int k = q->length-1;
    for (int i = 0; i < (q->length)/2; i++)
    {
        /* code */
        n = q->data[k - i];
        q->data[k - i] = q->data[i];
        q->data[i] = n;
    }
    for(int j = 0;j<q->length;j++){
        printf("%d,", q->data[j]);
    }
}

int main()
{
    sqList *k = (sqList *)malloc(sizeof(sqList));
    k->length = 19;
    for (int i = 0; i < k->length; i++)
    {
        k->data[i] = i;
        printf("%d,", k->data[i]);
    }
    printf("\n");
    reverse(k);
    return 0;
};