#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#define MAXSIZE 100
#define DONE 1
#define ERROR 0
int main()
{
    int n;
    double z;
    scanf("%d",&n);
    if(n>10){
        z = exp(n);
    }else if(n>(-3)&&n<=10){
        z = log10(n * 1.00);
    }else{
        z = sin(n * 1.00) / (cos(n * 1.00) + 4);
    }
    printf("%f",z);
    return 0;
}
