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
	printf("������������Ĳ������������Ϊ��1:Teacher 2��Offical 3:Giant\n");
	scanf("%d",&choice1);
	while(true){
		char ch1='n';
		switch(choice1){
			case 1:
				printf("��������/�������������ţ�����͹�����Ϣ\n");
				scanf("%s %ld %d %d",teacher.name,&teacher.EID,&teacher.Glade,&teacher.Salary);
				printf("��������/����Ժϵ��רҵ\n");
				scanf("%s %s",teacher.School,teacher.Discipine);
				char ch;
				printf("�Ƿ���������ְ��y/n\n");
				getchar();
				ch=getchar();
				if(ch=='y'){
					teacher.Glade+=1;
					teacher.Salary+=Quto1;
				}
				printf("����Ϊ����Ա�����Ϣ\n");
				printf("%s\t%ld\t%d\t%d\n",teacher.name,teacher.EID,teacher.Glade,teacher.Salary);
				printf("%s\t%s\n",teacher.School,teacher.Discipine);
				break;
			case 2:
				printf("��������/�������������ţ�����͹�����Ϣ\n");
				scanf("%s %ld %d %d",offical.name,&offical.EID,&offical.Glade,&offical.Salary);	
				printf("��������/���Ĵ��Һ͹�ְ\n");
				scanf("%s %s",offical.Departmant,offical.Position);
				char ch2;
				printf("�Ƿ���������ְ��y/n");
				getchar();
				ch2=getchar();
				if(ch2=='y'){
					offical.Glade+=1;
					offical.Salary+=Quto2;
				}
				printf("����Ϊ����Ա�����Ϣ\n");
				printf("%s\t%ld\t%d\t%d\n",offical.name,offical.EID,offical.Glade,offical.Salary);
				printf("%s\t%s\n",offical.Departmant,offical.Position);
				break;
			case 3:
				printf("��������/�������������ţ�����͹�����Ϣ\n");
				scanf("%s %ld %d %d",giant.name,&giant.EID,&giant.Glade,&giant.Salary);
				printf("��������/����Ժϵ,רҵ�����Һ͹�ְ\n");
				scanf("%s %s %s %s",giant.School,giant.Discipine,giant.Departmant,giant.Position);
				char ch3;
				printf("�Ƿ���������ְ��y/n\n");
				getchar();
				ch3=getchar();
				if(ch3=='y'){
					offical.Glade+=1;
					offical.Salary+=Quto2;
				}
				printf("�Ƿ���������ְ��y/n\n");
				ch3=scanf("%c",&ch);
				if(ch3=='y'){
					teacher.Glade+=1;
					teacher.Salary+=Quto1;
				}
				printf("����Ϊ����Ա�����Ϣ\n");
				printf("%s\t%ld\t%d\t%d\n",giant.name,giant.EID,giant.Glade,giant.Salary);
				printf("%s\t%s\n",giant.School,giant.Discipine);
				printf("%s\t%s\n",giant.Departmant,giant.Position);
				break;
			default :
				printf("��������Ƿ���������,y/n\n");
				scanf("%c",&ch1);
				break;
		}
		if(ch1=='n'){
			break;
		}
	}
	return 0;
}
