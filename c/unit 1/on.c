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
int fib(int n){
    // 常规方法
    int q=1;
    int p = 0;
    int k = 0;
    if(n<=0){
        return ERROR;
    }else{
        for(int i=1;i<n;i++){
            k = q;
            q = k + p;
            p = k;
        }
        return q;  
    }

    // 递归方法
}

int main()
{
    int start = DONE;
    int choice;
    while (start)
    {
        printf("请输入题号：\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 4:{
            int num;
            printf("1.计算阶乘\n请输入一个数：");
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
            printf("1.计算斐波那契数列第n项\n请输入项数：");
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
        default:
            start = ERROR;
            break;
        }
    }

    printf("演示程序结束！\n");
};