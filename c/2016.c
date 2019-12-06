#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAXSIZE 100
#define DONE 1
#define ERROR 0
double glg(double c);
char *sys(long n, int b, char *c);
int gys(int a, int b);
int main()
{
    // int x,y;
    // scanf("%d",&x);
    // x = x>12?x+10:x-12;
    // double p = 1e-4;
    // printf("%d\n",y);
    // printf("%Lf\n",p);
    printf("%f\n", glg(1e-4));
    int qqq,ppp;
    // scanf("%d",&qqq);
    // scanf("%d",&ppp);
    // printf("%d\n", gys(qqq,ppp));
    char k[80];
    puts(sys(10,2,k));
    return 0;
}
char *sys(long n,int b,char *c){
    int target[]={};
    char res[]={};
    int i = 0,m = 0;
    while(n!=0){
        target[i++] = n%b;
        n = n/b;
        // printf("%d", target[i]);
    }
    while(i!=0){
        if(target[i]>=10){
            target[i] = target[i]+87;
        }
        c[m++] = target[i--];
    }
    return c;
}
double glg(double c){
    double t = 0,item = 1;
    int i = 1;
    while (item>=c)
    {
        /* code */
        item = 1.0 / (1+(i-1)*2);
        if(i%2==0){        
            t = t - item;
        }else{
            t = t + item;
        }
        i++;
    }
    return t*4;
}
int gys(int a,int b){
    int p = a%b;
    if(p == 0){
        return b;
    }else{
        gys(b,p);
    }
}