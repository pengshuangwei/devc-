//队列的链式存储
 struct Node{
 	ElementType Data;
 	struct Node *Next;
 };
 struct QNode{
 	struct Node *rear;
	struct Node *front; 
 };
 typedef struct QNode *Queue;
 Queue PtrQ;
 ElementType DeleteQ(Queue PtrQ){
 	//不带头节点的链式队列的出队
	 struct Node *FrontCell;
	 ElementType FrontElem;
	 if(PtrQ->front == NULL){
	 	printf("队列为空");
	 	return ERROR; 
	 }
	 FrontCell = PtrQ->front; 
	 if(PtrQ->front == PtrQ->rear){
	 	PtrQ->front = PtrQ->rear = NULL; 
	 }else{
	 	PtrQ->front = PtrQ->front->Next;
	 }
	 FrontElem = FrontCell->Data;
	 free(FrontCell);
	 return FrontElem;
 } 
 void AddQ(Queue PtrQ){
 	ElementType Data; 
 	struct Node *previous;
 	previous = (struct Node *)malloc(sizeof(struct Node));
 	scanf("%d",&Data);
 	previous->Data = Data;
	previous->Next =NULL; 
 	PtrQ->front = PtrQ->rear = previous;
 	while(Data != -1){
 		scanf("%d",&Data);
 		previous = (struct Node *)malloc(sizeof(struct Node));
 		previous->Data = Data;
	    previous->Next =NULL; 
	    PtrQ->rear =previous;
	 }
 }
