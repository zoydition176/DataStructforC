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
// 쳲���������
int fib(int n){
    // ���淽��
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

    // �ݹ鷽��
}

int main()
{
    int start = DONE;
    int choice;
    while (start)
    {
        printf("��������ţ�\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 4:{
            int num;
            printf("1.����׳�\n������һ������");
            scanf("%d", &num);
            if (factorial(num))
            {
                printf("���Ϊ:%d\n", factorial(num));
            }
            else
            {
                printf("��������!\n");
            }
            system("pause");
        }
            break;
        case 5:
        {
            int num;
            printf("1.����쳲��������е�n��\n������������");
            scanf("%d", &num);
            if (fib(num))
            {
                printf("���Ϊ:%d\n", fib(num));
            }
            else
            {
                printf("��������!\n");
            }
            system("pause");
        }
        break;
        default:
            start = ERROR;
            break;
        }
    }

    printf("��ʾ���������\n");
};