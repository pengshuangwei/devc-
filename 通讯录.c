#include<stdio.h>
struct birthday{
    int year;
    int month;
    int day;
};
struct Address{
    char *name;
    struct birthday date;
    char *telephone;
    char *Mobile;
    char sex;
};
int main()
{
    int N,n,num[n];
    int i,j;
    scanf("%d",&N);
    struct Address number[N];
    for(i=0;i<N;i++){
        scanf("%s %d/%d/%d %c %s %s",number[i].name,number[i].date.year,number[i].date.month,number[i].date.day,number[i].sex,number[i].telephone,number[i].Mobile);
    }
    scanf("%d",&n);
    for(j=0;j<n;j++){
  		scanf("%d",&num[j]);
    }
    for(j=0;j<n;j++){
		i=num[j]+1;
	    if(i<N)
		   printf("%s %s %s %c %d/%d/%d",number[i].name,number[i].telephone,number[i].Mobile,number[i].sex,number[i].date.year,number[i].date.month,number[i].date.day);
		else
		printf("Not Found");
	}
    return 0;

}
