#include <stdio.h>
typedef struct  TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode{
	ElementType Data;
	BinTree Left;
	BinTree Right;
}; 
int PostOrderGetHeight( BinTree BT){
	if(BT){
		HL = PostOrderGetHeight(BT->Left);
		HR = PostOrderGetHeight(BT->Right);
		MaxH = (HL > HR)? HL : HR ;
		return (MaxH + 1);
	}
	else return 0; 
}
