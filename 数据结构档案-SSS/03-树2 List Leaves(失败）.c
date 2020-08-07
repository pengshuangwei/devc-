#include <stdio.h>
#include <stdlib.h>
#define Maxsize 10
typedef struct TreeNode{
    char left;
    char right;
}Tree;//创建树的结构体 
Tree tree[Maxsize];
int createTree(Tree * tree);//将读入的数据建立为树（静态链接） 
void PrintTree(int Root);//按照从上到下，从左到右的顺序输出叶子 
int main()
{
    int Root;//用来记录根节点的数组下表 
    Root = createTree(tree);
    PrintTree(Root);
    return 0;
    
}
int createTree(Tree * tree)
{
    int num,i = 0;
    int Root;
    char cr,cl;//记录键入的左右节点的数值 
    int isfound = 0;//用来防止空表的情况 
    
    scanf("%d",&num);
    
    int check[num];
    
    for(i=0;i<num;i++) check[i] = 0;
    for(i=0;i<num;i++){
    	
    	getchar();
    	//循环处理，将键入的值按要求写入数的结构体 
        scanf("%c %c",&cr,&cl);
        if(cr != '-'){
            tree[i].left = cr - '0';//字符型到整型转化 
            check[tree[i].left] = 1;
        }else tree[i].left = -1;//-1表示此处节点为空 
        if(cl != '-'){
            tree[i].right = cl - '0';
            check[tree[i].right] = 1;
        }else tree[i].right = -1;
    }
    
    for(i=0;i<num;i++){
        if(!check[i]){
        	//通过与节点数组下标相同的数组，来找出根节点 
            isfound = 1; 
            break;
	        }
	    }
        if(isfound)//防止空表时出现非正常返回。 
            Root = i;
        return Root;
}
void PrintTree(int Root)
{
	    if(tree[Root].left == -1 && tree[Root].right == -1){
	        printf("%d ",Root);//判断该节点是否为叶结点 
	    }
	 	if(tree[tree[Root].left].left == -1 && tree[tree[Root].left].right == -1){
	        printf("%d ",tree[Root].left);//判断该结点指向的左结点是否为叶结点 
	    }if(tree[tree[Root].right].left == -1 && tree[tree[Root].right].right == -1){
	        printf("%d ",tree[Root].right);// 判断该结点指向的右结点是否为叶结点
	    }

}
