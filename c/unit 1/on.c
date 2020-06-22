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
        // 1
        /*
        for (int i = 1; i <= n; i++)
        {
            res = res * i;
        }
        return res;
        */

        // 2
        while (n)
        {
            res = res * n;
            n--;
        }
        return res;
    }
}
// 斐波那契数列
int fib(int n)
{
    // 常规方法
    int q = 1;
    int p = 0;
    int k = 0;
    if (n <= 0)
    {
        return ERROR;
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            k = q;
            q = k + p;
            p = k;
        }
        return q;
    }

    // 递归方法
}

// 台阶问题
int ladder()
{
    int n = 7;
    while (n)
    {
        if ((n % 2 == 1) && (n % 3 == 2) && (n % 5 == 4) && (n % 6 == 5) && (n % 7 == 0))
        {
            break;
        }
        else
        {
            n = n + 7;
        }
    }
    return n;
}

// 货币问题
int currency()
{
    int n = 0;
    int x;
    int y;
    int z;
    int arr[100][3];
    for (y = 9; y >= 0; y--)
    {
        x = 10 - y;
        for (z = 0; z < x; z++)
        {
            if (z * 5 + (x - z) * 1 + y * 2 == 18)
            {
                n = n + 1;
                arr[n][0] = x - z;
                arr[n][1] = y;
                arr[n][2] = z;
            }
        }
    }
    // return arr[100][3];
    return n;
}

// 勾股数输出
void Pythagorean()
{
    int x;
    int y;
    int z;
    int n = 0;
    for (z = 5; z <= 100; z++)
    {
        for (y = 4; y < z; y++)
        {
            for (x = 3; x <= y; x++)
            {
                if (x * x + y * y == z * z)
                {
                    n = n + 1;
                    printf("第%d组勾股数为%d,%d,%d\n", n, x, y, z);
                }
            }
        }
    }
}

// 百鸡问题
void CountChicken()
{
    int x;
    int y;
    int z;
    int n = 0;
    for (z = 20; z >= 0; z--)
    {
        y = 100 - z;
        for (x = 0; x < y; x++)
        {
            if (x * 9 + z * 15 + (y - x) * 1 == 300)
            {
                n = n + 1;
                printf("解%d:\n", n);
                printf("公鸡%d只\n母鸡%d只\n小鸡%d只\n", z, x, y - x);
                printf("----------------------------\n");
                break;
            }
        }
    }
}

int main()
{
    int start = DONE;
    int choice;
    while (start)
    {
        printf("请输入题号（4~9）：\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 4:
        {
            int num;
            printf("4.计算阶乘\n请输入一个数：");
            scanf("%d", &num);
            if (factorial(num))
            {
                printf("结果为:%d\n", factorial(num));
            }
            else
            {
                printf("参数错误!\n");
            }
            system("pause");
        }
        break;
        case 5:
        {
            int num;
            printf("5.计算斐波那契数列第n项\n请输入项数：");
            scanf("%d", &num);
            if (fib(num))
            {
                printf("结果为:%d\n", fib(num));
            }
            else
            {
                printf("参数错误!\n");
            }
            system("pause");
        }
        break;
        case 6:
        {
            printf("6.计算台阶数,一条长阶梯，若每步跨2阶，则最后剩一阶；每步3阶，剩2阶；每步5阶，剩4阶；每步跨6阶，剩5阶；每步7阶则最后一阶不剩。\n");
            printf("结果为:%d\n", ladder());
            system("pause");
        }
        break;
        case 7:
        {
            printf("7.货币凑钱问题，1元2元5元纸币共10张，凑整18元，有几种办法?\n");
            printf("结果为:%d\n", currency());
            system("pause");
        }
        break;
        case 8:
        {
            printf("8.勾股数,输出问题:求一百以内的勾股数，避免3，4，5与5，4，3这样的重复的勾股数?\n输出结果:\n");
            Pythagorean();
            system("pause");
        }
        break;
        case 9:
        {
            printf("9.百鸡问题，公鸡一只五块，母鸡一只3块，小鸡三只一块，一百元买一百只鸡，请问怎么买？\n输出结果:\n");
            CountChicken();
            system("pause");
        }
        break;
        default:
            start = ERROR;
            break;
        }
    }

    printf("演示程序结束！\n");
};