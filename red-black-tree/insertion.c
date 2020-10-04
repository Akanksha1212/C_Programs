#include <stdio.h>
#include <stdlib.h>

enum bool 
{
  FALSE,
  TRUE
};
typedef enum bool Bool;

#define RED TRUE
#define BLACK FALSE

typedef struct node RBNode;

struct node 
{
  int value;
  Bool color;
  RBNode *left, *right, *parent;
};

static void freeAllNodes(RBNode *node);

static void freeNode(RBNode *node);

static RBNode * createNode(int value);

static Bool isRed(RBNode *node);

static RBNode * rotateLeft(RBNode *node);

static RBNode * rotateRight(RBNode *node);

static void flipColors(RBNode *node);

static void printTreeUtil(RBNode *node, int space);

void freeTree(RBNode *root);

void insert(RBNode *root, int value);

void printTree(RBNode *root);

// ---------------------------------------------------------------

void freeTree(RBNode *root) {
  if (root == NULL) {
    return;
  }

  freeAllNodes(root);
}

static void freeAllNodes(RBNode *root) {
  if (root != NULL) {
    freeAllNodes(root->left);
    freeAllNodes(root->right);
    free(root);
  }
}

// ---------------------------------------------------------------

RBNode * createTree(int value) {
  return createNode(value);
}

RBNode * createNode(int value) {
  RBNode *newNode = malloc(sizeof(RBNode));
  newNode->value = value;
  newNode->color = RED;
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->parent = NULL;
}

// ---------------------------------------------------------------

void insert(RBNode *root, int value) {
  root = insertNode(root, value);
}

RBNode * insertNode(RBNode *node, int value) {
  if (node == NULL) return createNode(value);

  int nodeVal = node->value;

  if (nodeVal < value) node->right = insertNode(node->right, value);
  else if (nodeVal > value) node->left = insertNode(node->left, value);
  else return; // No duplicated values

  if (isRed(node->right) && !isRed(node->left)) {
    node = rotateLeft(node);
  }

  if (isRed(node->left) && isRed(node->left->left)) {
    node = rotateRight(node);
  }

  if (isRed(node->right) && isRed(node->left)) {
    flipColors(node);
  }

  return node;
}

static Bool isRed(RBNode *node) {
  if (node == NULL) return FALSE;
  return node->color;
}

RBNode * rotateLeft(RBNode *node) {
  RBNode *aux = node->right;
  node->right = aux->left;
  aux->left = node;
  aux->color = aux->left->color;
  aux->left->color = RED;
  return aux;
}

RBNode * rotateRight(RBNode *node) {
  RBNode *aux = node->left;
  n->left = aux->right;
  x->right = n;
  x->color = x->right->color;
  x->right->color = RED;
  return x;
}

static void flipColors(RBNode *node) {
  node->color = !node->color;
  node->left->color = !node->left->color;
  node->right->color = !node->right->color;
}

// ---------------------------------------------------------------

void printTree(RBNode *root) {
  printTreeUtil(root, 0);
}

static void printTreeUtil(RBNode *node, int space) {
  if (node == NULL) return;

  space += 1;
  printTreeUtil(node->right, space);
  printf("\n");

  for (int i = 1; i < space; i++)
    printf("\t");

  printf("%d\n", node->value);
  printTreeUtil(node->left, space);
}
