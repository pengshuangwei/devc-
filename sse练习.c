#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define   MAX_LEN  10                	   /* �ַ�����󳤶� */
#define   STU_NUM 30                       /* ����ѧ������ */
#define   COURSE_NUM 6                     /* ���Ŀ��Կ�Ŀ�� */
typedef struct student {
	long num;	/* ÿ��ѧ����ѧ�� */
	char name[MAX_LEN];            	/* ÿ��ѧ�������� */
	float score[COURSE_NUM];	/* ÿ��ѧ��COURSE_NUM�Ź��εĳɼ� */
	float sum;                       /* ÿ��ѧ�����ܳɼ� */
	float aver;                   /* ÿ��ѧ����ƽ���ɼ� */
} STU;
int   Menu(void);//�����ʾ��Ϣ ��
void  ReadScore(STU *stu, int n, int *m);//¼��ÿ��ѧ����ѧ�š������͸��ƿ��Գɼ���
void  AverSumofEveryStudent(STU *stu, int n, int m);// ����ÿ��ѧ�����ֺܷ�ƽ���֣�
void  AverSumofEveryCourse(STU *stu, int n, int m);//����ÿ�ſγ̵��ֺܷ�ƽ���֣�
void  SortbyScore(STU *stu,int n,int m,int (*compare)(float a,float b));//���ɼ���ͬ�ų����α� ��
int   Ascending(float a, float b);//�����ж�
int   Descending(float a, float b);//�����ж� ��
void  SwapFloat(float *x, float *y);//����������Ϣ ��
void  SwapLong(long *x, long *y);//����ѧ����Ϣ ��
void  SwapChar(char *x, char *y);//����������Ϣ ��
void  AsSortbyNum(STU *stu, int n, int m);//���������ֵ�˳���ų��ɼ���
void  AsSortbyName(STU *stu, int n, int m);//��ѧ�Ŵ�С�ų����α�
void  SearchbyNum(STU *stu, int n, int m);//��ѧ�Ų�ѯѧ���������俼�Գɼ���
void  SearchbyName(STU *stu, int n, int m);//���������ֵ�˳���ų��ɼ���
void  StatisticAnalysis(STU *stu, int n, int m);//�����㣨90~100�������ã�80~89�����еȣ�70~79��������60~69����������0~59��5�����
//��ÿ�ſγ̷ֱ�ͳ��ÿ�����������Լ���ռ�İٷֱȣ�
void  PrintScore(STU *stu, int n, int m);//���ÿ��ѧ����ѧ�š����������ƿ��Գɼ����Լ�ÿ�ſγ̵��ֺܷ�ƽ���֣�

int main() {
	int stunumber=0;//ѧ���������� ��
	int counumber=0;//�γ������� ��
	int choice=0;//��ͬ��ֵ���в�ͬ�Ĳ��� ��
	int (*compare)(float,float);//���庯��ָ���������������У�
	printf("Input student number(n<=30):\n");//��ʾ��Ϣ ��
	scanf("%d",&stunumber);//����ѧ������ ��
	STU stu[stunumber];//����ṹ������ ��
	do {
		choice=Menu();//�����ʾ��Ϣ��������choice��ֵ ��
		switch(choice) {
			case 1: {
				ReadScore(stu,stunumber,&counumber);
				break;
			}//¼��ÿ��ѧ����ѧ�š������͸��ƿ��Գɼ���
			case 2: {
				AverSumofEveryCourse(stu,stunumber,counumber);
				break;
			}////����ÿ�ſγ̵��ֺܷ�ƽ���֣�
			case 3: {
				AverSumofEveryStudent(stu,stunumber,counumber);
				break;
			}//// ����ÿ��ѧ�����ֺܷ�ƽ���� ��
			case 4: {
				compare=Descending;
				SortbyScore(stu,stunumber,counumber,compare);
				printf("Sort in descending order by score:\n");
				PrintScore(stu,stunumber,counumber);
				break;
			}//��ÿ��ѧ�����ܷ��ɸߵ����ų����α� ��
			case 5: {
				compare=Ascending;
				SortbyScore(stu,stunumber,counumber,compare);
				printf("Sort in ascending order by score:\n");
				PrintScore(stu,stunumber,counumber);
				break;
			}//��ÿ��ѧ�����ܷ��ɵ͵����ų����α�
			case 6: {
				AsSortbyNum(stu,stunumber,counumber);
				printf("Sort in ascending order by number:\n");
				PrintScore(stu,stunumber,counumber);
				break;
			}//��ѧ����С�����ų��ɼ��� ��
			case 7: {
				AsSortbyName(stu,stunumber,counumber);
				printf("Sort in ascending order by name:\n");
				PrintScore(stu,stunumber,counumber);
				break;
			}//���������ֵ�˳���ų��ɼ��� ��
			case 8: {
				SearchbyNum(stu, stunumber, counumber);
				break;
			}//��ѧ�Ų�ѯѧ���������俼�Գɼ� ��
			case 9: {
				SearchbyName(stu,stunumber,counumber);
				break;
			}//��������ѯѧ���������俼�Գɼ� ��
			case 10: {
				StatisticAnalysis(stu,stunumber,counumber);
				break;
			}//�����㣨90~100�������ã�80~89�����еȣ�70~79��������60~69����������0~59��5�����
			//��ÿ�ſγ̷ֱ�ͳ��ÿ�����������Լ���ռ�İٷֱȣ�
			case 11: {
				PrintScore(stu,stunumber,counumber);
				break;
			}//���ÿ��ѧ����ѧ�š����������ƿ��Գɼ����Լ�ÿ�ſγ̵��ֺܷ�ƽ���֣�
			case 0: {
				printf("End of program!\n");
				break;
			}//���������Ϣ ��
			default : {
				printf("Input error!\n");
				break;
			}//���������Ϣ��
		}
	} while(choice);
	return 0;
}


int   Menu(void) {
	int choice=0;
	printf("Management for Students' scores\n"
	       "1.Input record\n"
	       "2.Caculate total and average score of every course\n"
	       "3.Caculate total and average score of every student\n"
	       "4.Sort in descending order by score\n"
	       "5.Sort in ascending order by score\n"
	       "6.Sort in ascending order by number\n"
	       "7.Sort in dictionary order by name\n"
	       "8.Search by number\n"
	       "9.Search by name\n"
	       "10.Statistic analysis\n"
	       "11.List record\n"
	       "0.Exit\n"
	       "Please Input your choice:\n");
	scanf("%d",&choice);
	return choice;
}
void  ReadScore(STU *stu, int n, int *m) {
	int i=0,j=0;
	printf("Input course number(m<=6):\n");
	scanf("%d",m);
	printf("%d",*m);
	printf("Input student's ID, name and score:\n");
	for(i=0; i<n; i++) {
		scanf("%ld",&stu[i].num);
		scanf("%s",stu[i].name);
		for(j=0; j<*m; j++) {
			scanf("%f",&stu[i].score[j]);
		}
	}
}
void  AverSumofEveryStudent(STU *stu, int n, int m) {
	int i=0,j=0;
	for(i=0; i<n; i++) {
		stu[i].sum=0;
		for(j=0; j<m; j++) {
			stu[i].sum=stu[i].sum+stu[i].score[j];
		}
	}
	for(i=0; i<n; i++) {
		stu[i].aver=stu[i].sum/m;
		printf("student %d: sum=%.0f,aver=%.0f\n",i+1,stu[i].sum,stu[i].aver);
	}

}
void  AverSumofEveryCourse(STU *stu,int n,int m) {
	int i=0,j=0;
	float sum[m];
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			sum[i]=sum[i]+stu[j].score[i];
		}
	}
	for(i=0; i<m; i++) {
		printf("course %d:sum=%.0f,aver=%.0f\n",i+1,sum[i],sum[i]/n);
	}

}
void  SortbyScore(STU *stu,int n,int m,int (*compare)(float a,float b)) {
	int i=0,j=0,t=0;
	for(i=0; i<n; i++) {
		for(j=i+1; j<n; j++) {
			if(compare(stu[i].sum,stu[j].sum)){
				SwapChar(stu[i].name,stu[j].name);
				SwapLong(&stu[i].num,&stu[j].num);
				SwapFloat(&stu[i].sum,&stu[j].sum);
				SwapFloat(&stu[i].aver,&stu[j].aver);
				for(t=0; t<m; t++) {
					SwapFloat(&stu[i].score[t],&stu[j].score[t]);
				}
			}
		}
	}
}
int   Ascending(float a, float b) {
	return (a>b);
}
int   Descending(float a, float b) {
	 return (a<b);
}

void  SwapFloat(float *x, float *y) {
	float *t;
	*t=*x;
	*x=*y;
	*y=*t;

}
void  SwapLong(long *x, long *y) {
	long *t;
	*t=*x;
	*x=*y;
	*y=*t;

}
void  SwapChar(char *x, char *y) {
	char *t;
	t=(char*)malloc(sizeof(x));
	strcpy(t,x);
	strcpy(x,y);
	strcpy(y,t);
	free(t);
}
void  AsSortbyName(STU *stu, int n, int m) {
	int i=0,j=0,t=0;
	for(i=0; i<n; i++) {
		for(j=i+1; j<n; j++) {
			if(strcmp(stu[i].name,stu[j].name)>0) {
				SwapChar(stu[i].name,stu[j].name);
				SwapLong(&stu[i].num,&stu[j].num);
				SwapFloat(&stu[i].sum,&stu[j].sum);
				SwapFloat(&stu[i].aver,&stu[i].aver);
				for(t=0; t<m; t++) {
					SwapFloat(&stu[i].score[t],&stu[j].score[t]);
				}
			}
		}
	}
}
void  AsSortbyNum(STU *stu, int n, int m) {
	int i=0,j=0,t=0;
	for(i=0; i<n; i++) {
		for(j=i; j<n; j++) {
			if(stu[i].num>stu[j].num) {
				SwapChar(stu[i].name,stu[j].name);
				SwapLong(&stu[i].num,&stu[j].num);
				SwapFloat(&stu[i].sum,&stu[j].sum);
				SwapFloat(&stu[i].aver,&stu[i].aver);
				for(t=0; t<m; t++) {
					SwapFloat(&stu[i].score[t],&stu[j].score[t]);
				}
			}
		}
	}
}
void  SearchbyNum(STU *stu, int n, int m) {
	long int t=0;
	int i=0,j=0;
	int isfound=0;
	printf("Input the number you want to search:\n");
	scanf("%ld",&t);
	for(i=0; i<n; i++) {
		if(t==stu[i].num) {
			isfound=1;
			printf("%ld\t%s\t",stu[i].num,stu[i].name);
			for(j=0; j<m; j++) {
				printf("%.0f\t",stu[i].score[j]);
			}
			printf("%.0f\t%.0f\n",stu[i].num,stu[i].aver);
			break;
		}
	}
	if(isfound==0) {
		printf("Not found!\n");
	}
}
void  SearchbyName(STU *stu, int n, int m) {
	char a[MAX_LEN];
	int isfound=0;
	int i=0,j=0;
	printf("Input the name you want to search:\n");
	scanf("%s",a);
	for(i=0; i<n; i++) {
		if(a==stu[i].name) {
			isfound=1;
			printf("%ld\t%s\t",stu[i].num,stu[i].name);
			for(j=0; j<m; j++) {
				printf("%.0f\t",stu[i].score[j]);
			}
			printf("%.0f\t%.0f\n",stu[i].num,stu[i].aver);
			break;
		}
	}
	if(isfound==0) {
		printf("Not found!\n");
	}
}
void  StatisticAnalysis(STU *stu, int n, int m) {
	int i=0,j=0;
	int digit[m][6];
	for(i=0; i<m; i++) {
		for(j=0; j<6; j++) {
			digit[i][j]=0;
		}
	}
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			if(stu[j].score[i]<60) digit[i][0]++;
			if(stu[j].score[i]>=60&&stu[j].score[i]<70) digit[i][1]++;
			if(stu[j].score[i]>=70&&stu[j].score[i]<80) digit[i][2]++;
			if(stu[j].score[i]>=80&&stu[j].score[i]<90) digit[i][3]++;
			if(stu[j].score[i]>=90&&stu[j].score[i]<100) digit[i][4]++;
			if(stu[j].score[i]==100) digit[i][5]++;
		}
	}
	for(i=0; i<=m; i++) {
		printf("For course %d:\n",i+1);
		printf("<60\t%d\t%.2f%%\n",digit[i][0],(digit[i][0]*100.0)/n);
		printf("60-69\t%d\t%.2f%%\n",digit[i][1],(digit[i][1]*100.0)/n);
		printf("70-79\t%d\t%.2f%%\n",digit[i][2],(digit[i][2]*100.0)/n);
		printf("80-89\t%d\t%.2f%%\n",digit[i][3],(digit[i][3]*100.0)/n);
		printf("90-99\t%d\t%.2f%%\n",digit[i][4],(digit[i][4]*100.0)/n);
		printf("100\t%d\t%.2f%%\n",digit[i][5],(digit[i][5]*100.0)/n);
	}

}
void  PrintScore(STU *stu, int n, int m) {
	int i=0,j=0;
	for(i=0; i<n; i++) {
		printf("%ld\t%s\t",stu[i].num,stu[i].name);
		for(j=0; j<m; j++) {
			printf("%.0f\t",stu[i].score[j]);
		}
		printf("%.0f\t%.0f\n",stu[i].sum,stu[i].aver);
	}

}
