#include<stdio.h>
#include<stdlib.h>
void create();
void display();
struct node
{
int info;
struct node *link;
};
struct node *start=NULL;

int main()
{
create();
display();
return 0;

}

void create()
{
 struct node *new,*ptr;

 char ch='y';
 int item;

 while(ch=='y'||ch=='Y')
  {
    new=(struct node*)malloc(sizeof(struct node));
    if(new==NULL)
    {
    printf("overflow");
    exit(0);
    }
  printf("enter item value");
  scanf("%d",&item);
  new->info=item;
  new->link=NULL;

  if(start==NULL)
     start=new;
  else
  {
    ptr=start;

    while(ptr->link!=NULL)
          ptr=ptr->link;
    ptr->link=new;

   }

  printf("Do u want to add more nodes");
  
  scanf("%c",&ch);
  }
  }

  void display()
  {

  struct node *ptr;
  if(start==NULL)
  {

   printf("list is empty");
  exit(0);
  }
  else{

  ptr=start;
  while(ptr!=NULL)
  {
  printf("\t%d",ptr->info);
  ptr=ptr->link;

  }
  }
  }

