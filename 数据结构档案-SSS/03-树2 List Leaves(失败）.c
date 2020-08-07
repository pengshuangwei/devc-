#include <stdio.h>
#include <stdlib.h>
#define Maxsize 10
typedef struct TreeNode{
    char left;
    char right;
}Tree;//�������Ľṹ�� 
Tree tree[Maxsize];
int createTree(Tree * tree);//����������ݽ���Ϊ������̬���ӣ� 
void PrintTree(int Root);//���մ��ϵ��£������ҵ�˳�����Ҷ�� 
int main()
{
    int Root;//������¼���ڵ�������±� 
    Root = createTree(tree);
    PrintTree(Root);
    return 0;
    
}
int createTree(Tree * tree)
{
    int num,i = 0;
    int Root;
    char cr,cl;//��¼��������ҽڵ����ֵ 
    int isfound = 0;//������ֹ�ձ����� 
    
    scanf("%d",&num);
    
    int check[num];
    
    for(i=0;i<num;i++) check[i] = 0;
    for(i=0;i<num;i++){
    	
    	getchar();
    	//ѭ�������������ֵ��Ҫ��д�����Ľṹ�� 
        scanf("%c %c",&cr,&cl);
        if(cr != '-'){
            tree[i].left = cr - '0';//�ַ��͵�����ת�� 
            check[tree[i].left] = 1;
        }else tree[i].left = -1;//-1��ʾ�˴��ڵ�Ϊ�� 
        if(cl != '-'){
            tree[i].right = cl - '0';
            check[tree[i].right] = 1;
        }else tree[i].right = -1;
    }
    
    for(i=0;i<num;i++){
        if(!check[i]){
        	//ͨ����ڵ������±���ͬ�����飬���ҳ����ڵ� 
            isfound = 1; 
            break;
	        }
	    }
        if(isfound)//��ֹ�ձ�ʱ���ַ��������ء� 
            Root = i;
        return Root;
}
void PrintTree(int Root)
{
	    if(tree[Root].left == -1 && tree[Root].right == -1){
	        printf("%d ",Root);//�жϸýڵ��Ƿ�ΪҶ��� 
	    }
	 	if(tree[tree[Root].left].left == -1 && tree[tree[Root].left].right == -1){
	        printf("%d ",tree[Root].left);//�жϸý��ָ��������Ƿ�ΪҶ��� 
	    }if(tree[tree[Root].right].left == -1 && tree[tree[Root].right].right == -1){
	        printf("%d ",tree[Root].right);// �жϸý��ָ����ҽ���Ƿ�ΪҶ���
	    }

}
