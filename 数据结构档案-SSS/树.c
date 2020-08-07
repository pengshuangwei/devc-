typedef struct  TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode{
	ElementType Data;
	BinTree Left;
	BinTree Right;
}; 

/*�������
��һ�������ʸ���㣻
�ڶ������������������
���������������������
*/
void PreOrderTraversal(BinTree BT)
{
	if( BT ){
		printf("%d",BT->Data);
		PreOrderTraversal( BT->Left);
		PreOrderTraversal( BT->Right);
	} 
}  
/*�������
��һ�����������������
�ڶ��������ʸ���㣻
���������������������
*/
void InOrderTraversal( BinTree BT)
{
	if(BT){
		InOrderTraversal( BT->Left);
		printf("%d",BT->Data);
		InOrderTraversal( BT->Right); 
	}
}
/*�������
��һ�����������������
�ڶ������������������
�����������ʸ���㣻
*/
void PostOrderTraversal( BinTree BT)
{
	if( BT){
		PostOrderTraversal(BT->Left);
		PostOrderTraversal(BT->Right);
		printf("%d",BT->Data);
	}
 } 
/*����ǵݹ����
����һ����㣬�Ͱ���ѹջ������������������
��������������������ջ�������ýڵ㲢����
Ȼ������ָ����ȥ��������ýڵ�������
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
 /*����ǵݹ����
����һ����㣬�ȷ����ٰ���ѹջ������������������
��������������������ջ�������ýڵ�
Ȼ������ָ����ȥ��������ýڵ�������
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
/*��������������е�Ҷ�ӽ��*/
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
