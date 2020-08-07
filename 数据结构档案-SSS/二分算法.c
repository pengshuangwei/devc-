#include<stdio.h>
#include<stdlib.h>
int max(int list[],int right,int left)
{
	int maxleft=0,maxright=0;
	int center=0,i=0;
	int Max=0;
	int thisleftsum=0,maxleftsum=0;
	int thisrightsum=0,maxrightsum=0;
	center=(right+left)/2;
	if(left == right){
		if(list[left]>0){
			return list[left];
		}else{
			return 0;
		}
	}
	maxleft=max(list,left,center);
	maxright=max(list,center+1,right);
	for(i=center;i>=left;i--){
		thisleftsum+=list[i];
		if(thisleftsum>maxleftsum){
			maxleftsum=thisleftsum;
		}
	}
	for(i=center+1;i<=right;i++){
		thisrightsum+=list[i];
		if(thisrightsum>maxrightsum){
			maxrightsum=thisrightsum;
		}
	}
	if(maxleft>maxright&&maxleft>(maxleftsum+maxrightsum)){
		Max=maxleft;
		}
	else if(maxright>maxleft&&maxright>(maxleftsum+maxrightsum)){
		Max=maxright;
	}else{
		Max=maxrightsum+maxleftsum;
	}
	return Max;
}
int main()
{
	int num[]={-1,2,99,5,6,7,8,-8,-6,-5};
//	int i=0;
//	for(i=0;i<10;i++){
//		printf("%d\n",num[i]);
//	}
	int Max1=0;
	Max1=max(num,0,9);
	printf("------->%d",Max1);
	return 0;
}
