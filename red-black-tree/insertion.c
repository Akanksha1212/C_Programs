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

static RBNode * moveRedLeft(RBNode *node);

static RBNode * moveRedRight(RBNode *node);

static Bool isRed(RBNode *node);

static RBNode * rotateLeft(RBNode *node);

static RBNode * rotateRight(RBNode *node);

static void flipColors(RBNode *node);

static void printTreeUtil(RBNode *node, int space);

void freeTree(RBNode *root);

void insert(RBNode *root, int value);

void printTree(RBNode *root);