typedef struct LNode *List;
struct LNode{
	ElemenType Data[MAXSIE];
	int Last;
};
struct LNode L;
List Ptrl; 
//�����յ�˳���
List MakeEmpty()
{
	List Ptrl;
	Ptrl = (List)malloc(sizeof(struct LNode));
	Ptrl->Last=-1; 
 } return Ptrl;
 //���� 
 int Find(ElementType X,List Ptrl)
 {
 	int i=0;
 	while(i <= Ptrl->Last && Ptrl->Data[i] != x)
 		i++;
 	if(i > Ptrl->Last)
 		return -1;
 	else
 		return i;
  } 
 //����
 void Insert(ElementType X,int i, List Ptrl)
 {
 	int j=0;
 	if(Last==MAXSIZE-1){
 		printf("����");
		 return ; 
	 }
	 if(i < 1 && i > Last+2){
	 	printf("λ�ò��Ϸ�");
		 return ; 
	 }
	 for(j=Ptrl->Last;j>=i-1){
	 	Ptrl->Data[j+1]=Ptrl->Data[j];
	 }
	 Ptrl->Data[i]=X;
	 Ptrl->Last++;
	 return ;
	 
 } 
 //ɾ��
 void Delete(int i,List Ptrl,int Last)
 {
 	for(i<1||i>Ptrl->Last+1){
 		printf("��λ�ò�����Ԫ��"); 
	 }
 	for(i;i<Ptrl->Last;i++){
 		Ptrl->Data[i]=Ptrl->Data[i+1];
	 }
	 Ptrl->Data[i]=-1;
	 Ptrl->Last--;
	 return ; 
 }
