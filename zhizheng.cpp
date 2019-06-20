#include <stdio.h>

int main()
{
    int var = 20; /* 实际变量的声明 */
    int *ip = &var;      /* 指针变量的声明 */
    /*这里可以理解为 ip指针 和 var变量绑定在一起了*/

    /*指针是一种形象化的访问过程，定义的特定类型的指针用来存储对应类型的变量地址，用*符号+指针变量 去访问它的数据  */


    // 直接访问变量地址
    printf("Address of var variable: %p\n", &var);

    printf("Address of var variable: %p\n", ip);

    printf("Address of var variable: %d\n", *ip);

    // /* 在指针变量中存储的地址 */
    // printf("Address stored in ip variable: %p\n", ip);

    // /* 使用指针访问值 */
    // printf("Value of *ip variable: %d\n", *ip);

    return 0;
}