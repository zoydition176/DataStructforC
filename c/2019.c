#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAXSIZE 100
#define DONE 1
#define ERROR 0
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

    int i = 1;
    float sum = 0;

    while (i <= 100)
    {
        if (i % 2 == 0)
        {
            sum -= 1 / (i++ * 1.0);
        }
        else
        {
            sum += 1 / (i++ * 1.0);
        }
    }
    printf("%f\n", sum);
}
