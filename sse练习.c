#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define   MAX_LEN  10                	   /* 字符串最大长度 */
#define   STU_NUM 30                       /* 最多的学生人数 */
#define   COURSE_NUM 6                     /* 最多的考试科目数 */
typedef struct student {
	long num;	/* 每个学生的学号 */
	char name[MAX_LEN];            	/* 每个学生的姓名 */
	float score[COURSE_NUM];	/* 每个学生COURSE_NUM门功课的成绩 */
	float sum;                       /* 每个学生的总成绩 */
	float aver;                   /* 每个学生的平均成绩 */
} STU;
int   Menu(void);//输出提示信息 ；
void  ReadScore(STU *stu, int n, int *m);//录入每个学生的学号、姓名和各科考试成绩；
void  AverSumofEveryStudent(STU *stu, int n, int m);// 计算每个学生的总分和平均分；
void  AverSumofEveryCourse(STU *stu, int n, int m);//计算每门课程的总分和平均分；
void  SortbyScore(STU *stu,int n,int m,int (*compare)(float a,float b));//按成绩不同排出名次表 ；
int   Ascending(float a, float b);//升序判断
int   Descending(float a, float b);//降序判断 ；
void  SwapFloat(float *x, float *y);//交换分数信息 ；
void  SwapLong(long *x, long *y);//交换学号信息 ；
void  SwapChar(char *x, char *y);//交换名字信息 ；
void  AsSortbyNum(STU *stu, int n, int m);//按姓名的字典顺序排出成绩表；
void  AsSortbyName(STU *stu, int n, int m);//按学号大小排出名次表；
void  SearchbyNum(STU *stu, int n, int m);//按学号查询学生排名及其考试成绩；
void  SearchbyName(STU *stu, int n, int m);//按姓名的字典顺序排出成绩表；
void  StatisticAnalysis(STU *stu, int n, int m);//按优秀（90~100）、良好（80~89）、中等（70~79）、及格（60~69）、不及格（0~59）5个类别，
//对每门课程分别统计每个类别的人数以及所占的百分比；
void  PrintScore(STU *stu, int n, int m);//输出每个学生的学号、姓名、各科考试成绩，以及每门课程的总分和平均分；

int main() {
	int stunumber=0;//学生人数变量 ；
	int counumber=0;//课程数变量 ；
	int choice=0;//不同的值进行不同的操作 ；
	int (*compare)(float,float);//定义函数指针便于升序或降序排列；
	printf("Input student number(n<=30):\n");//提示信息 ；
	scanf("%d",&stunumber);//输入学生人数 ；
	STU stu[stunumber];//定义结构体数组 ；
	do {
		choice=Menu();//输出提示信息并都读入choice的值 ；
		switch(choice) {
			case 1: {
				ReadScore(stu,stunumber,&counumber);
				break;
			}//录入每个学生的学号、姓名和各科考试成绩；
			case 2: {
				AverSumofEveryCourse(stu,stunumber,counumber);
				break;
			}////计算每门课程的总分和平均分；
			case 3: {
				AverSumofEveryStudent(stu,stunumber,counumber);
				break;
			}//// 计算每个学生的总分和平均分 ；
			case 4: {
				compare=Descending;
				SortbyScore(stu,stunumber,counumber,compare);
				printf("Sort in descending order by score:\n");
				PrintScore(stu,stunumber,counumber);
				break;
			}//按每个学生的总分由高到低排出名次表 ；
			case 5: {
				compare=Ascending;
				SortbyScore(stu,stunumber,counumber,compare);
				printf("Sort in ascending order by score:\n");
				PrintScore(stu,stunumber,counumber);
				break;
			}//按每个学生的总分由低到高排出名次表；
			case 6: {
				AsSortbyNum(stu,stunumber,counumber);
				printf("Sort in ascending order by number:\n");
				PrintScore(stu,stunumber,counumber);
				break;
			}//按学号由小到大排出成绩表 ；
			case 7: {
				AsSortbyName(stu,stunumber,counumber);
				printf("Sort in ascending order by name:\n");
				PrintScore(stu,stunumber,counumber);
				break;
			}//按姓名的字典顺序排出成绩表 ；
			case 8: {
				SearchbyNum(stu, stunumber, counumber);
				break;
			}//按学号查询学生排名及其考试成绩 ；
			case 9: {
				SearchbyName(stu,stunumber,counumber);
				break;
			}//按姓名查询学生排名及其考试成绩 ；
			case 10: {
				StatisticAnalysis(stu,stunumber,counumber);
				break;
			}//按优秀（90~100）、良好（80~89）、中等（70~79）、及格（60~69）、不及格（0~59）5个类别，
			//对每门课程分别统计每个类别的人数以及所占的百分比；
			case 11: {
				PrintScore(stu,stunumber,counumber);
				break;
			}//输出每个学生的学号、姓名、各科考试成绩，以及每门课程的总分和平均分；
			case 0: {
				printf("End of program!\n");
				break;
			}//输出结束信息 ；
			default : {
				printf("Input error!\n");
				break;
			}//输出错误信息；
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
