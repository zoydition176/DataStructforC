#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct sqList
{
    // int *element;
    int data[10];
    int length;
};

void sqListFilling(sqList k)
{
    int n = 0;
    // if(k.length>0){
    //     for(int i=0;i<k.length;i++){
    //         k.data[i] = i;
    //     }
    // }
    for (int q = 0; q <= 11; q++)
    {
        k.data[q] = 0;
        // printf("%d\n", L.data[q]);
    }
};
int main()
{
    int test;
    sqList L;
    L.length = 20;
    sqListFilling(L);
    // for (int q = 0; q <= 11; q++)
    // {
    //     L.data[q] = 0;
    //     printf("%d\n", L.data[q]);
    // }
    for (int i = 0; i <= 10; i++)
    {
        // L.data[q] = 0;
        printf("%d\n", L.data[i]);
    }
}