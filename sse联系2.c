

/*�Ӽ�����������һ������m����m�������������m�����������ֽ⣬����m��ʾΪ��������С����˳�����еĳ˻���ʽ������������"It is a prime number"�����磬�û�����90ʱ���������90 = 2 * 3 * 3 * 5���û�����17ʱ���������"It is a prime number"��
������ʾ��Ϣ��"Input m:"
�����ʽ��"%d"
�����ʽ��
������ʱ���"It is a prime number\n"
���������"%d = "��"%d * "
����ʾ��1��
Input m:90�L
90 = 2 * 3 * 3 * 5
����ʾ��2��
Input m:13�L
It is a prime number*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int main()
{
    int m;
    printf("Input m:");
    scanf("%d",&m);
    int *prime=(int*)malloc(10*sizeof(int));
    int *p=NULL;
    prime[0]=2;
    int t=3;
    int count=0;
    bool isprime=false;
    while(t<m){
        int i=0;
        for(i=0;i<count;i++){
            if(t%prime[i]==0){
                isprime=false;
                break;
            }else{
            isprime=true;
            }
        }
        if(isprime){
            count++;
            prime[count]=t;
            if(count%9==0){
                p=(int*)realloc(prime,(count+10)*sizeof(int));
                if(!p){
                    printf("error");
                    free(prime);
                    prime=NULL;
                    return 1;
                }else{
                prime=p;
                }
            }
            printf("It is a prime number\n");
            return 1;
        }
        t++;
    }
    int num[count];
    int j=0;
    for(t=0;t<count&&(m!=1);t++){
        if(m%prime[t]==0){
            m=m/prime[t];
            num[j]=prime[t];
            j++;
            t=0;
        }
    }
    printf("%d = ",m);
    for(t=0;t<j;t++){
            printf("%d",j);
        printf("%d * ",num[t]);
    }
    printf("%d ",num[t]);
    return 0;

}

