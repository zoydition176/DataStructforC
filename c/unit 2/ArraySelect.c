#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAXSIZE 100
#define DONE 1
#define ERROR 0

/*�����������ͽṹ�������ֿ�д����Ϊ�˷�ֹһЩ������������˷�ʱ������*/

// ���Ա�
typedef struct sqlist
{
    int data[MAXSIZE];
    int length;
} sqlist;
void printfSql(sqlist q);
void initArray(sqlist *q, int n);
void reverse(sqlist *q);
void findelement(sqlist q);
int testVar();

int main()
{
    // int a;
    // scanf("%d",&a);
    sqlist *a = (sqlist *)malloc(sizeof(sqlist));
    initArray(a, 10);
    // printfSql(*a);
    reverse(a);
    printfSql(*a);
    testVar(5);
    findelement(*a);
}

// ��ʼ��˳���
void initArray(sqlist *q, int n)
{
    int a = 0;
    q->length = n;
    memset(q->data, 0, sizeof(q->data)); // ���ԭ������
    srand((unsigned)time(NULL));         // ��ʼ��ʱ������
    if (n > 0)
    {
        for (int i = 0; i < q->length; i++)
        {
            a = rand() % 30;
            q->data[i] = a;
        }
    }
    printfSql(*q);
}

// ��ӡ˳���
void printfSql(sqlist q)
{
    if (q.length > 0)
    {
        for (int i = 0; i < q.length; i++)
        {
            if (i == q.length - 1)
            {
                printf("%d\n", q.data[i]);
            }
            else
            {
                printf("%d,", q.data[i]);
            }
        }
    }
}

// �������
void reverse(sqlist *q) 
{
    static int n;
    int k = q->length - 1;
    for (int i = 0; i < (q->length) / 2; i++)
    {
        /* code */
        n = q->data[k - i];
        q->data[k - i] = q->data[i];
        q->data[i] = n;
    }
}
// ��������ѡ��������С��������
void findelement(sqlist q)
{
    static int max;
    int min = q.data[0];
    for(int i=0;i<q.length;i++){
        max = q.data[i] > max ? q.data[i] : max;
        min = q.data[i] < min ? q.data[i] : min;
    }
    printf("�������ֵΪ:%d,������СֵΪ:%d\n",max,min);
}

// ���ú����Ա����ռ䲻ͬ��ԭ���ǵ��ú�����ʱ�򱣳ֺ����ı�������ջ
int testVar(int n){
    int a = 0;
    if(n == 0){
        return n;
    }else{   
        printf("a in %x,a is %d\n", &a, a);
        n--;
        testVar(n);
    }
}

/*
�����β�ֻ�����Զ��ֲ������������Ǿ�̬�ֲ�������Ϊʲô��
����Ϊ��̬�ֲ����������������Ǵӳ�ʼ�������������������̬�ֲ��������ڴ��еľ�̬�洢����
�������������ö�ʵ�����¸���Ϊ�βεľ�̬�ֲ�������ʼ��ʱ��������û�н������޷���ʼ���βΡ�
*/