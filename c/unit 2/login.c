#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAXSIZE 100
#define DONE 1
#define ERROR 0
// ��д�������뺯��
int checkcode();
int login();
int main()
{
    // checkcode();
    login();
    return 0;
}

int checkcode(){//�ݹ鷽��
    int code = 123;
    int p;
    int n;
    static int t,q;
    scanf("%d",&p);
    if(p == code){
        printf("��¼�ɹ�����ӭʹ�ã�\n");
        while (p!=0)
        {
            q = p % 10 + q;
            p = p/10;
        }
        printf("�����λ��֮��Ϊ%d",q);
        return 0;
    }else{
        t++;
        if(t>=3){
            printf("�Ƿ��û�!\n");
            return 0;
        }else{
            printf("�������������!");
            checkcode();
        }
    }
}
int login(){//ѭ������
    static int start = DONE;
    static int t;
    int p,n = 0;
    int code = 123;
    while (start)
    {
        printf("�������¼���룺");
        scanf("%d",&p);
        if(p==code){
            printf("��¼�ɹ�����ӭʹ�ã�\n");
            while (p!=0)
            {
                n = p%10+n;
                p=p/10;
            }
            printf("�����λ��֮��Ϊ%d", n);
            start = 0;
        }else{
            t++;
            if(t>=3){
                printf("�Ƿ��û�!\n");
                start = 0;
            }else{
                printf("�������������!\n");
            }
        }
    }
}