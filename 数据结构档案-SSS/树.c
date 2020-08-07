typedef struct  TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode{
	ElementType Data;
	BinTree Left;
	BinTree Right;
}; 

/*先序遍历
第一步：访问根结点；
第二步：先序遍历左子树
第三步：先序遍历右子树
*/
void PreOrderTraversal(BinTree BT)
{
	if( BT ){
		printf("%d",BT->Data);
		PreOrderTraversal( BT->Left);
		PreOrderTraversal( BT->Right);
	} 
}  
/*先序遍历
第一步：先序遍历左子树
第二步：访问根结点；
第三步：先序遍历右子树
*/
void InOrderTraversal( BinTree BT)
{
	if(BT){
		InOrderTraversal( BT->Left);
		printf("%d",BT->Data);
		InOrderTraversal( BT->Right); 
	}
}
/*先序遍历
第一步：先序遍历左子树
第二步：先序遍历右子树
第三步：访问根结点；
*/
void PostOrderTraversal( BinTree BT)
{
	if( BT){
		PostOrderTraversal(BT->Left);
		PostOrderTraversal(BT->Right);
		printf("%d",BT->Data);
	}
 } 
/*中序非递归输出
遇到一个结点，就把他压栈，并遍历其左子树，
当左子树遍历结束，从栈顶弹出该节点并访问
然后按其右指针再去中序遍历该节点右子树
*/ 
void InOrderTraversal( BinTree BT)
{
	BinTree T = BT;
	Stack S = CreateStack( Maxsize);
	while( T || !IsEmpty(S)){
		while(T){
			Push (S,T);
			t = T->Left;
		}
		if( ! IsEmpty(S) ){
			T = Pop(S);
			printf("%5d",T->Data);
			T = T->Right;
		}
	} 
 } 
 /*先序非递归输出
遇到一个结点，先访问再把他压栈，并遍历其左子树，
当左子树遍历结束，从栈顶弹出该节点
然后按其右指针再去中序遍历该节点右子树
*/ void PreOrderTraversal(BinTree BT){
	BinTree T = BT;
	stack  S = CreateStack( Maxsize);
	while( T || !IsEmpty){
		while(T){
			printf("%5d",T->Data);
			Push(S,T);
			T = T->Left;
		}
		while(!IsEmpty(S)){
			T = Pop(S);
			T = T->Right;
		}
	}
}
void LevelOrderTraversal( BinTree BT)
{
	Queue Q;BinTree T;
	if(!BT) return ;
	Q = CreateQueue(MaxSize);
	while(!IsEmmptyQ( Q )){
		T = DeleteQ( Q );
		printf("%d\n",T->Data);
		if (T->Left ) AddQ(Q,T->Left);
		if (T->Right ) AddQ(Q,T->Right); 
	}
}
/*遍历输出二叉树中的叶子结点*/
void PreOrderPrintLeaves( BinTree BT)
{
	if(BT){
		if( !BT->Left && !BT->Right){
			printf("%5d",BT->Data);
			PreOrderPrintLeaves( BT->Left);
			PreOrderPrintLeaves( BT->Right); 
		}
	}
 } 
