#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *play;
	char str[1024]="崔艺琼，你个大憨憨，我和你讲，不要天天欺\
	负我家彭双威，他那么帅气，那么可爱，你要是再欺负他，他就不和你玩了";
	play=fopen("大憨憨.vbs","w+");
	fprintf(play,Createobject("SAPI.SpVoice").speak(%s),str);
	fclose(play);
	system("大憨憨.vbs");
	return 0;
}
