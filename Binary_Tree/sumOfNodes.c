#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *left, *right;
};

struct node *newNode(int key)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->value = key;
    newnode->left = NULL;
    newnode->right = NULL;
    return(newnode);
}

int sumofnodes(struct node *root)

{
    int rightsubtree, leftsubtree, sum = 0;
    if(root != NULL)
    {
        leftsubtree = sumofnodes(root->left);
        rightsubtree = sumofnodes(root->right);
        sum = (root->value) + leftsubtree + rightsubtree;
        return sum;
    }
}


int main()
{
    struct node *newnode = newNode(60);
    newnode->left = newNode(45);
    newnode->right = newNode(80);
    newnode->left->left = newNode(35;
    newnode->left->right = newNode(50);
    newnode->right->left = newNode(75);
    newnode->right->right = newNode(100);
    /* Sample Tree 1:

     *                60

     *             /    \

     *            45     80

     *           / \     / \

     *         35  50   75 100

     */

    printf("Sum of nodes in tree 1 = %d", sumofnodes(newnode));
    printf("\n");

    /* Creating second Tree. */

    struct node *root = newNode(15);
    /* Sample Tree 3: Tree having just one root node.

     *              15

     */

    printf("Sum of nodes in tree 3 = %d", sumofnodes(root));
    printf("\n");
    return 0;
}