#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#define MAXSIZE 100
#define DONE 1
#define ERROR 0
// #define N 5
// #define M N+1
// #define f(x) (x*M)
void snew (char str[]);
void csdg(int n);
void f1(char *s1);
int main()
{
    // int i1,i2;
    // i1 = f(2);
    // i2 = f(1+1);
    // printf("%d,%d\n",i1,i2);

    // int n;
    // double z;
    // scanf("%d",&n);
    // if(n>10){
    //     z = exp(n);
    // }else if(n>(-3)&&n<=10){
    //     z = log10(n * 1.00);
    // }else{
    //     z = sin(n * 1.00) / (cos(n * 1.00) + 4);
    // }
    // printf("%f",z);
    // char s[] = "chinabank";
    // puts(s);
    // snew(s);
    // puts(s);
    // int k = 5>2>7>8;
    // printf("%d",k);
    // char c = '8';
    // char ch[10] = "China";
    // printf("%d\n",strlen(ch));
    // printf("%c\n",c);
    // int i;
    // for (i = 0; i == 10; i++)
    // {
    //     continue;
    // };
    // printf("%d",i);
    // return 0;
    // int x = 3,y = 2 , a[x];
    // int b = 037;
    // printf("%d\n",b);
    // printf("%f",1.0*x/y);



    // char *c = "hubei gongye daxue";
    // int i,j;
    // for(i=j=0;c[i]!='\0';i++){
    //     if(c[i]!=' '){
    //         c[j++]=c[i];
    //     }else{
    //         continue;
    //     }
    // }
    // c[j]='\0';
    // printf("%s\n",c[0]);


    // static char kkk[5]={'a','e','i','o','u'};
    // char sss[80];
    // int k,j;
    // gets(sss);
    // for(k=0;sss[k]!='\0';k++){
    //     for(j=0;j<5;j++){
    //         if(sss[k]==kkk[j]){
    //             sss[k]=j+'0';
    //         }
    //     }
    // }
    // puts(sss);

    /**/
    // for(int i = 1;i<=4;i++){
    //     for(int n =1;n<=4;n++){
    //         if(n == i ){
    //             continue;
    //         }else{
    //             for(int m = 1;m<=4;m++){
    //                 if(m==i||m==n){
    //                     continue;
    //                 }else{
    //                     printf("%d\n",(i*100)+(n*10)+m);
    //                 }
    //             }
    //         }
    //     }

    // }

    // f1("abcdefg");
    // csdg(10);
    int jok;
    jok = 0 + '6' - '0';
    char kkk[5][20];
    char b[3]="abc";
    char a[4]={'a','2','c','\0'};
    // puts(b);
    printf("%d\n", 1+'0');
    FILE *fp;
    char For;
    // fp = fopen("C:\\Users\\Administrator\\Desktop\\ddd.txt","r");
    int k;
    for(k = 1;k+1;k++){
        if(k>4){
            printf("%d\n",k++);
            break;
        }
        printf("%d\n",k++);
    }
}
void snew(char str[]){
    char k[]="xxxxxxx";
    char *p = str;
    int i = 0;
    


    while (str[i]!='\0')
    {
        /* code */
        if(i%2==0){
            p[i] = str[i];
            // printf("%s\n", str[0]);
        }
        i++;
    }
    puts(p);
}
void f1(char *s1){
    char c;
    // char b;
    // b = *s1;
    // putchar(b);
    // puts(s1);
    if(*s1!='\0'){
        c=*s1;        
        strcpy(s1,s1+1);
        // putchar(c);
        printf("dayingyici");
        f1(s1);
        printf("dayingyici");
        putchar(c);
    }
}
void csdg(int n){
    static int m = 0;
    if(n>=0){
        printf("%d\t %d\n", n--,m);
        csdg(n);
        printf("执行了%d次\n",++m);
    }else{
        printf("不递归了\n");
    }
}