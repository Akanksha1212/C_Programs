#include<stdio.h>
#include<stdlib.h>
// Forward Linked List
struct List{
	int value ;  
	struct List *node; 
};
struct List *head = NULL;
int numElem = 0;
int InsertEnd(int v)
{

	struct List *newNode =(struct List*) malloc(sizeof(struct List));
	newNode -> value = v;
	newNode->node= NULL;
	if(head==NULL){
		head= newNode;
	}
	else{
		struct List *temp ;
		temp = head;
		while(temp->node!=NULL){
			temp = temp->node;
		}
		temp->node = newNode; 
		
		}
	numElem++;
	
}
int PrintLinkedList(){
	printf("\n");
	if(numElem ==0 ){
		printf("\n Linked List Empty  :( ");
	}
	else {
		struct List *temp;
		temp =head ;
		while(temp !=NULL){
			printf(" %d ",temp->value);
			temp=temp->node;
		}
		
	}
}
int InsertPosition(int v, int pos ){
	struct List *newNode =(struct List*) malloc(sizeof(struct List));
	newNode->value = v;
	if( numElem >= pos ){
		struct List *temp;
		struct List *newNode = (struct List *)malloc(sizeof(struct List));
		newNode->value = v;
		if(pos==1){
		newNode->node = head;
		head=newNode;
		}
		else{
			struct List *temp2;
			temp=head;
			for(int i=0; i<numElem-1;i++){
			temp=temp->node;
			}
			temp2= temp->node ; 	
			temp->node = newNode;
			newNode->node = temp2; 

		}
		numElem++;
	}
	else {
		printf("\n Linked List Position N/A  :0 ");
	}
}

int deletePos (int pos){
	if (numElem >= pos){
		if(numElem == 1 ){
			struct List* temp;
			temp = head ; 
			free(temp);
			head= NULL;
		}
		else{ 
			struct List* temp ; 
			struct List* temp2; 
			temp=head;
			for (int i= 0 ; i < pos - 2 ; i++){
				temp = temp->node;
			}
			temp2=temp->node;
			temp->node = temp2->node;
			free(temp2);
			
		}
		numElem--; 
	}
	else{
		printf("Position not available"); 
	}
}

int deleteLinkedList(){
	if(numElem==0){
		printf("\n List is Empty :X ");
	}
	else { 
		struct List* temp ;
		struct List* del;
		temp=head;
		while(temp!=NULL){
			del = temp;
			temp=temp->node;
			numElem--;
			free(del);
		}
	}
}
void main(){

	InsertEnd(34);
	PrintLinkedList();
	InsertEnd(2);
	PrintLinkedList();
	InsertEnd(1);
	PrintLinkedList();
	InsertPosition(4,1);
	PrintLinkedList();
	deletePos(2);
	PrintLinkedList();
	InsertEnd(26);
	PrintLinkedList();
	InsertPosition(54,5);
	PrintLinkedList();
	deleteLinkedList();
	deleteLinkedList();

}
