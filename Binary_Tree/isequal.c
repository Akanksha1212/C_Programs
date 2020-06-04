/*
C-program to check if the two given binary tree are equal or not
*/

#include<stdio.h>
#include<stdlib.h>
struct node{
 int info;
 struct node *left,*right;
};
typedef struct node NODE;

NODE *newnode(int data){
 NODE *p;
 p= (NODE *)malloc(sizeof(NODE));
 p->info= data;
 p->left=NULL;
  p->right=NULL;
}

int isequal(NODE *root1,NODE *root2){
  if(root1==NULL && root2==NULL)
     return 1;
  if(root1->info != root2->info)
       return 0;
 return (isequal(root1->left,root2->left) && isequal(root1->right,root2->right));
}

int main(){
  NODE *root1,*root2;
  root1= newnode(1);
  root1->left= newnode(2);
  root1->right= newnode(3);
  root1->left->left= newnode(4);
  root1->left->right= newnode(5);

  root2= newnode(1);
  root2->left= newnode(4);
  root2->right= newnode(3);
  root2->left->left= newnode(4);
  root2->left->right= newnode(5);

  if(isequal(root1,root2))
      printf("tree are equal\n");
  else
      printf("not equal\n");
  return 0;
}
