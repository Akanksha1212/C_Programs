// Forward Linked List
#include<stdio.h>
#include<stdlib.h>

struct List
{
	int value ;  
	struct List *node; 
};

struct List *head = NULL;	// Global variable (Accessible anywhere in the code)
int numElem = 0;		// Global variable (Accessible anywhere in the code)

void InsertEnd (int v)	// Insert value "v" at the end of a linked list
{
	struct List *newNode = (struct List*) malloc(sizeof(struct List));
	newNode -> value = v;
	newNode -> node= NULL;
	if (head == NULL)
		head= newNode;
	else
	{
		struct List *temp ;
		temp = head;
		while (temp->node != NULL)
		{
			temp = temp->node;
		}
		temp->node = newNode; 
	}
	numElem++;
}

void PrintLinkedList()	// Print the linked list
{
	printf("\n");
	if (numElem == 0)
		printf("\n Linked List Empty  :( ");
	else
	{
		struct List *temp;
		temp = head ;
		while (temp != NULL)
		{
			printf(" %d ",temp->value);
			temp = temp->node;
		}
	}
}

void InsertPosition (int v, int pos)	// Insert value "v" at position "pos"
{
	if (numElem >= pos)
	{
		struct List *newNode = (struct List *)malloc(sizeof(struct List));
		newNode->value = v;
		if (pos == 1)
		{
			newNode->node = head;
			head = newNode;
		}
		else
		{
			struct List *temp;
			temp = head;
			for (int i = 0; i < pos - 2; i++)
			{
				temp=temp->node;
			}
			newNode->node= temp->node ; 	
			temp->node = newNode; 
		}
		numElem++;
	}
	else
	{
		printf("\n Linked List Position N/A  :0 ");
	}
}

void deletePos (int pos)	// Delete position "pos" in the linked list
{
	if (numElem >= pos)
	{
		if(numElem == 1 || pos == 1)
		{
			struct List* temp;
			temp = head ;
			head = temp->node;
			free(temp);
		}
		else
		{ 
			struct List* temp ; 
			struct List* temp2; 
			temp = head;
			for (int i = 0; i < pos - 2; i++)
			{
				temp = temp->node;
			}
			temp2=temp->node;
			temp->node = temp2->node;
			free(temp2);
		}
		numElem--; 
	}
	else
	{
		printf("Position not available"); 
	}
}

void deleteLinkedList()	// Delete the whole linked list
{
	if (numElem == 0)
	{
		printf("\n List is Empty :X ");
	}
	else 
	{ 
		struct List* temp ;
		struct List* del;
		temp = head;
		while (temp != NULL)
		{
			del = temp;
			temp = temp->node;
			free(del);
			numElem--;
		}
	}
}

void main()
{
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
