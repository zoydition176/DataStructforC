#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAXSIZE 100
#define DONE 1
#define ERROR 0
int main()
{
    char str[81],*p;
    int i;
    for(i=0;i<80;i++){
        str[i]=getchar();
        if(str[i]=='\n'){
            break;
        }
    }
    str[i]='\0';
    p = str;
    
    // p = str;
    while (*p)
    {
        /* code */
        putchar(*(p++));
    }
}
