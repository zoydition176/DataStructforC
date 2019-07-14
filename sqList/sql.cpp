#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* �������� */ 
#define MAXSIZE 100
#define DONE 1
#define ERROR 0

struct sqList
{
    struct sqList *address;
    int data[MAXSIZE];
    int length;
};

// ��ʼ��һ�������˳�������100
void sqListFilling(sqList *&k,int q)
{
    // k = (sqList *)malloc(sizeof(sqList));
    k->address = k;
    k->length = q;
    int n = 0;
    srand((unsigned)time(NULL));
    if (q > 0)
    {
        for (int i = 0; i < k->length; i++)
        {
            n = rand()%30;
            k->data[i] = n;
        }
    }
};

// ˳����Ӧ�±�Ԫ�ػ�ȡ
int findElement(sqList *k, int i)
{
    if(i>=0 && i<=k->length){
        // printf("THE ELEMENT YOU FIND IS %d\n", k->data[i]);
        return k->data[i];
    }else{
        return ERROR;
    }
};

int main()
{
    int start = DONE;
    int choice;
    sqList *q = (sqList *)malloc(sizeof(sqList));
    // sqList *q = (sqList *)malloc(sizeof(sqList));
    // q->address = q;
    while (start)
    {
        printf("*****��ӭʹ��c�����ݽṹ��һ�����Ա������ʾ����*****\n");
        printf("*****��ѡ�����*****\n");
        printf("*****�� 1 :��ʼ��˳���*****\n");
        printf("*****�� 2 :��ȡ�±��Ӧ˳���Ԫ��*****\n");
        printf("*****�� 9�� �˳�˳��������ʾ����*****\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                int name;
                printf("��ѡ����1�Ų���:��ʼ��˳���\n");
                printf("������˳���ı���\n");
                scanf("%d", &name);
                // sqList *L = (sqList *)malloc(sizeof(sqList));
                sqListFilling(q, name);       
                for (int i=0;i<=q->length;i++)
                {
                    printf(" %d ||", q->data[i]);
                };
                printf("����Ϊ %d �ɹ�!\n", q->address);
                printf("����Ϊ %d ��˳����ʼ���ɹ�!\n", name);
                system("pause");
                break;
            case 2:
                int num,res;
                printf("��ѡ����2�Ų���:��ȡ˳���Ԫ��\n");
                printf("�������±꣺\n");
                scanf("%d", &num);
                res = findElement(q, num);
                if (res)
                {
                    printf("�±�%d��Ԫ��Ϊ��%d \n", num, res);
                }else{
                    printf("����ֵ���Ϸ�!\n");
                }
                system("pause");
                break;
            case 9:
                start = ERROR;
                break;
        }
    }
    printf("��ʾ���������\n");
}