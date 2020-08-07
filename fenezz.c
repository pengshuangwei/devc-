#include<stdio.h>
int Findmax(int num1,int num2,int num[]);
int main()
{
    int k=0;
    int max=0;
    scanf("%d",&k);
    int num[k];
    int i;
    for(i=0;i<k;i++){
        scanf("%d",&num[i]);
    }
    max=Findmax(0,k,num);
    if(max>0){
    printf("%d",max);
}
    else{
        printf("0");
    }
    return 0;
}

int Findmax(int num1,int num2,int num[])
{
    int max;
    if(num1==num2){
        max=num[num1];
    }else{
        int middle;
        middle=(num1+num2)/2;
        int leftmax=Findmax(num1,middle,num);
        int rightmax=Findmax(middle+1,num2,num);
        int middlenum=num[middle]+num[middle+1];
        int middlemax=middlenum;
        for(int i=middle-1;i>=num1;i--){
            middlenum+=num[i];
            if(middlenum>middlemax){
                middlemax=middlenum;
            }
        }
            middlenum=middlemax;
        for(int i=middle+2;i<=num2;i++){
                middlenum+=num[i];
                if(middlenum>middlemax){
                middlemax=middlenum;
            }
        }
        if(leftmax>middlemax){
            max=leftmax;
        }else if(rightmax>middlemax){
            max=rightmax;
        }else{
            max=middlemax;
        }

    }
    return max;
}
