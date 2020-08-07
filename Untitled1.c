#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *deletem( struct ListNode *L, int m );
void printlist( struct ListNode *L )
{
     struct ListNode *p = L;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    int m;
    struct ListNode *L = readlist();
    scanf("%d", &m);
    L = deletem(L, m);
    printlist(L);

    return 0;
}

/* 你的代码将被嵌在这里 */
struct ListNode *readlist()
{
    struct ListNode *head=NULL;
    struct ListNode *previous=NULL;
    struct ListNode *end=NULL;
    do{
        previous=(struct ListNode*)malloc(sizeof(struct ListNode));
        if(!head){
            head=previous;
        }
        if(end){
            end->next=previous;
        }
        scanf("%d",&previous->data);
        if(previous->data==-1){
            end->next=NULL;
            free(previous);
            break;
        }else{
        previous->next=NULL;
        end=previous;
        }
    }while(end->data!=-1);
    return head;
}
struct ListNode *deletem( struct ListNode *L, int m )
{
    struct ListNode *head=NULL;
    struct ListNode *previous=NULL;
    head=L;
    do{
        if(head->data==m){
            previous=head;
            head=head->next;
            free(previous);
        }
        head=head->next;
    }while(head);
    do{
        previous=head->next;
        if(previous->data==m){
            head->next=previous->next;
            free(previous);
        }else{
            head=head->next;
        }
    }while(head);
    return L;
}
