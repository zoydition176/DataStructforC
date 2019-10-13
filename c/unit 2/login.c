#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAXSIZE 100
#define DONE 1
#define ERROR 0
// 编写检验密码函数
int checkcode();
int login();
int main()
{
    // checkcode();
    login();
    return 0;
}

int checkcode(){//递归方法
    int code = 123;
    int p;
    int n;
    static int t,q;
    scanf("%d",&p);
    if(p == code){
        printf("登录成功！欢迎使用！\n");
        while (p!=0)
        {
            q = p % 10 + q;
            p = p/10;
        }
        printf("密码各位数之和为%d",q);
        return 0;
    }else{
        t++;
        if(t>=3){
            printf("非法用户!\n");
            return 0;
        }else{
            printf("输入错误，请重输!");
            checkcode();
        }
    }
}
int login(){//循环方法
    static int start = DONE;
    static int t;
    int p,n = 0;
    int code = 123;
    while (start)
    {
        printf("请输入登录密码：");
        scanf("%d",&p);
        if(p==code){
            printf("登录成功！欢迎使用！\n");
            while (p!=0)
            {
                n = p%10+n;
                p=p/10;
            }
            printf("密码各位数之和为%d", n);
            start = 0;
        }else{
            t++;
            if(t>=3){
                printf("非法用户!\n");
                start = 0;
            }else{
                printf("输入错误，请重输!\n");
            }
        }
    }
}