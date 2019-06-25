#include <stdio.h>

struct sqList
{
    int data[100];
    int length;
};

    // int findElement(sqList L,int x){

    // };

int main()
{
    sqList L;
    L.length = 20;
    L.data[100] = {20,20,20,10,5};
    printf("length is :%d", L.length);
}