#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *read=fopen("thing.txt","r");
	fseek(read,0L,SEEK_END);
	int len=ftell(read);
	printf("%d\n",len);
	char  num[10]="";
	printf("----->%ld\n",sizeof(num));
	fseek(read,0L,SEEK_SET);
	fgets(num,len,read);
	printf("%s",num);
	fclose(read);
	char  num1[19]="12345678";
	int i=0;
	for(i=0;i<19;i++){
		printf("%d,--->,%c",i,num1[i]);
		printf("\n");
	}
	return 0;
 } 
