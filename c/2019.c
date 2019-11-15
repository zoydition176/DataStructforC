#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAXSIZE 100
#define DONE 1
#define ERROR 0
int fc(int a, int b);
void copy(char *f, char *t);
int main()
{
    // char str[81],*p;
    // int i;
    // for(i=0;i<80;i++){
    //     str[i]=getchar();
    //     if(str[i]=='\n'){
    //         break;
    //     }
    // }
    // str[i]='\0';
    // p = str;
    
    // // p = str;
    // while (*p)
    // {
    //     /* code */
    //     putchar(*(p++));
    // }


//     float sum = 0;
//     float n;
//    for(int i=1;i<=100;i++){
//        n = i;
//         if (i % 2 == 0)
//        {
//            sum = sum - (1 / n);
//        }else{
//            sum = sum + (1 / n);
//        }
//    }
//     printf("%f\n", sum);


    // int n,c;
    // char *a="I am a teacher.";
    // char b[]="You are a student.";
    // copy(a,b);
    // printf("\nstring_a=%s;\nstring_b=%s;",a,b);
    // scanf("%d%d",&n,&c);
    // printf("%d,%d",n,c);
    // int k=4,m=1,p1,p2;
    // p1 = fc(k,m);
    // p2 = fc(k,m);
    // printf("p1=%d,p2=%d",p1,p2);

    int b[][3]={0,1,2,3};
    int c[100][100]={0};
    char k[] = "hello";
    char *p1 = k;
    char *p2 = k;
    char q[]="china";
    int x,y;
    // q = *p1+*p2;
    printf("%s\n",q);
    scanf("%d",&x);
    if(x<12){
        x+=10;
    }else{
        x-=12;
    }
    printf("%d\n",y);
    return 0;
}
int fc(int a,int b){
    static int m=0,i=2;
    i+=m+1;
    m=i+a+b;
    return (m);
}
void copy(char *f,char *t){
    for(;*f!='\0';f++,t++){
        *t = *f;
    }
    *t = '\0';
}
void count(){

}