//#define Maxsiez//˳��洢��������
////typedef struct SNode *Stack;
////struct SNode{
////	ElementType Data [Maxsize];
////	int Top;
////}; 
//void Push(Stack Ptrs,ElementTYpe item){
//	if(Ptrs->Top == Maxsize - 1){
//		printf("��ջ����"); 
//		return;
//	}
//	Ptrs->Data[++(Ptrs->Top)] = item;
//}//��ջ
// ElementType pop(Stack Ptrs){
// 	if( Ptrs->Top == -1){
// 		printf("��ջ�ѿ�");
// 		return ERROR; 
//	 }else{
//	 	return (Ptrs->Data[(Ptrs->Top)--]); 
//	 } 
// } 
// //��ջ
// #define Maxsize 10 //�洢���Ԫ�ظ���
// struct Dstack{
// 	ElementType Data[Maxsize];
// 	int Top1;
// 	int Top2;
// }S;
//S.Top1=-1;
//S.Top2=Maxsize;
//void Push(struct DStack *Ptrs,ElementType item,int Tag)
//{//ͨ��Tag�ж��Ƕ��Ǹ���ջ���� 
//	if(Ptrs->Top2 - Ptrs->Top1 == 1){
//		printf("��ջ��");
//		return; 
//	}//�ж϶�ջ�Ƿ����� 
//	if(Tag){
//		Ptrs->Data[++(Ptrs->Tog1)] == item;
//	}else{
//		Ptrs->Data[--(Ptrs->Tog2)] == item;
//	}
//}
//ElementType Pop(struct DStack *Ptrs,int Tag){
//	if(Tag == 1){
//		if(Ptrs->Tog1 == -1){
//			printf("��ջ�ѿ�");
//			return NULL; 
//		}else{
//		return Ptrs->Data[(Ptrs->Tog1)--]; 
//	}else{
//		if(Ptrs->Tog2 == Maxsize){
//			printf("��ջ�ѿ�");
//			return NULL; 
//		}else{
//		return Ptrs->Data[(Ptrs->Tog2)++]; 
//		} 
//} 


#��ջ����ʽʵ��
typedef struct SNode *Stack;
struct SNode{
	ElementType Data;
	Stack Next; 
};
Stack CreateStack()
{//����һ����ջ��ͷ�ڵ㣬������ָ��
	Stack S;
	S=(Stack)malloc(sizeof(struct SNode));
	S->Next = NULL;
	return S; 
}
int IsEmpty(Stack S){
	//�ж�һ����ջ�Ƿ�Ϊ��
	return (S->Next == NULL); 
}
void Push(Stack S,ElementType item){
	//��Ԫ��itemѹ���ջ
	Stack previous = NULL;
	previous=(Stack)malloc(sizeof(struct SNode));
	previous->Data = item;
	previous->Next = S->Next;
	S->Next = previous; 
} 
ElementType pop(Stack S){
	//��ɾ�������ض�ջ��Ԫ��
	ElementType TopElem;
	 Stack previous = NULL; 
	 if(IsEmpty(S)){
	 	printf("��ջ�ѿ�");
		 return NULL; 
	 }else{
		 previous = S->Next;
		 S->Next = previous->Next;
		 TopElem = previous->Data;
		 free(previous);
		 return TopElem; 
	}
} 
