#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
typedef struct node NODE;


void InsertOrdered(NODE *, int );
int Delete(NODE *, int );
void Traverse(NODE *);

int main()
{
    int i;

    NODE head;
    head.next = NULL;
    head.data = 0;

  

    for (i = 0; i < 5; i++)
    {
        InsertOrdered(&head, i);
        Traverse(&head);
    }

    for (i = 0; i < 5; i++)
    {
        Delete(&head, i);
        Traverse(&head);
    }

    return 0;
}

void InsertOrdered(NODE *head, int data)
{
    NODE * newnode;
    newnode = (NODE *)malloc(sizeof(NODE));
    newnode->data = data;

    NODE * previous = head;
    NODE * current = head->next;
    while (current != NULL && data < current->data)
    {
        previous = current;
        current = current->next;
    }
    previous->next = newnode;
 newnode->next = current;
}


int Delete(NODE *head, int data)
{
    NODE * previous = head;
    NODE * current = head->next;
    while (current != NULL && current->data != data)
    {
        previous = current;
        current = current->next;
    }
    if (current != head && current != NULL) 
    {
        previous->next = current->next;
        free(current);
        return 0;
    }
    else
        return 1;
}

void Traverse(NODE * head)
{
    NODE * current = head->next;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

