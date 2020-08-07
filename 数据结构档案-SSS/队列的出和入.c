#include<stdio.h>
#include<stdlib.h>
 struct Node{
 	int Data;
 	struct Node *Next;
 };
 struct QNode{
 	struct Node *rear;
	struct Node *front; 
 };
typedef struct QNode *Queue;
void  DeleteQ(Queue PtrQ);
void CreatQ(Queue PtrQ);
void print(Queue PtrQ);
int main()
{
 	Queue PtrQ;
 	PtrQ=(Queue)malloc(sizeof(struct QNode));
 	CreatQ(PtrQ);
 	/*DeleteQ(PtrQ);*/
 	print(PtrQ);
 	free(PtrQ);
 	return 0;
}
void print(Queue PtrQ){
	struct Node *FrontCell;
	 int FrontElem;
	 while(PtrQ->front != NULL){
		 FrontCell = PtrQ->front; 
		 if(PtrQ->front == PtrQ->rear){
		 	PtrQ->front = PtrQ->rear = NULL; 
		 }else{
		 	PtrQ->front = PtrQ->front->Next;
		 }
		 FrontElem = FrontCell->Data;
		 free(FrontCell);
		 printf("%d\t",FrontElem);
	} 
}
void DeleteQ(Queue PtrQ){
	 struct Node *FrontCell;
	 int FrontElem;
	 if(PtrQ->front == NULL){
	 	printf("队列为空");
	 }else{
		 FrontCell = PtrQ->front; 
		 if(PtrQ->front == PtrQ->rear){
		 	PtrQ->front = PtrQ->rear = NULL; 
		 }else{
		 	PtrQ->front = PtrQ->front->Next;
		 }
		 FrontElem = FrontCell->Data;
		 free(FrontCell);
		 printf("----->%d\t",FrontElem);
	} 
 }
void CreatQ(Queue PtrQ){
 	int Data; 
 	struct Node *previous;
 	previous = (struct Node *)malloc(sizeof(struct Node));
 	printf("请输入数字 "); 
 	scanf("%d",&Data);
 	if(Data == -1){
 		free(previous);
 		PtrQ->front = PtrQ->rear =NULL; 
	 }else{
	 	previous->Data = Data;
		previous->Next =NULL; 
	 	PtrQ->front = PtrQ->rear = previous;
	 }
 	while(1){
 		printf("请输入数字 "); 
 		scanf("%d",&Data);
 		if(Data == -1){
 			break;
		 }
 		previous = (struct Node *)malloc(sizeof(struct Node));
 		PtrQ->rear->Next = previous;
 		previous->Data =Data;
	    previous->Next =NULL; 
	    PtrQ->rear = previous;
	}
 }
