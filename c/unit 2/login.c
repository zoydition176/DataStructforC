#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAXSIZE 100
#define DONE 1
#define ERROR 0

int checkcode();

int main(){
    checkcode();
    return 0;
}

int checkcode(){
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