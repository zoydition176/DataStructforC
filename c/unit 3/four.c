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
    int x,b,c = 0;
    printf("%d,%d,%d\n",x,b,c);
    // printf("%c\n", *(str+i)); //%s �����ʽ�������ַ�����Ҫ��� �ַ������׵�ַ,���������Ĵ�ӡ
    // printf("%d\n",*(p=a+1));
    // printf("%d\n",m[m[4]+m[8]]);
    return 0;
}
