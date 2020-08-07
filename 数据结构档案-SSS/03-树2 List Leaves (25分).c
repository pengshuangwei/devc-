#include <stdio.h>
#include <stdlib.h>
#define Maxsize 10
typedef struct TreeNode{
    int data;
    int left;
    int right;
}Tree;//创建树的结构体 
Tree tree[Maxsize]; 
int main()
{
    int num,i=0;
    int queue[Maxsize];
    int n,flag = 0;
    int rear1,front1;
    rear1=front1=-1;
    char l,r;
    scanf("%d",&num);
    int check[num];
    for(i=0;i<num;i++) check[i] = 0;
    for(i=0;i<num;i++){
    	getchar();
        scanf("%c %c",&l,&r);
        tree[i].data = i;
        if(l!='-'){
        	check[l-'0'] = 1;
        	tree[i].left = l-'0'; 
		}else tree[i].left = -1;
        if(r!='-'){
        	check[r-'0'] = 1;
        	tree[i].right = r-'0';
		}else tree[i].right = -1;
    }
    for(i=0;i<num;i++){
        if(!check[i])
            queue[++rear1] = i;
    }
    while(front1 != rear1){
        n = queue[++front1];
        if(tree[n].left != -1)
            queue[++rear1] = tree[n].left;
        if(tree[n].right != -1)
            queue[++rear1] = tree[n].right;
        if(tree[n].left == -1 && tree[n].right == -1){
            if(flag){
                flag = 1;
            }else{
                printf(" ");
            }
            printf("%d",tree[n].data);
        }
    }
    return 0;
}

