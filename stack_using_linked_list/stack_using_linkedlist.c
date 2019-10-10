#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* link;
};

 
 
struct node*  push(int x,struct node *top)
 {
  struct node* temp = NULL;
 temp =  (struct node*)malloc(sizeof(struct node));
 temp->data =x;
 temp->link = top;
 top= temp;
 return top;
    
    
 }
 struct node* pop(struct node *top)
 {

  if(top==NULL)
  {
      printf("stack is empty\n");
      return NULL;
  }
  else
  {
      struct node* temp =  top;
      top = temp->link;
      free(temp);
  }
  return top;
 }
 void display(struct node *top)
 {
     struct node* temp = top;
     printf("stack direction is --------->\n");
     while(temp!=NULL)
     {

         printf("%d ",temp->data);
         temp=temp->link;
     }
     printf("\n");
 }

int main()
{
struct node* top = NULL;
top = push(2,top);
top = push(4,top);
top = push(6,top);
top = push(87,top);
top = push(23,top);
display(top);

top = pop(top);
top = pop(top);
top = pop(top);
display(top);
return 0;


}