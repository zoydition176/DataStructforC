#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* �������� */ 
#define MAXSIZE 100
#define DONE 1
#define ERROR 0

struct sqList
{
    // int *element;
    int data[MAXSIZE];
    int length;
};

// ��ʼ��һ�������˳�������100
void sqListFilling(sqList *&k,int q)
{
    int n = 0;
    k->length = q;
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
        printf("THE ELEMENT YOU FIND IS %d\n", k->data[i]);
        return DONE;
    }else{
        return ERROR;
    }
};

int main()
{
    int start = DONE;
    int choice;
    // sqList *L = (sqList *)malloc(sizeof(sqList));
    // sqListFilling(L,10);
    // for (int i = 0; i < L->length; i++)
    // {
    //     printf("%d\n", L->data[i]);
    // }
    while (start)
    {
        printf("*****��ӭʹ��c�����ݽṹ��һ�����Ա������ʾ����*****\n");
        printf("*****��ѡ�����*****\n");
        printf("*****�� 1 :����˳���*****\n");
        printf("*****�� 2 :����˳���*****\n");
        printf("*****�� 9�� �˳�˳��������ʾ����*****\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                int name;
                printf("��ѡ����1�Ų���:����˳���\n");
                printf("������˳���ı���\n");
                scanf("%d", &name);
                sqList *L = (sqList *)malloc(sizeof(sqList));
                sqListFilling(L, name);
                printf("����˳���ɹ�!\n");
                system("pause");
                break;
            case 9:
                int name;
                printf("��ѡ����1�Ų���:����˳���\n");
                printf("������˳���ı���\n");
                scanf("%d", &name);
                sqList *L = (sqList *)malloc(sizeof(sqList));
                sqListFilling(L, name);
                printf("����˳���ɹ�!\n");
                system("pause");
                break;
        }
    }
    
}