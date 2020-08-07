//#include<stdio.h>
//void read(int num[],int n);
//int maxsum(int num[],int n);
//int main(){
//    int n;
//    scanf("%d",&n);
//    int num[n];
//	read(num,n);
//    printf("%d",maxsum(num,n));
//    return 0;
//}
//void read(int num[],int n){
//    int i=0;
//    for (i=0;i<n;i++){
//        scanf("%d",&num[i]);
//    }
//}
//int maxsum(int num[],int n){
//    int thissum=0;
//    int maxsum=0;
//    int i=0;
//    for(i=0;i<n;i++){
//        thissum+=num[i];
//        if(thissum > maxsum){
//            maxsum=thissum;
//        }
//        if(thissum < 0){
//            thissum=0;
//        }
//    }
//    return maxsum;
//}
#include<stdio.h>
#include<stdlib.h>
void read(int num[],int n);
int maxsum(int num[],int n);
int main(){
    int n;
    int *left=NULL;
	int *data=NULL;
	left=(int*)malloc(sizeof(int));
	data=(int*)malloc(sizeof(int));
    int gap,Maxsum;
    scanf("%d",&n);
    *left = n-1;
	*data = n-1;
    int num[n];
	read(num,n);
    Maxsum=max(num,n,left,data);
    gap=*left - *data;
    printf("%d %d %d",Maxsum,num[gap],num[*left]);
    return 0;
}
void read(int num[],int n){
    int i=0;
    for (i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
}
int max(int num[],int n,int *left,int *data){
    int thissum=0;
    int maxsum=0;
    int i=0;
    int find=0;
    for(i=0;i<n;i++){
        thissum+=num[i];
        if(thissum > maxsum){
            maxsum=thissum;
            *left = i;
            *data=find;
        }
        if(thissum < 0){
            thissum=0;
            find = 0; 
        }else{
        	find++;
		}
    }
    return maxsum;
}
