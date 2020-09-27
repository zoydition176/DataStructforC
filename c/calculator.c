#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

float count(float x){
    float k = 4.184;
    return x/k;
}

int main(){
    int s = 1;
    while (s)
    {
        /* code */
        count(s);
    }
    
    return 0;
}