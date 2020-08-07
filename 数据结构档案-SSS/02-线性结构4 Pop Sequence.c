#include<stdio.h>
#include<stdlib.h>
#define Maxsize 1000
typedef struct {
    int num[1000];
}Data;
void read(Data data[],int K,int N);/*记录给出的pop序列*/
void deal(int num[][Maxsize],Data data[],int K,int N);/*将给出的Pop序列按递增顺序整理；*/
void judge(int num[][Maxsize],Data data[],int K,int N,int M);
int main(){
    int M,N,K;
    scanf("%d %d %d",&M,&N,&K);
    Data data[K];
    int num[K][N+1];
    read(data,K,N);
    deal(num,data,K,N);
    judge(num,data,K,N,M);
    return 0;
}
void read(Data data[],int K, int N){
    int i=0,j=0;
    for(i=0;i<K;i++){
        for(j=0;j<N;j++){
            scanf("%d",&data[i].num[j]);
        }
    }
}
void deal(int num[][Maxsize],Data data[],int K,int N){
    int min=0,max=N;
    int i,j;
    int isfound=0;
    for(i=0;i<K;i++){
        isfound=0,min=0,max=N;
        for(j=N-1;j>0;j--){
            if(data[i].num[j]<data[i].num[j-1]){
                num[i][min++]=data[i].num[j];
            }else{
                num[i][--max]=data[i].num[j];
                isfound++;
            }
        }
        num[i][min++]=data[i].num[0];
        num[i][N]=isfound;
    }
}
void judge(int num[][Maxsize],Data data[],int K,int N,int M){
    int i,j;
    int isfound=1;
    for(i=0;i<K;i++){
        if(num[i][N] == 0 &&(M < N)){
            printf("NO\n");
        }else{
            for(j=0;j<N;j++){
                if(num[i][j] != j+1){
                    printf("NO\n");
                    isfound = 0;
                    break;
                }
            }
            if(isfound != 0){
                printf("YES\n");
            }
            isfound=1;
        }
    }
}


