//#define Maxsiez//顺序存储的最大个数
////typedef struct SNode *Stack;
////struct SNode{
////	ElementType Data [Maxsize];
////	int Top;
////}; 
//void Push(Stack Ptrs,ElementTYpe item){
//	if(Ptrs->Top == Maxsize - 1){
//		printf("堆栈已满"); 
//		return;
//	}
//	Ptrs->Data[++(Ptrs->Top)] = item;
//}//入栈
// ElementType pop(Stack Ptrs){
// 	if( Ptrs->Top == -1){
// 		printf("堆栈已空");
// 		return ERROR; 
//	 }else{
//	 	return (Ptrs->Data[(Ptrs->Top)--]); 
//	 } 
// } 
// //出栈
// #define Maxsize 10 //存储最大元素个数
// struct Dstack{
// 	ElementType Data[Maxsize];
// 	int Top1;
// 	int Top2;
// }S;
//S.Top1=-1;
//S.Top2=Maxsize;
//void Push(struct DStack *Ptrs,ElementType item,int Tag)
//{//通过Tag判断是对那个堆栈操作 
//	if(Ptrs->Top2 - Ptrs->Top1 == 1){
//		printf("堆栈满");
//		return; 
//	}//判断堆栈是否已满 
//	if(Tag){
//		Ptrs->Data[++(Ptrs->Tog1)] == item;
//	}else{
//		Ptrs->Data[--(Ptrs->Tog2)] == item;
//	}
//}
//ElementType Pop(struct DStack *Ptrs,int Tag){
//	if(Tag == 1){
//		if(Ptrs->Tog1 == -1){
//			printf("堆栈已空");
//			return NULL; 
//		}else{
//		return Ptrs->Data[(Ptrs->Tog1)--]; 
//	}else{
//		if(Ptrs->Tog2 == Maxsize){
//			printf("堆栈已空");
//			return NULL; 
//		}else{
//		return Ptrs->Data[(Ptrs->Tog2)++]; 
//		} 
//} 


#堆栈的链式实现
typedef struct SNode *Stack;
struct SNode{
	ElementType Data;
	Stack Next; 
};
Stack CreateStack()
{//创建一个堆栈的头节点，并返回指针
	Stack S;
	S=(Stack)malloc(sizeof(struct SNode));
	S->Next = NULL;
	return S; 
}
int IsEmpty(Stack S){
	//判断一个堆栈是否为空
	return (S->Next == NULL); 
}
void Push(Stack S,ElementType item){
	//将元素item压入堆栈
	Stack previous = NULL;
	previous=(Stack)malloc(sizeof(struct SNode));
	previous->Data = item;
	previous->Next = S->Next;
	S->Next = previous; 
} 
ElementType pop(Stack S){
	//是删除并返回堆栈的元素
	ElementType TopElem;
	 Stack previous = NULL; 
	 if(IsEmpty(S)){
	 	printf("堆栈已空");
		 return NULL; 
	 }else{
		 previous = S->Next;
		 S->Next = previous->Next;
		 TopElem = previous->Data;
		 free(previous);
		 return TopElem; 
	}
} 
