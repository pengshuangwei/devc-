#include<stdio.h>
int main()
{
	int num[]={1,2,3,4,5,6,67,7,8,8,};
	int thissum=0,maxsum=0;
	int i=0;
	for(i=0;i<10;i++){
		thissum+=num[i];
		if(thissum>maxsum){
			maxsum=thissum;
		}else if(thissum<0){
			thissum=0;
		}
	}
	printf("------>%d",maxsum);
	return 0;
 } 
