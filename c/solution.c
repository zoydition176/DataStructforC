#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int *sortInt(int *s, int length);
int *creatArray(int length);
void printfArray(int *s, int length);

int main(){
    int start = 1;
    int choice;
    int d;
    printf("������Ҫ�����鳤�ȣ�\n");
    scanf("%d", &d);
    int *k = creatArray(d); 
    printfArray(k, d);
    while (start)
    {
        printf("��ѡ����Ҫ�����������\n");
        printf("1.����������顣\n");
        printf("2.���Ʋ�������顣\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            sortInt(k, d);
            printfArray(k, d);
            system("pause");
        }
        break;
        case 2:
        {
            printfArray(k, d);
            system("pause");
        }
        break;
        default:
            start = 0;
            break;
        }
    }
    
    
    return 0;
}

int *sortInt(int *s,int length){
    int i;
    int j;
    int m;   
    for(i=0;i<length;i++){
        for(j=0;j<length-i-1;j++){
            if(*(s+j) >= *(s+j+1)){
                m = *(s + j);
                *(s + j) = *(s + j + 1);
                *(s + j + 1) = m;
            }
        }
    }
    return s;
}

int *creatArray(int length)
{
    int i;
    int *result = (int *)malloc(length * sizeof(int));
    for (i = 0; i < length; i++)
    {           
        printf("����һ������");
        scanf("%d", &result[i]);
    }
    return result;  
}

int *moveArray(int *s, int length, int num){
    int *temp = (int *)malloc(num * sizeof(int));
}


void printfArray(int *s, int length)
{
    printf("������Ϊ��");
    for(int i=0;i<length;i++){
        if(i == length - 1){
            printf(" %d ]\n", *(s + i));
        }else if(i==0){
            printf("[ %d ,", *(s + i));
        }else{
            printf(" %d ,", *(s + i));
        }
    }
}