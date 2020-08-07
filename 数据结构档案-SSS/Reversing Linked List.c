#include<stdio.h>
typedef struct Snode{
    int address;
    int data;
    int  nextaddress;
}Node;
void create(Node num[],int number);
int tidy(Node num[],int number,int headaddress);
void rev(Node node[],int num,int rev_num);
void print(Node node[],int nunm);
int main(){
    int count;
    int headaddress,num,rev_num;
    scanf("%d %d %d",&headaddress,&num,&rev_num);
    Node node[num];
    int n;
    create(node,num);
    n = tidy(node,num,headaddress);
    rev(node,n,rev_num);
    print(node,n);
    return 0;
}
void create(Node num[],int number){
    int i=0;
    for(i=0;i<number;i++){
        scanf("%d %d %d",&num[i].address,&num[i].data,&num[i].nextaddress);
    }
}
int tidy(Node num[],int number,int headaddress){
    int i=0,j=0;
    int realnum=0;
    for(i=0;i<number;i++){
        for(j=i;j<number;j++){
            if(num[j].address == headaddress){
                exchange(&num[i].address,&num[j].address);
                exchange(&num[i].data,&num[j].data);
                exchange(&num[i].nextaddress,&num[j].nextaddress);
                headaddress = num[i].nextaddress;
                realnum++;
                break;
            }
        }
        if(num[i].nextaddress == -1){
            break;
        }
    }
    return realnum;
}
void exchange(int*a,int*b){
    int n = 0;
    n = *a;
    *a = *b;
    *b = n;
}
void  rev(Node node[],int num,int rev_num){
    int count = num /rev_num;
    int i=0;
    for(i=1;i<=count;i++){
        int j = (i-1)*rev_num;
        int c=1;
        int n=j+rev_num/2;
        for(j;j<n;j++){
            exchange(&node[j].address,&node[j+rev_num-c].address);
            exchange(&node[j].data,&node[j+rev_num-c].data);
            exchange(&node[j].nextaddress,&node[j+rev_num-c].nextaddress);
            c=c+2;
        }
    }
    if(rev_num<num ){
	   for(i=0;i < (count*rev_num)-1;i++){
	    	node[i].nextaddress=node[i+1].address;
		}
	}
	else{
		for(i=0;i<rev_num-1;i++){
			node[i].nextaddress=node[i+1].address;
		} 
	}
	node[num].nextaddress=-1;
}
void print(Node node[],int num){
    int i=0;
    for(i;i<num-1;i++){
        printf("%05d %d ",node[i].address,node[i].data);
        if(node[i].nextaddress < 0){
        	printf("%d\n",node[i].nextaddress);
		}else{
			printf("%05d\n",node[i].nextaddress);
		}
    }
    printf("%05d %d ",node[i].address,node[i].data);
        if(node[i].nextaddress < 0){
        	printf("%d\n",node[i].nextaddress);
		}else{
			printf("%05d\n",node[i].nextaddress);
		};
}


