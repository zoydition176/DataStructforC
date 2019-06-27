#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct sqList
{
    int data[20];
    int length;
};

void sqListFilling(sqList k)
{
    int n;
    if(k.length>0){//非空顺序表
        for(int i=0;i<k.length;i++){
            n = 1 + (int)(rand()%10);
            k.data[i] = n;
        }
    }

};
int main()
{
    int test;
    sqList L;
    L.length = 20;
    // test = rand()%10;
    // printf("%d\n", test);
    void sqListFilling(sqList L);
    printf("%d\n", L.data[0]);
    // for (int q = 0; q <= L.length; q++)
    // {
    //     printf("%d\n", L.data[q]);
    // }
}