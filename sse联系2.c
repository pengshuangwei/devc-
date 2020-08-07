

/*从键盘任意输入一个整数m，若m不是素数，则对m进行质因数分解，并将m表示为质因数从小到大顺序排列的乘积形式输出，否则输出"It is a prime number"。例如，用户输入90时，程序输出90 = 2 * 3 * 3 * 5；用户输入17时，程序输出"It is a prime number"。
输入提示信息："Input m:"
输入格式："%d"
输出格式：
是素数时输出"It is a prime number\n"
否则输出用"%d = "，"%d * "
运行示例1：
Input m:90↙
90 = 2 * 3 * 3 * 5
运行示例2：
Input m:13↙
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

