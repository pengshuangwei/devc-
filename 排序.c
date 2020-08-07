#include<stdio.h>
int main(){
	int a[8]={34,234,436,235,235,236,36547,76,};
	int i=0,j=0;
	for(i=0;i<8;i++){
		for  (j=i;j<8;j++){
			if(a[i]<a[j]){
				int t=0;
				t=a[j];
				a[j]=a[i];
				a[i]=t;
			}
		}
	}
	for(i=0;i<8;i++){
		printf("%d",a[i]);
	}
	return 0;
}
