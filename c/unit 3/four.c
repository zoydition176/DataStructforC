#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAXSIZE 100
#define DONE 1
#define ERROR 0
int main()
{
    char str[5] = {'a','b','c','d','e'};
    int n = 0;
    int i = 2;
    int a[]={1,2,4,6,8,99};
    int *p = a;
    int m[10] = {9,4,12,8,2,10,7,5,1,3};
    printf("%c\n", *(str+i)); //%s 输出格式，用于字符串，要求给 字符串的首地址,是整个串的打印
    printf("%d\n",*(p=a+1));
    printf("%d\n",m[m[4]+m[8]]);
    return 0;
}
