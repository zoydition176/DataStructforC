#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define DONE 1
#define ERROR 0
// 阶乘
int factorial(int n)
{
    int res = 1;
    if (n == 0)
    {
        return ERROR;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            res = res * i;
        }
        return res;
    }
}

int main()
{
    int num;
    printf("1.计算阶乘\n请输入一个数：");
    scanf("%d", &num);
    if (factorial(num))
    {
        printf("结果为:%d\n", factorial(num));
    }
    else
    {
        printf("参数错误");
    }
    system("pause");
};