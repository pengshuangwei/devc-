#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num[]={2,3,4,5,-56,6,7};
	int i=0,j=0;
	int max=0,sum=0;
	for( i=0; i<7;i++){
		for(j=i;j<7;j++){
			sum+=num[j];
			if(sum>max){
				max=sum;
			}
		}
		sum=0;
	}
	if(max>=0){
		printf("%d",max);
	}else{
		printf("0");
	}
	return 0;
	
} 
