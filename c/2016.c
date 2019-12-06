#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAXSIZE 100
#define DONE 1
#define ERROR 0
double glg(double c);
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
    printf("%d\n", gys(32,10));
    return 0;
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