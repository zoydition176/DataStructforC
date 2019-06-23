#include <stdio.h>
int main()
{
    /*一维数组的定义与表达*/
    /*
    int arg[5];
    for(int i=0;i<sizeof(arg)/sizeof(arg[0]);i++){
        scanf("%d",&arg[i]);
        printf("you have pushed this num in the array\n");
    }
    printf("your array is :[%d,%d,%d,%d,%d]", arg[0], arg[1], arg[2], arg[3], arg[4]);
    */
   
    /*二位数组的定义与描述*/
    /*
    int arg[2][5];
    for (int i = 0; i < sizeof(arg) / sizeof(arg[0]); i++)
    {
        for (int j = 0; j < sizeof(arg[0]) / sizeof(arg[0][0]); j++)
        {
            scanf("%d", &arg[i][j]);
            printf("you have pushed this num in the array\n");
        }
    }

    for (int i = 0; i < sizeof(arg) / sizeof(arg[0]); i++)
    {
        printf("[");
        for (int j = 0; j < sizeof(arg[0]) / sizeof(arg[0][0]); j++)
        {
            if (j == 4)
            {
                printf("%d", arg[i][j]);
            }else{
                printf("%d,", arg[i][j]);
            }
        }
        printf("]\n");
    }
    */
}