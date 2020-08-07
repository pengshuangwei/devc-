#include<stdio.h>
void yu (int **m);
int main()
{
	int *p;
	*p = 7;
	yu(&p);
	printf("%d",*p);
	return 0;
 } 
 void yu(int **m){
 	int num=9;
 	*m=&num;
 	
 }
