/*���е�˳��洢*/ 
#include<stdio.h>
Queue CreatQueue( int Maxsize);//���ɳ���ΪMaxsize�Ķ���
int IsFullQ(Queue Q,int Maxsize);//�ж϶����Ƿ�����
void AddQ(Queue Q,ElementType item);//��Ԫ�ز��뵽������
int IsEmptyQ( Queue Q);//�ж϶����Ƿ�Ϊ�� 
ElementType Delete(Queue Q);//����������Ԫ�شӶ�����ɾ�������� 
#define MaxSize;
struct QNode{
	ElementType Data [MaxSize];
	int rear;
	int front; 
}; 
typedef struct QNode *Queue;
void Addq(Queue PtrQ,ElementType item){
	if((PtrQ->rear+1)%MaxSize == PtrQ->front){
		printf("������");
		return;
	}
	PtrQ->rear = (PtrQ->rear+1)%MaxSize;
	PtrQ->Data[PtrQ->rear]=item; 
}//�����
ElementType DeleteQ(Queue PtrQ)
{
	if(PtrQ->front == PtrQ->rear){
		printf("���п�");
		return ERROR;
	}else{
		PtrQ->front = (PtrQ->front+1)%MaxSize;
		return PtrQ->Data[PtrQ->front]; 
	}
 } 
