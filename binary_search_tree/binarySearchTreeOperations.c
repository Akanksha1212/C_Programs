#include <stdio.h>
#include <stdlib.h>

//Node structure
struct node
{
	int data;
	struct node* left;
	struct node* right;
};


//Function prototype
void insert(int data);
void delete();
void inorder(struct node* t);
void preorder(struct node* t);
void postorder(struct node* t);

//root node pointing to first node
struct node* root = NULL;
int data;

void main()
{
	int option;
	while(1)
	{
		printf("\nBST Options\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. In-order Traverse\n");
		printf("4. Pre-order Traverse\n");
		printf("5. Post-order Traverse\n");
		printf("6. Exit\n");
		
		
		printf("\nSelect your option\n");
		scanf("%d",&option);
		
		switch(option)
		{
			case 1: printf("\nEnter the data to insert\n");
					scanf("%d",&data);
					insert(data);
					break;
			case 2: delete();
					break;
			case 3: inorder(root);
					break;
			case 4: preorder(root);
					break;
			case 5: postorder(root);
					break;
			case 6: exit(2);
			default: printf("\nInvalid option\n");
		}
	}
}

void insert(int data)
{
	struct node* t, *p;
	t = (struct node*)malloc(sizeof(struct node));
	t->data = data;
	t->left = NULL;
	t->right = NULL;
	if(root == NULL)
	{
		root = t;
	}
	else
	{
		struct node* curr = root;
		while(curr)
		{
			p = curr;
			if(t->data > curr->data)
			{
				curr = curr->right;
			}
			else
			{
				curr = curr->left;
			}
		}
		if(t->data > p->data)
		{
			p->right = t;
		}
		else
		{
			p->left = t;
		}
	}
}

void delete()
{
	
}

void inorder(struct node* t)
{
	if(t->left)
	{
		inorder(t->left);
	}
	printf("%d | ",t->data);
	if(t->right)
	{
		inorder(t->right);
	}
}

void preorder(struct node* t)
{
	printf("%d | ", t->data);
	if(t->left)
	{
		preorder(t->left);
	}
	if(t->right)
	{
		preorder(t->right);
	}
}

void postorder(struct node* t)
{
	if(t->left)
	{
		postorder(t->left);
	}
	if(t->right)
	{
		postorder(t->right);
	}
	printf("%d | ", t->data);
}
