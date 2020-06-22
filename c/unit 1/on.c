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
int fib(int n)
{
    // ���淽��
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

    // �ݹ鷽��
}

// ̨������
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

// ��������
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

// ���������
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
                    printf("��%d�鹴����Ϊ%d,%d,%d\n", n, x, y, z);
                }
            }
        }
    }
}

// �ټ�����
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
                printf("��%d:\n", n);
                printf("����%dֻ\nĸ��%dֻ\nС��%dֻ\n", z, x, y - x);
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
        printf("��������ţ�4~9����\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 4:
        {
            int num;
            printf("4.����׳�\n������һ������");
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
            printf("5.����쳲��������е�n��\n������������");
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
        case 6:
        {
            printf("6.����̨����,һ�������ݣ���ÿ����2�ף������ʣһ�ף�ÿ��3�ף�ʣ2�ף�ÿ��5�ף�ʣ4�ף�ÿ����6�ף�ʣ5�ף�ÿ��7�������һ�ײ�ʣ��\n");
            printf("���Ϊ:%d\n", ladder());
            system("pause");
        }
        break;
        case 7:
        {
            printf("7.���Ҵ�Ǯ���⣬1Ԫ2Ԫ5Ԫֽ�ҹ�10�ţ�����18Ԫ���м��ְ취?\n");
            printf("���Ϊ:%d\n", currency());
            system("pause");
        }
        break;
        case 8:
        {
            printf("8.������,�������:��һ�����ڵĹ�����������3��4��5��5��4��3�������ظ��Ĺ�����?\n������:\n");
            Pythagorean();
            system("pause");
        }
        break;
        case 9:
        {
            printf("9.�ټ����⣬����һֻ��飬ĸ��һֻ3�飬С����ֻһ�飬һ��Ԫ��һ��ֻ����������ô��\n������:\n");
            CountChicken();
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