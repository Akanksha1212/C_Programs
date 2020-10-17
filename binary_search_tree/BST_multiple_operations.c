#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *root=NULL;

struct node *createNode(int key)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data=key;
    p->left=NULL;
    p->right=NULL;
    return p;
}

struct node *insertion(struct node *temp,int key)
{
    if(temp==NULL)
        return createNode(key);
    if(temp->data < key)
        temp->right = insertion(temp->right,key);
    else if(temp->data > key)
        temp->left = insertion(temp->left,key);
    return temp;
}

struct node *search(struct node *temp,int key)
{
    if(temp==NULL || temp->data==key)
        return temp;
    if(temp->data < key)
        return search(root->right,key);
    return search(root->left,key);
}

void preorder(struct node *temp)
{
    if(temp!=NULL)
    {
        printf("%d\t",temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void inorder(struct node *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        printf("%d\t",temp->data);
        inorder(temp->right);
    }
}

void postorder(struct node *temp)
{
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d\t",temp->data);
    }
}

int maxDepth(struct node* temp)
{
   if (temp==NULL)
       return 0;
   else
   {
       int lDepth = maxDepth(temp->left);
       int rDepth = maxDepth(temp->right);

       if (lDepth > rDepth)
           return(lDepth+1);
       else return(rDepth+1);
   }
}

int numElements(struct node *temp)
{
  if (temp==NULL)
    return 0;
  else
    return(numElements(temp->left) + 1 + numElements(temp->right));
}

int findMax(struct node* temp)
{
    while(temp->right != NULL)
        temp=temp->right;
    return temp->data;
}

int minimum(struct node* temp)
{
    while(temp->left != NULL)
        temp=temp->left;
    return temp->data;
}

struct node* minValueNode(struct node* node)
{
    struct node* current = node;
    while (current->left != NULL)
        current = current->left;

    return current;
}

struct node* rem(struct node *temp, int key)
{
    if(temp == NULL)
        return temp;
    if(key>temp->data)
        temp->right= rem(temp->right,key);
    else if(key<temp->data)
        temp->left= rem(temp->left,key);
    else{
        if (temp->left == NULL)
        {
            struct node *t = temp->right;
            free(temp);
            return t;
        }
        else if (temp->right == NULL)
        {
            struct node *t = temp->left;
            free(temp);
            return t;
        }
        struct node* t = minValueNode(temp->right);
        temp->data = t->data;
        temp->right = rem(temp->right, t->data);

    }
    return temp;
}

int null(struct node *temp)
{
    int left=0,right=0;
    if(temp==NULL)
        return 0;
    else if(temp->right == NULL && temp->left == NULL)
    {
        return 1;
    }
    else{
        left=left + null(temp->left);
        right=right + null(temp->right);
        return(left+right);
    }
}

void main()
{
    int choice,key,first_time=0;
    int nodes;
    struct node *temp=NULL;
    printf("=================BINARY SEARCH TREE=====================\n");
    while(1)
    {
        printf("1.INSERT IN BST.\n");
        printf("2.SEARCH KEY\n");
        printf("3.PREORDER TRAVERSAL\n");
        printf("4.INORDER TRAVERSAL\n");
        printf("5.POSTORDER TRAVERSAL\n");
        printf("6.HEIGHT AND DEPTH\n");
        printf("7.NUMBER OF ELEMENTS IN THE TREE\n");
        printf("8.MAXIMUM ELEMENTS\n");
        printf("9.MINIMUM ELEMENTS\n");
        printf("10.DELETE NODE\n");
        printf("11.EXIT\n");
        printf("========================================\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the data of the node:\t");
                    scanf("%d",&key);
                    root=insertion(root,key);
                    break;

            case 2: printf("Enter the data to be searched:\t");
                    scanf("%d",&key);
                    temp=search(root,key);
                    if(temp==NULL)
                        printf("The data wasn't found in the tree\n");
                    else
                        printf("The root is present in the tree\n");
                    break;

            case 3: printf("The preorder traversal is:\n");
                    preorder(root);
                    printf("\n");
                    break;

            case 4: printf("The inorder traversal is:\n");
                    inorder(root);
                    printf("\n");
                    break;

            case 5: printf("The postorder traversal is:\n");
                    postorder(root);
                    printf("\n");
                    break;

            case 6: printf("The height of the tree is %d\n",maxDepth(root));
                    break;

            case 7: printf("The number of elements in the tree are %d\n",numElements(root));
                    break;

            case 8: printf("The maximum element is %d\n",findMax(root));
                    break;

            case 9: if(root==NULL)
                        printf("The tree is empty\n");
                    else
                        printf("The minimum element is %d\n",minimum(root));
                    break;

            case 10: printf("Enter the node to be deleted:\t");
                     scanf("%d",&key);
                     printf("\n");
                     rem(root,key);
                     printf("The inorder after deletion is:\n");
                     inorder(root);
                     printf("\n");
                     break;

            case 11: exit(0);

            case 12: nodes=null(root);
                     printf("%d\n",nodes);
                     break;

            default: printf("Wrong choice entered\n");
                     break;
        }
    }
}
