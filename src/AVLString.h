#ifndef AVLString_H_
#define AVLString_H_
#include "AVL.h"

typedef struct NodeString NodeString;

struct NodeString{
  int balance; //different in height
  Node *leftChild;
  Node *rightChild;
  char *string;
};

#define avlAddString(root, nodeToAdd) avlAdd((Node *)(root), (Node *)(nodeToAdd), compareString)
int compareString(void *nodeInTree, void *nodeToCompare);

#endif
