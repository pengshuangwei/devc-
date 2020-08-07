//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	FILE *write=fopen("day1.txt","w+");
//	char str[]="come on !"; 
//	/*int i=0;
//	for(i=0;i<strlen(str)+1;i++){
//		fputc(str[i],write);
//	}*/
//	fputs(str,write);
//	fclose(write);
//	FILE *read=fopen("day1.txt","r");
//	char ch[1024]=""; 
//	fgets(ch,1024,read);
//	/*while(ch!=EOF){
//		printf("%c",ch);
//		ch=fgetc(read);
//	}*/
//	printf("%s",ch);
//	fclose(read); 
//	return 0;
// } 
#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *write = fopen("Speak.vbs","w+");
	fprintf(write,"Createobject(\"SAPI.SpVoice\").speak(\"给你讲个故事：有一天龘????蚮?? 龘????蚮??????? \
	???? ?? 龘????蚮??????? ???莔艸彳\
饢蘿蘿靄饢靨爛驫寵灣龍贏爨 瘸驫嚴戀蔞讀鑭鷚爨籮 饢驫嚴? ?? 龘????蚮????\
蟿??城 龘????死了\")");
	fclose(write);
	system ("Speak.vbs");
	return 0;
 } 
