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
    if(k.length>0){
        for(int i=0;i<k.length;i++){
            k.data[i] = i;
        }
    }

};
int main()
{
    int test;
    sqList L;
    L.length = 20;
    sqListFilling(L);
    for (int q = 0; q <= L.length; q++)
    {
        printf("%d\n", L.data[q]);
    }
}