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
int josephus(int n, int m);
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
    josephus(8,5);
    return 0;
}
char *sys(long n,int b,char *c){//数制转换
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
double glg(double c){//格力高公式算π
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
int josephus(int n,int m){
    int i = 0,j=0;
    int *p = (int *)malloc(n*sizeof(int));
    while (i<n)
    {
        /* code */
        p[i] = i+1;
        i++;
    }
    while(n>1){
        j = (j+m-1)%n;
        for(int a = j;a<n-1;a++){
            p[a] = p[a+1];
        }
        n--;
        if(j==n){
            j = 0;
        }
    }
    printf("%d",p[0]);
    return p[0];
}