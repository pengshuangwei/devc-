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
    printf("����3����ѡ�˵Ļ�����Ϣ������\n");
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
    printf("����μ�ͶƱ������:%d\n", number);

    char *ch[number];
    printf("����%d���μ�ͶƱ�˵�ͶƱ���\n", number);
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
    printf("���3����ѡ�˵Ļ�����Ϣ��������Ʊ��\n");
    for (i = 0; i < 3; i++)
    {
        printf("%s %d\n", num[i].a, num[i].Num);
    }
    return 0;
}
