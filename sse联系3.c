#include<stdio.h>
#include<string.h>
#define   MAX_LEN  10                	   /* 字符串最大长度 */
#define   STU_NUM 30                       /* 最多的学生人数 */
#define   COURSE_NUM 6                     /* 最多的考试科目数 */
typedef struct student
{
    long num;	/* 每个学生的学号 */
    char name[MAX_LEN];            	/* 每个学生的姓名 */
    float score[COURSE_NUM];	/* 每个学生COURSE_NUM门功课的成绩 */
    float sum;                       /* 每个学生的总成绩 */
    float aver;                   /* 每个学生的平均成绩 */
}STU;
int   Menu(void);
void  ReadScore(STU *stu, int n, int *m);//读入
void  AverSumofEveryStudent(STU *stu, int n, int m);//每个学生的c
void  AverSumofEveryCourse(STU *stu, int n, int m);//每科的成绩
void  SortbyScore(STU *stu,int n,int m,int (*compare)(float a,float b));//按成绩分
int   Ascending(float a, float b);//升序
int   Descending(float a, float b);//降序
void  SwapFloat(float *x, float *y);//交换分数
void  SwapLong(long *x, long *y);//交换学号
void  SwapChar(char *x, char *y);//交换名字
void  AsSortbyNum(STU *stu, int n, int m);//按名字升序分
void  SortbyName(STU *stu, int n, int m);//按学号分
void  SearchbyNum(STU *stu, int n, int m);
void  SearchbyName(STU *stu, int n, int m);//按学号找
void  StatisticAnalysis(STU *stu, int n, int m);//成绩统计
void  PrintScore(STU *stu, int n, int m);//总输出

int main()
{
    int stunumber=0;
    int counumber=0;//人数和课程数
    int choice=0;
    int (*compare)(float,float);
    printf("Input student number(n<=30):\n");
    scanf("%d",&stunumber);
    STU stu[stunumber];
    do{
    choice=Menu();
    switch(choice){
        case 1:{//录入
            ReadScore(stu,stunumber,&counumber);
            break;
            }
        case 2:{//每科的成绩
            AverSumofEveryCourse(stu,stunumber,counumber);
            break;
             }
        case 3:{//每个人的成绩
            AverSumofEveryStudent(stu,stunumber,counumber);
            break;
             }
        case 4:{//按成绩降序排
            SortbyScore(stu,stunumber,counumber,compare);
            break;
             }
        case 5:{
            SortbyScore(stu,stunumber,counumber,compare);
            break;
             }
        case 6:{
            AsSortbyNum(stu,stunumber,counumber);
            break;
            }
        case 7:{
            SortbyName(stu,stunumber,counumber);
            break;
            }
        case 8:{
            SearchbyNum(stu, stunumber, counumber);
            break;
            }
        case 9:{
            SearchbyName(stu,stunumber,counumber);
            break;
            }
        case 10:{
            StatisticAnalysis(stu,stunumber,counumber);
            break;
            }
        case 11:{
            PrintScore(stu,stunumber,counumber);
            break;
            }
        case 0:{
            printf("End of program!\n");
            break;
            }
            default :
            printf("Input error!\n");
            break;
    }
}while(choice);
return 0;
}


int   Menu(void)
{
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
void  ReadScore(STU *stu, int n, int *m)//读入
{
    int i=0,j=0;
    printf("Input course number(m<=6):\n");
    scanf("%d",m);
    printf("%d",*m);
    printf("Input student's ID, name and score:\n");
    for(i=0;i<n;i++){//循环学生
        scanf("%ld",&stu[i].num);
        scanf("%s",stu[i].name);
            for(j=0;j<*m;j++){
                scanf("%f\n",&stu[i].score[j]);
            }
    }
    for(i=0;i<n;i++){
        printf("%ld\t%s\t",stu[i].num,stu[i].name);
        for(j=0;j<*m;j++){
            printf("%.0f\t",stu[i].score[j]);
        }
      //  printf("%.0f\t%.0f\n",stu[i].num,stu[i].aver);
      printf("\n");
    }

}
void  AverSumofEveryStudent(STU *stu, int n, int m)//每个学生的c
{
     int i=0,j=0;
     for(i=0;i<n;i++){
            stu[i].sum=0;
        for(j=0;j<m;j++){
            stu[i].sum=stu[i].sum+stu[i].score[j];
        }
    }
    for(i=0;i<n;i++){
            stu[i].aver=stu[i].sum/m;
        printf("student %d: sum=%.0f,aver=%.0f\n",i+1,stu[i].sum,stu[i].aver);
    }

}
void  AverSumofEveryCourse(STU *stu,int n,int m)//每科的成绩
{
    int i=0,j=0;
    float sum[m];
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            sum[i]=sum[i]+stu[j].score[i];
        }
    }
    for(i=0;i<m;i++){
        printf("course %d:sum=%.0f,aver=%.0f\n",i+1,sum[i],sum[i]/n);
    }

}
void  SortbyScore(STU *stu,int n,int m,int (*compare)(float a,float b))//按成绩分
{
    int i=0,j=0;
     compare=Descending;
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
   	     int t;
        	t = compare(stu[i].sum,stu[j].sum);
            if(t)
                {
                SwapChar(stu[i].name,stu[j].name);
                SwapLong(&stu[i].num,&stu[j].num);
                SwapFloat(&stu[i].sum,&stu[j].sum);
                SwapFloat(&stu[i].aver,&stu[i].aver);
                SwapFloat(stu[i].score,stu[j].score);
            }
        }
    }
    printf("Sort in ascending order by score:\n");
    for(i=0;i<n;i++){
        printf("%ld\t%s\t",stu[i].num,stu[i].name);
        for(j=0;j<m;j++){
            printf("%.0f\t",stu[i].score[j]);
        }
        printf("%.0f\t%.0f\n",stu[i].sum,stu[i].aver);
    }
}
int   Ascending(float a, float b)//升序
{
    return (a>b);
}
int   Descending(float a, float b)//降序
{
    return (a<b);
}

void  SwapFloat(float *x, float *y)//交换分数
{
    float *t;
    *t=*x;
    *x=*y;
    *y=*t;

}
void  SwapLong(long *x, long *y)//交换学号
{
    long t;
    t=*x;
    *x=*y;
    *y=t;

}
void  SwapChar(char *x, char *y)//交换名字
{
    char *t;
    strcpy(t,x);
    strcpy(x,y);
    strcpy(y,t);

}
void  AsSortbyNum(STU *stu, int n, int m)//按名字升序分
{
    int i=0,j=0;
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            if(strcmp(stu[i].name,stu[j].name)>0){
                SwapChar(stu[i].name,stu[j].name);
                SwapLong(&stu[i].num,&stu[j].num);
                SwapFloat(&stu[i].sum,&stu[j].sum);
                SwapFloat(&stu[i].aver,&stu[i].aver);
                SwapFloat(stu[i].score,stu[j].score);
            }
        }
    }

     printf("Sort in ascending order by name:\n");
     for(i=0;i<n;i++){
        printf("%ld\t%s\t",stu[i].num,stu[i].name);
        for(j=0;j<m;j++){
            printf("%.0f\t",stu[i].score[j]);
        }
        printf("%.0f\t%.0f\n",stu[i].num,stu[i].aver);
    }
}
void  SortbyName(STU *stu, int n, int m)//按学号分
{
    int i=0,j=0;
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            if(stu[i].num>stu[j].num){
               SwapChar(stu[i].name,stu[j].name);
                SwapLong(&stu[i].num,&stu[j].num);
                SwapFloat(&stu[i].sum,&stu[j].sum);
                SwapFloat(&stu[i].aver,&stu[i].aver);
                SwapFloat(stu[i].score,stu[j].score);
            }
        }
    }

    printf("Sort in ascending order by number:\n");
    for(i=0;i<n;i++){
        printf("%ld\t%s\t",stu[i].num,stu[i].name);
        for(j=0;j<m;j++){
            printf("%.0f\t",stu[i].score[j]);
        }
        printf("%.0f\t%.0f\n",stu[i].num,stu[i].aver);
    }
}
void  SearchbyNum(STU *stu, int n, int m)//按学号找
{
    long int t=0;
    int i=0,j=0;
    int isfound=0;
    printf("Input the number you want to search:\n");
    scanf("%ld",&t);
    for(i=0;i<n;i++){
        if(n==stu[i].num){
            isfound=1;
            printf("%ld\t%s\t",stu[i].num,stu[i].name);
            for(j=0;j<m;j++){
                printf("%.0f\t",stu[i].score[j]);
            }
            printf("%.0f\t%.0f\n",stu[i].num,stu[i].aver);
        }
    }
    if(isfound==0){
        printf("Not found!\n");
    }
}
void  SearchbyName(STU *stu, int n, int m)//按名字找
{
   char a[MAX_LEN];
    int isfound=0;
    int i=0,j=0;
    printf("Input the name you want to search:\n");
    scanf("%s",a);
    for(i=0;i<n;i++){
        if(a==stu[i].name){
            isfound=1;
            printf("%ld\t%s\t",stu[i].num,stu[i].name);
            for(j=0;j<m;j++){
                printf("%.0f\t",stu[i].score[j]);
            }
            printf("%.0f\t%.0f\n",stu[i].num,stu[i].aver);
        }
    }
    if(isfound==0){
        printf("Not found!\n");
    }
}
void  StatisticAnalysis(STU *stu, int n, int m)//成绩统计
{
    int i=0,j=0;
    int digit[m][6];
    for(i=0;i<m;i++){
        for(j=0;j<6;j++){
            digit[i][j]=0;
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(stu[j].score[i]<60) digit[i][0]++;
            if(stu[j].score[i]>=60&&stu[j].score[i]<70) digit[i][1]++;
            if(stu[j].score[i]>=70&&stu[j].score[i]<80) digit[i][2]++;
            if(stu[j].score[i]>=80&&stu[j].score[i]<90) digit[i][3]++;
            if(stu[j].score[i]>=90&&stu[j].score[i]<100) digit[i][4]++;
            if(stu[j].score[i]==100) digit[i][5]++;
        }
    }for(i=1;i<=m;i++){
       printf("For course %d:\n",i);
       printf("<60\t%d\t%.2f%%\n",digit[i][0],(digit[i][0]*100.0)/n);
       printf("60-69\t%d\t%.2f%%\n",digit[i][1],(digit[i][1]*100.0)/n);
       printf("70-79\t%d\t%.2f%%\n",digit[i][2],(digit[i][2]*100.0)/n);
       printf("80-89\t%d\t%.2f%%\n",digit[i][3],(digit[i][3]*100.0)/n);
       printf("90-99\t%d\t%.2f%%\n",digit[i][4],(digit[i][4]*100.0)/n);
       printf("100\t%d\t%.2f%%\n",digit[i][5],(digit[i][5]*100.0)/n);
    }

}
void  PrintScore(STU *stu, int n, int m)//总输出
{
    int i=0,j=0;
    for(i=0;i<n;i++){
        printf("%ld\t%s\t",stu[i].num,stu[i].name);
        for(j=0;j<m;j++){
            printf("%.0f\t",stu[i].score[j]);
        }
        printf("%.0f\t%.0f\n",stu[i].num,stu[i].aver);
    }

}
