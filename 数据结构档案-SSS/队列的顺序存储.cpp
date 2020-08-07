/*队列的顺序存储*/ 
#include<stdio.h>
Queue CreatQueue( int Maxsize);//生成长度为Maxsize的队列
int IsFullQ(Queue Q,int Maxsize);//判断队列是否已满
void AddQ(Queue Q,ElementType item);//将元素插入到队列中
int IsEmptyQ( Queue Q);//判断队列是否为空 
ElementType Delete(Queue Q);//将队列数据元素从队列中删除并返回 
#define MaxSize;
struct QNode{
	ElementType Data [MaxSize];
	int rear;
	int front; 
}; 
typedef struct QNode *Queue;
void Addq(Queue PtrQ,ElementType item){
	if((PtrQ->rear+1)%MaxSize == PtrQ->front){
		printf("队列满");
		return;
	}
	PtrQ->rear = (PtrQ->rear+1)%MaxSize;
	PtrQ->Data[PtrQ->rear]=item; 
}//入队列
ElementType DeleteQ(Queue PtrQ)
{
	if(PtrQ->front == PtrQ->rear){
		printf("队列空");
		return ERROR;
	}else{
		PtrQ->front = (PtrQ->front+1)%MaxSize;
		return PtrQ->Data[PtrQ->front]; 
	}
 } 
