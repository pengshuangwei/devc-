#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *play;
	char str[1024]="����������󺩺����Һ��㽲����Ҫ������\
	���Ҽ���˫��������ô˧������ô�ɰ�����Ҫ�����۸��������Ͳ���������";
	play=fopen("�󺩺�.vbs","w+");
	fprintf(play,Createobject("SAPI.SpVoice").speak(%s),str);
	fclose(play);
	system("�󺩺�.vbs");
	return 0;
}
