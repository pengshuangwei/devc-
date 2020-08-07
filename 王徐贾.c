#include<stdio.h>
#include<stdbool.h>
typedef  struct{
	char name[30];
	long EID;
	int Glade;
	int Salary;
	char School[30];
	char Discipine[20]; 
} Teacher;
typedef struct {
	char name[30];
	long EID;
	int Glade;
	int Salary;
	char Departmant[30];
	char Position[30];
}Offical;
typedef struct {
	char name[30];
	long EID;
	int Glade;
	int Salary;
	char School[30];
	char Discipine[20]; 
	char Departmant[30];
	char Position[30];
}Giant;

int main()
{
	int Quto1=300;
	int Quto2=3000;
	int choice1;
	Teacher teacher;
	Offical offical;
	Giant giant;
	printf("请问你接下来的操作对象的属性为：1:Teacher 2：Offical 3:Giant\n");
	scanf("%d",&choice1);
	while(true){
		char ch1='n';
		switch(choice1){
			case 1:
				printf("请输入他/她的姓名，工号，级别和工资信息\n");
				scanf("%s %ld %d %d",teacher.name,&teacher.EID,&teacher.Glade,&teacher.Salary);
				printf("请输入她/他的院系和专业\n");
				scanf("%s %s",teacher.School,teacher.Discipine);
				char ch;
				printf("是否增加他的职称y/n\n");
				getchar();
				ch=getchar();
				if(ch=='y'){
					teacher.Glade+=1;
					teacher.Salary+=Quto1;
				}
				printf("下面为该人员相关信息\n");
				printf("%s\t%ld\t%d\t%d\n",teacher.name,teacher.EID,teacher.Glade,teacher.Salary);
				printf("%s\t%s\n",teacher.School,teacher.Discipine);
				break;
			case 2:
				printf("请输入他/她的姓名，工号，级别和工资信息\n");
				scanf("%s %ld %d %d",offical.name,&offical.EID,&offical.Glade,&offical.Salary);	
				printf("请输入她/他的处室和官职\n");
				scanf("%s %s",offical.Departmant,offical.Position);
				char ch2;
				printf("是否增加他的职务y/n");
				getchar();
				ch2=getchar();
				if(ch2=='y'){
					offical.Glade+=1;
					offical.Salary+=Quto2;
				}
				printf("下面为该人员相关信息\n");
				printf("%s\t%ld\t%d\t%d\n",offical.name,offical.EID,offical.Glade,offical.Salary);
				printf("%s\t%s\n",offical.Departmant,offical.Position);
				break;
			case 3:
				printf("请输入他/她的姓名，工号，级别和工资信息\n");
				scanf("%s %ld %d %d",giant.name,&giant.EID,&giant.Glade,&giant.Salary);
				printf("请输入她/他的院系,专业，处室和官职\n");
				scanf("%s %s %s %s",giant.School,giant.Discipine,giant.Departmant,giant.Position);
				char ch3;
				printf("是否增加他的职务y/n\n");
				getchar();
				ch3=getchar();
				if(ch3=='y'){
					offical.Glade+=1;
					offical.Salary+=Quto2;
				}
				printf("是否增加他的职称y/n\n");
				ch3=scanf("%c",&ch);
				if(ch3=='y'){
					teacher.Glade+=1;
					teacher.Salary+=Quto1;
				}
				printf("下面为该人员相关信息\n");
				printf("%s\t%ld\t%d\t%d\n",giant.name,giant.EID,giant.Glade,giant.Salary);
				printf("%s\t%s\n",giant.School,giant.Discipine);
				printf("%s\t%s\n",giant.Departmant,giant.Position);
				break;
			default :
				printf("输入错误，是否重新输入,y/n\n");
				scanf("%c",&ch1);
				break;
		}
		if(ch1=='n'){
			break;
		}
	}
	return 0;
}
