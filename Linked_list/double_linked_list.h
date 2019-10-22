#include <stdio.h>
#include <stdlib.h>
#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST
typedef int tp_item; // type of list item 

typedef struct tp_node{
	tp_item info;
	struct tp_node* prev; // previous
	struct tp_node* next; //next
}element;

typedef struct doubly_linked_list{
	struct tp_node* start;
	struct tp_node* end;	
}tp_list;

element * allocate (); // allocate memory for our elements of the list
tp_list * init(); // initialize the list
int is_empty (tp_list *l); // check if the list is empty
int insert_in_the_start (tp_list **l, tp_item e); // insert given element in the start of the list
int insert_in_the_end (tp_list **l, tp_item e); // insert given element in the end of the list
int print_reverse_order (tp_list *l); // print list in reverse order
int print (tp_list *l); // print all list
tp_list * allocate_list(); // allocate memory for list
element * search(tp_list *l, tp_item e); // search given element on list and return the element memory location
int remove_element(tp_list *l, tp_item e); // remove given element of the list
int destroy (tp_list **l); // destroy given list

tp_list * init(){
	tp_list *aux; // auxiliar pointer
	aux=allocate_list();
	aux->end=NULL;
	aux->start=NULL;
	return aux;
}

int is_empty (tp_list *l) {
	if ( l->end == NULL ) return 1;
	return 0;
}

element * allocate (){
	element * pt;
	pt = (element *) malloc(sizeof(element));
	return pt;
}

int insert_in_the_end (tp_list **l, tp_item e){
	tp_list *current;
	current=*l;
	element *new_element;
	new_element = allocate (); // return 0 if couldn't allocate memory
	if (!new_element){
		return 0;
	}
	
	if (is_empty (current)) {
		new_element->info= e;
		new_element->prev =current->start;
		new_element->next = current->end;
		current->start=new_element;
		current->end=new_element;
		return 1;
	}
	else {
		new_element->info = e;
		new_element->next=NULL;
		new_element->prev = current->end;
		current->end->next = new_element;
		current->end = new_element;
		return 1;
	}
}

int insert_in_the_start (tp_list **l, tp_item e){
	tp_list *current; 
	element *new_element;
	current=*l;
	new_element = allocate ();
	if (!new_element){// return 0 if couldn't allocate memory
		return 0;
	}
	if (is_empty (current)) {
		new_element->info= e;
		new_element->prev =current->start;
		new_element->next = current->end;
		current->start=new_element;
		current->end=new_element;
		return 1;
	}
	else {
		current->start->prev = new_element;
		new_element->next = current->start;
		current->start = new_element;
		new_element->info = e;
		return 1;
	}
}

tp_list * allocate_list (){
	tp_list * pt;
	pt = (tp_list *) malloc(sizeof(tp_list));
	return pt;
}

int print (tp_list *l) {
	element *aux;
	aux=l->start;
	if(aux==NULL) return 0; // return 0 if the list is empty
	while (aux!=NULL){
		printf ("%d\n", aux->info);
		aux=aux->next;
	}
	return 1;
}
int print_reverse_order (tp_list *l) {
	element *aux;
	aux=l->end;
	if(aux==NULL) return 0; // return 0 if the list is empty
	while (aux!=NULL){
		printf ("%d\n", aux->info);
		aux= aux->prev;
	}
	return 1;
}
element * search(tp_list *l, tp_item e){
	element *current;
	current=l->start;
	while (current!=NULL&&current->info!=e){
		current= current->next;
	}
	if(current!=NULL){
		printf("\n\nthe memory address is: %p\n\n", current);
		return current;
	}
	printf("\n\nthe given element %d isn't in the list\n\n",e);
	return NULL;
}

int destroy (tp_list **l){
	tp_list *aux;
	aux=*l;
	if(aux->start == NULL) return 0;
	while (aux->start != NULL){
		aux->start = aux->start->next;
		free(aux->start);
	}
	aux->start=NULL;
	aux->end=NULL;
	return 1;
}

int remove_element(tp_list *l, tp_item e){
	element *current;
	current=l->start;
	if(current==NULL) return 0;
	while (current!=NULL&&current->info!=e){
		current=current->next;
	}
	if (current == NULL) return 0; // return 0 if the element is not on the list
	if(current->prev==NULL){ // in case its the first
		current=current->next;
		free(current->prev);
		current->prev=NULL;
		l->start=current;
		
		return 1;
	}
	else if(current->next==NULL){
		current=current->prev;
		free(current->next);
		current->next=NULL;
		l->end=current;
		return 1;
	}
	else if(l->start==l->end){
		l->end=l->start=NULL;
		free(current);
		return 1;
	}
	
	else {
		current->prev->next = current->next;
		current->next->prev = current->prev;
		free(current);
		current=NULL;
		return 1; 
	}
	
}
#endif
