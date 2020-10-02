#include <stdio.h>

#include <stdlib.h>

struct node{

	int data; // data field	struct node *next;

};

void display(struct node* head){

	struct node* current=head; // current node set to head

	printf("traversing the list...\n");

	while(current!=NULL){ //traverse until current node isn't NULL

		printf("%d ",current->data);

		current=current->next; // go to next node

	}

}

void reverse_display(struct node* head){

	if(head){

		//recursive call to display in reverse order

		reverse_display(head->next);

		printf("%d ",head->data);

	}

}

struct node* creatnode(int d){

	struct node* temp=malloc(sizeof(struct node));

	temp->data=d;

	temp->next=NULL;

	return temp;

}

int main(){

	printf("creating the linked list by inserting new nodes at the end\n");

	printf("enter 0 to stop building the list, else enter any integer\n");

	int k,count=1,x;

	struct node* curr,*temp;

	scanf("%d",&k);

	struct node* head=creatnode(k); //buliding list, first node

	scanf("%d",&k);

	temp=head;

	///////////////////inserting at the end//////////////////////

	while(k){

		curr=creatnode(k);

		temp->next=curr;//appending each node

		temp=temp->next;

		scanf("%d",&k);

	}

	

	display(head); // displaying the list

	printf("\ndisplaying in reverse order...\n");

	reverse_display(head);//display in reverse order

	return 0;

}

OUTPUT :
creating the linked list by inserting new nodes at the end

enter 0 to stop building the list, else enter any integer

4 6 8 9 1 0

traversing the list...

4 6 8 9 1 

displaying in reverse order...

1 9 8 6 4 

Process finished.
