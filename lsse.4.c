#include<stdio.h>
#include<string.h>
 struct People
{
    char* a;
    int Num;
};
int main()
{
    int i = 0;
    int t = 0;
    int digit = 0;
    int number = 0;
    int j=0;
    struct People num[3];
    printf("输入3个候选人的基本信息：姓名\n");
    for (i = 0; i < 3; i++)
    {
        scanf("%s",&num[i].a);
        digit = sizeof(num[i].a);
        if (digit > t)
        {
            t = digit;
        }
    }
    scanf("%d",&number);
    printf("输入参加投票的人数:%d\n", number);

    char *ch[number];
    printf("输入%d个参加投票人的投票情况\n", number);
    for (i = 0; i < number; i++)
    {
        scanf("%s", *ch[i]);
    }
    for (i = 0; i < number; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            if (strcmp(ch[i],num[j].a)==0)
            {
                num[j].Num++;
                break;
            }
        }
    }
    printf("输出3个候选人的基本信息：姓名，票数\n");
    for (i = 0; i < 3; i++)
    {
        printf("%s %d\n", num[i].a, num[i].Num);
    }
    return 0;
}
