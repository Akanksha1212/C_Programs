#include<stdio.h>
#include<stdlib.h>
struct bst
{
    int data;
    struct bst * left;
    struct bst * right;
};
struct bst * insert(int data,struct bst * head)
{
    if(head==NULL)
    {
        struct bst * temp = (struct bst *)malloc(sizeof(struct bst));
        temp->left=NULL;
        temp->right=NULL;
        temp->data=data;
        head=temp;
    }
    else if(data < head->data)
    {
        head->left = insert(data,head->left);
    }
    else
    {
        head->right = insert(data,head->right);
    }
    return head;   
}
void print(struct bst * head)
{
  if(head==NULL)
  {
    return;
  }
  else
  {
    print(head->left);
    printf("%d ",head->data);
    print(head->right);
  }

}
int main()
{
    int i=1;
    struct bst * head=NULL;
    while(i!=0)
    {
        printf("Enter 1)insert 2)print 0)exit ");
        scanf("%d",&i);
        if(i==1)
        {
            int data;
            scanf("%d",&data);
            head=insert(data,head);
        }
        else if(i==0)
        {
            break;
        }
        else if(i==2)
        {
            print(head);
        }
    }
}