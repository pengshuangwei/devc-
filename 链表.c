typedef struct LNode *List;
struct LNode{
	ElementType X;
	List Next;
};
struct LNode L;
List PtrL;
//求链表长
int Length (List Ptrl){
	List *P=Ptrl;
	int j=0;
	while(p){
		P=P->Next;
		j++;
	}
	return j;
} 
//查找
 List FindKth(int k,List Ptrl){
 	List p = Ptrl;
 	int i=1;
 	while(p!=NULL && i<k){
 		p=p->Next;
 		i++;
	 }
	 if(i==k){
	 	return k;
	 }
	 else if 
	 return NULL;
 }
 
 List Find(ElementType X,List Ptrl){
 	List p=Ptrl;
 	while(p!=NULL && p->X != X){
 		p=p->Next;
	 }
	 return p;
 } 
 //删除
 void delete1(ElementType x,List Ptrl){
 	List p=Ptrl;
 	List n;
 	while(p!=NULL && p->X != x){
 		n=p;
 		p=p->Next;
	 }
	 if(p){
	 	n->Next=p->Next;
	 	p=NULL;
	 }
	 return Ptrl;
 } 
 void delete2(int k , List Ptrl){
 	List p,n;
 	if(k == 1){
 		s=Ptrl;
 		if(Ptrl){
 			s=Ptrl;
 			if(Ptrl){
	 			Ptrl=Ptrl->Next;
	 			free(s);	
			 }
		 }
		return Ptrl;
	 }
	p=FindKth(i-1,List);
 	n=FindKth(i,List); 
 	if(p == NULL){
 		printf("第%d个节点不存在",i-1);
	 }else if(n == NULL){
	 	printf("第%d个节点不存在",i);
	 }else{
	 	p->Next=n->Next;
	 	free(n);
	 }
	}
 }
 //插入
List  Insert(ElementType x,int i ,List Ptrl){
	List p,s;
	if(i==1){
		s=(List)malloc(sizeof(struct List));
		s->X=x;
		s->Next=Ptrl;
		return s;
	}
	p=FindKth(i-1,List);
	if(p==NULL){
		printf("参数错误");
		return NULL;
	}
	else{
	s=(List)malloc(sizeof(struct List));
	s->X=x;
	s->Next=p->Next;
	p->Next=s;
	return Ptrl;
	}
} 
