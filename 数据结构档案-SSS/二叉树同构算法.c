#include <stdio.h>
#include <stdlib.h>
#define Maxsize 10 

typedef struct Tree{
    char ch;
    int left;
    int  right;
}Data; 
Data data1[Maxsize],data2[Maxsize];
int  createData(Data* data);
int main()
{
    int R1,R2;
    R1 = createData(data1);
    R2 = createData(data2);
    if(Isomorphic(R1,R2)) printf("YES\n");
    else printf("N0\n");
    

}
int createData(Data* data)
{
    int num,Root = -1;
    char cl,cr;
    int isfound = 0;
    int check[Maxsize];
    scanf("%d",&num);
    int i=0;
    for(i=0;i<Maxsize;i++) check[i] = 0;
    for(i=0;i<num;i++){
    	getchar();
        scanf("%c %c %c",&data[i].ch,&cl,&cr);
        if(cl != '-'){
            data[i].left =(int)(cl - '0');
            check[data[i].left] = 1;
        }else data[i].left = -1;
        if(cr != '-'){
            data[i].right =(int)(cr - '0');
            check[data[i].right] = 1;
         }else data[i].right = -1;
    }
    for( i=0;i<num;i++){
        if(!check[i]){
        	isfound = 1;
        	 break;
		}    
    }
    if(isfound) Root = i;
    return Root;
}
int Isomorphic(int R1,int R2)
{
    if(R1 == -1 && R2 == -1)
        return 1;
    if(R1 == -1 || R2 == -1)
        return 0;
    if(data1[R1].ch != data2[R2].ch)
        return 0;
    if(data1[R1].left == -1 && data2[R2].left == -1)
        return (Isomorphic(data1[R1].right,data2[R2].right));
    if(((data1[R1].left != -1)&&(data2[R2].left != -1)) && ((data1[data1[R1].left].ch)==(data2[data2[R2].left].ch)))
        return (Isomorphic(data1[R1].left,data2[R2].left) && Isomorphic(data1[R1].right,data2[R2].right));
    else
        return (Isomorphic(data1[R1].left,data2[R2].right) && Isomorphic(data1[R1].right,data2[R2].left));
}
