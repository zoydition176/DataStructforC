#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define DONE 1
#define ERROR 0
// �׳�
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
    printf("1.����׳�\n������һ������");
    scanf("%d", &num);
    if (factorial(num))
    {
        printf("���Ϊ:%d\n", factorial(num));
    }
    else
    {
        printf("��������");
    }
    system("pause");
};