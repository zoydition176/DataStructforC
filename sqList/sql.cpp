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
    L.data[0] = {20};
    L.data[1] = {20};
    L.data[2] = {20};
    printf("length is :%d", L.length);
}