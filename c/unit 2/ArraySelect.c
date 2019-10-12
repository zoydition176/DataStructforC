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
void findmiddle(sqlist q);
int *initArr();
void selectElement(int *n);
int testVar();

int main()
{
    // int a;
    // scanf("%d",&a);
    sqlist *a = (sqlist *)malloc(sizeof(sqlist));
    initArray(a, 10);
    reverse(a);
    printfSql(*a);
    findelement(*a);
    testVar(5);
    findmiddle(*a);
    int *k = initArr();
    selectElement(k);
    // printf("��%d,%p", k[1], &k);
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

// ����������ֵ���е���
void findmiddle(sqlist q) 
{
    int arr[q.length];
    int p;
    for(int i = 0;i<q.length;i++){
        arr[i] = q.data[i];
    }
    for(int j = 0;j<q.length;j++){//ð������
        for(int x =0;x<q.length-j-1;x++){
            if(arr[x]>=arr[x+1]){
                p = arr[x];
                arr[x] = arr[x+1];
                arr[x+1] = p;
            }
        }
    }
    printf("������Ϊ��\n");
    for(int y = 0;y<q.length;y++){
        printf("%d ",arr[y]);
    }
    if((q.length)%2==0){
        printf("��λ��Ϊ��%d\n", arr[q.length/2]);
    }else{
        printf("��λ��Ϊ��%d\n",arr[(q.length+1)/2]);
    }  
}

// ��ѡ����λ��ֵ����ʮλ���λ��ֵ֮�͵�Ԫ��
int *initArr(){// ��ʼ��һ���������λ�����飬��������ָ��
    static int arr[9];// ע�⣺c�����Ӻ������ܷ��ؾֲ������ĵ�ַ����Ϊ�ֲ������ĵ�ַ�ں�����ջ��ʱ��ͱ�����ˡ�
    int n = 0;
    int a, b;
    // int *point = &arr;
    srand((unsigned)time(NULL));
    for(int i=0;i<9;i++){
        a = rand() % 10;
        b = rand() % 10;
        arr[i] = (i+1)*100+a*10+b;
        printf("%d\n",arr[i]);
    }
    return arr;
}

void selectElement(int *n){// ������Ԫ������ѡ����λ��ֵ��ʮλ��λ֮�ͻ�Ҫ���Ԫ��
    int m = 0;
    for(int i=0;i<9;i++){
        if(((n[i]/100)%10)>((n[i]/10)%10)+(n[i]%10)){
            printf("���Ϲ��������%d\n",n[i]);
            m++;
        }
    }
    if(m<1){
        printf("����û�з��Ϲ������");
    }
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
�������������ö�ʵ�����¸���Ϊ�βεľ�̬�ֲ�������ʼ��ʱ��������û�н������޷���ʼ���βΡ�˳����һ�£���̬�ֲ���������Ϊ�����ķ���ֵ�����ء�
*/

