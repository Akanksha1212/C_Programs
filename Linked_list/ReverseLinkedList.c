#include<stdio.h>
#include<stdlib.h>

/*
	Time Complexity : O(N)
	Space Complexity : O(1)
*/

struct Node {
	int val;
	struct Node* next;
};

struct Node *head = NULL;

// Iterative method
void reverseLinkedList() {

	struct Node *cur = head, *prev = NULL, *next = NULL;

	while (cur != NULL) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	head = prev;

}

// Recursive method 
void ReverseLinkedList(struct Node *prev) {

	if (prev->next == NULL) {
		head = prev;
		return;
	}

	ReverseLinkedList(prev->next);

	struct Node *p = prev->next;
	p->next = prev;
	prev->next = NULL;

}

void printLinkedList() {

	if (head == NULL) {
		printf("NULL\n");
		return;
	}

	struct Node *ptr = head;

	while (ptr != NULL) {
		printf("%d->", ptr->val);
		ptr = ptr->next;
	}
	printf("NULL\n");

}

void createLinkedList(int data) {

	struct Node *temp = (struct Node*) malloc (sizeof(struct Node));
	
	// create new node of linkedlist
	struct Node *ptr = head;
	temp->val = data;
	temp->next = NULL;

	if (head == NULL) {
		head = temp;
		return;
	}

	while (ptr->next != NULL) {
		ptr = ptr->next;
	}
	ptr->next = temp;

}


int main(int argc, char const *argv[]) {

	createLinkedList(1);
	createLinkedList(2);
	createLinkedList(3);
	createLinkedList(4);
	createLinkedList(5);

	printLinkedList();

	// iterative
	reverseLinkedList();
	printLinkedList();

	// recursive 
	ReverseLinkedList(head);
	printLinkedList();

	return 0;
}








