#include<stdio.h>
#include<stdlib.h>
#include<ctype.h> 
typedef struct Lnode *List;
struct Lnode{
    int data;
    int index;
    List next;
};
List cread(List head);
void print(List head); 
List  multipli(List head1,List head2,List pc);
List add(List head1,List head2,List L);
void merge(List pc);
void rock (List head);
int main()
{
    List head1=NULL,head2=NULL;
    List head=NULL,L=NULL;
    head1=cread(head1);
	head2=cread(head2);
	head=multipli(head1,head2,head);
	L=add(head1,head2,L);
	print(head);
	print(L);
	head1=NULL;
	head2=NULL;
	return 0; 
}
List cread(List head){
	head=(List)malloc(sizeof(struct Lnode));
    scanf("%d",&head->data);
    head->index=-1;
    List current=NULL;
    List previous=NULL;
    head->next=NULL;
    int i=1;
    for(i=1;i<=head->data;i++){
        current=(List)malloc(sizeof(struct Lnode));
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
	List p=NULL; 
	p=head;
	head=head->next;
	free(p);
	if(head==NULL){
		printf("¿Ø"); 
	}
	while(head->next){
		printf("%d %d ",head->data,head->index);
		p=head;
		head=head->next;
		free(p);
		p=NULL;
	}
	printf("%d %d",head->data,head->index);
	p=head;
	free(head);
	p=NULL;
}
List multipli(List head1,List head2,List head)
{
	head=(List)malloc(sizeof(struct Lnode));
	head->next=NULL; 
	List pa=NULL,pb=NULL;
	pa=head1->next;
	pb=head2->next;
	List current=NULL;
    List previous=NULL;
	while(pa){
		while(pb){
    		current=(List)malloc(sizeof(struct Lnode));
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
	List pa=NULL,current=NULL,pb=NULL;
	pa=pc->next;
	if(pc==NULL){
		printf("¿Õ"); 
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
	L=(List)malloc(sizeof(struct Lnode));
	List pa=NULL;
	List pb=NULL; 
	List pc=NULL;
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
    rock (L); 
    return L;
} 
void rock (List head){
	int data=0;
	int index=0;
	List current=NULL;
	List previous=NULL;
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
