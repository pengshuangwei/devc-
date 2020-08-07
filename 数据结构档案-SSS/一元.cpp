#include<stdio.h>
#include<stdlib.h>
typedef struct Lnode *List;
typedef struct Lnode{
    int data;
    int index;
    List next;
}Data;
List cread(List head);
void print(List head); 
List  multipli(List head1,List head2,List pc);
List add(List head1,List head2,List L);
void merge(List pc);
void rock (List head);
int main()
{
    List head1,head2;
    List head,L;
    head1=cread(head1);
	head2=cread(head2);
	head=multipli(head1,head2,head);
	L=add(head1,head2,L);
	print(head);
	print(L);
// 	head1=NULL;
// 	head2=NULL;
	return 0; 
}
List cread(List head){
	head=(List)malloc(sizeof(Data));
    scanf("%d",&head->data);
    head->index=-1;
    List current=NULL;
    List previous=NULL;
    head->next=NULL;
    int i=1;
    for(i=1;i<=head->data;i++){
        current=(List)malloc(sizeof(Data));
        if(head->next==NULL){
            head->next=current;
        }
        if(previous != NULL){
            previous->next=current;
        }
        scanf("%d %d",&current->data,&current->index);
        current->next=NULL;
        previous=current;
    }
    return head;
}
void print(List head){
// 	List p=NULL; 
// 	p=head;
	head=head->next;
// 	free(p);
	while(head->next){
		printf("%d %d ",head->data,head->index);
//  		p=head;
//  		head=head->next;
// 		free(p);
//  		p=NULL;
	}
	printf("%d %d",head->data,head->index);
// 	p=head;
// 	free(head);
// 	p=NULL;
}
List multipli(List head1,List head2,List head)
{
	head=(List)malloc(sizeof(Data));
	List pa,pb;
	pa=head1->next;
	pb=head2->next;
	List current;
    List previous;
	while(pa){
		while(pb){
    		current=(List)malloc(sizeof(Data));
	        if(head->next==NULL){
	            head->next=current;
	        }
	        if(previous != NULL){
	            previous->next=current;
	        }
	        current->data=pa->data*pb->data;
	        current->index=pa->index+pb->index; 
	        current->next=NULL;
	        previous=current;
	        pb=pb->next;
			}
		pa=pa->next;
		pb=head2->next;
	}
	merge(head);
	rock(head);
	return head;
}
void merge(List pc){
	List pa,current,pb;
	pa=pc->next;
	if(pc==NULL){
		printf("Пе"); 
	}
	while(pa){
		pb=pa;
		while(pb->next){
			current=pb->next;
			if(current->index==pa->index){
				pa->data+=current->data;
				pb->next=current->next;
				free(current);
				current=NULL;
			} 
			pb=pb->next;
		}
		pa=pa->next;
	}
}
List add(List head1,List head2,List L){
	L=(List)malloc(sizeof(Data));
	List pa;
	List pb; 
	List pc;
	pc=L;
	pa=head1->next;
	pb=head2->next;
	while(pa && pb){
        if(pa->data >= pb->data){
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }else{
            pc->next=pa;
            pc=pa;
            pa=pa->next;
        }
    }
    pc->next = pa ? pa : pb;
    merge(L);
    rock(L);
    return L;
} 
void rock (List head){
	int data=0;
	int index=0;
	List current;
	List previous;
	current=head->next;
	while(current){
		previous=current->next;
		while(previous){
			if(current->index<previous->index){
				data=previous->data;
				previous->data=current->data;
				current->data=data;
				index=previous->index;
				previous->index=current->index;
				current->index=index; 
			}
			previous=previous->next;
		}
		current=current->next;
	}
}
