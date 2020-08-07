#include<stdio.h>
int main()
{
    char msg[6]="ABC";
    msg[0]='a';
    char *mpt="abc";
    printf("msg:%p",msg);
    printf("mpt:%p",mpt);
    *mpt='A';
    return 0;
}
