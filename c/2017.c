#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#define MAXSIZE 100
#define DONE 1
#define ERROR 0
void snew (char str[]);
int main()
{
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
    char s[] = "chinabank";
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
    int x = 3,y = 2 , a[x];
    int b = 037;
    printf("%d\n",b);
    printf("%f",1.0*x/y);
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