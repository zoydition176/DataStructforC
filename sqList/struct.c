#include <stdio.h>
#include <stdlib.h>

int a = 20;
int main()
{
    typedef struct
    {
        /* data */
        int age;
        char *name;
    } Student, *pStudent, Student[100];
    Student sss;
    sss.age = 10;
    sss.name = "zdx";
    printf("%d\n", a);
    printf("s name is %s,age is %d", sss.name, sss.age);
    return 0;
}