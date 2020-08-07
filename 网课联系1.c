#include<stdio.h>
int main()
{
int number;int choice=0;
printf("Input student number(n<30):\n");
scanf("%d",&number);
long int ID[number];
float score[number];
do{
    printf("Management for Students' scores\n"
    "1.Input record\n"
    "2.Caculate total and average score of course\n"
    "3.Sort in descending order by score\n"
    "4.Sort in ascending order by number\n"
    "5.Search by number\n"
    "6.Statistic analysis\n"
    "7.List record\n"
    "0.Exit\n"
    "Please Input your choice:\n");
int i=0;
scanf("%d",&choice);
if(choice<0&&choice>7){
    printf("Input error!");
}else{
    switch(choice){
        case 1:{
		printf("Input student's ID, name and score:\n");
        for(i=0;i<number;i++){
            scanf("%ld%f",&ID[i],&score[i]);
          //  printf("%ld,%f\n",ID[i],score[i]);
        }
        break;}
        case 2:{
		float  sum=0.0;
        for(i=0;i<number;i++){
        //	printf("%f\n",score[i]);
            sum=sum+score[i];
           // printf("%f\n",sum);
        }
        printf("sum=%.0f,aver=%.2f\n",sum,sum/number);
        break;}
        case 3:{
        printf("Sort in descending order by score:\n");
        int j=0;
        for(i=0;i<number;i++){
            for(j=0;j<number;j++){
                if(score[i]<score[j]){
                    float t=0;
                    t=score[j];
                    score[j]=score[i];
                    score[i]=t;
                    long int k=0;
                    k=ID[j];
                    ID[j]=ID[i];
                    ID[i]=k;
                }
            }
            for(i=0;i<number;i++){
                printf("%ld\t%.0f\n",ID[i],score[i]);
            }

        }break;}
        case 4:{
        printf("Sort in ascending order by number:\n");
        int j=0;
        for(i=0;i<number;i++){
            for(j=0;j<number;j++){
                if(ID[i]<ID[j]){
                    long int t=0.0;
                    t=ID[j];
                    ID[j]=ID[i];
                    ID[i]=t;
                    float k=0;
                    k=score[j];
                    score[j]=score[i];
                    score[i]=t;
                }
            }
            for(i=0;i<number;i++){
                printf("%ld\t%.0f\n",ID[i],score[i]);
            }

        }break;}
        case 5:{
        printf("Input the number you want to search:\n");
       long int Id=0;
		int isfound=0;
        scanf("%ld",&Id);
        for(i=0;i<number;i++){
            if(Id==ID[i]){
                printf("%ld\t%.0f\n",ID[i],score[i]);
                isfound=1;
                break;
            }
        }if(!isfound){
            printf("Not found!\n");
        }break;}
        case 6:{
       	int num1=0,num2=0,num3=0,num4=0,num5=0,num6=0;
        for(i=0;i<number;i++){
            if(score[i]<60)num1++;
            else if(score[i]>=60&&score[i]<70)num2++;
            else if(score[i]>=70&&score[i]<80)num3++;
            else if(score[i]>=80&&score[i]<90)num4++;
            else if(score[i]>=90&&score[i]<100)num5++;
            else num6++;
        }
        printf("<60\t%d\t%.2f%%\n",num1,num1/number);
        printf("60-69\t%d\t%.2f%%\n",num2,num2/number);
        printf("70-79\t%d\t%.2f%%\n",num3,num3/number);
        printf("80-89\t%d\t%.2f%%\n",num4,num4/number);
        printf("90-99\t%d\t%.2f%%\n",num5,num5/number);
        printf("100\t%d\t%.2f%%\n",num6,num6/number);
        break;}
        case 7:{
        for(i=0;i<number;i++){
            printf("%ld\t%f\n",ID[i],score[i]);
        }break;}
        case 0:{
        printf("End of program!");
        break;
   	    }
    }
}
    }while(choice);
    return 0;
}

//
