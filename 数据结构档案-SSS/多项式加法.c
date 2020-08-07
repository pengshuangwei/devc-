#include<stdio.h> 
#include<stdlib.h>
struct PolyNode{
	int coef;
	int expon;
	struct PolyNode *link;
};
typedef struct PolyNode *Polynomial;
void Attach(int c,int e,Polynomial *pRear);
int main(){
	


	return 0;
}


Polynomial PolyAdd (Polynomial P1,Polynomial P2) 
{
	Polynomial front,rear,temp;
	int sum;
	front = (Polynomial)malloc(sizeof(struct PolyNode));
	rear = front;
	while(P1 && P2){
		switch(Compare(P1->expon,P2->expon)){
			case 1:
				Attach(P1->coef,P1->expon,&rear);
				P1 = P1->link;
				break;
			case 2:
				Attach(P2->coef,P2->expon,&rear);
				P2 = P2->link;
				break;
			case 0:
				sum = P1->coef + P2->coef;
				if(sum)Attach(sum,P1->expon,&rear);
				P1 = P1->link;
				P2 = P2->link;
				break; 
		}
	}
	for(;P1;P1->link){
		Attach(P1->coef,P1->expon,&rear); 
	} 
	for(;P2;P2->link){
		Attach(P2->coef,P2->expon,&rear); 
	}
	rear->link = NULL;
	temp = front;
	front = front->link;
	free(temp);
	return temp; 
} 

void Attach(int c,int e,Polynomial *pRear){
	Polynomial P;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->coef = c;
	P->expon = e;
	P->link = NULL;
	(*pRear)->link = P;
	*pRear = P; 
}
int Compare(int a,int b){
	int num=0;
	if(a > b){
		num = 1;
	}else if(a <b){
		num = -1;
	}
	return num;
}
