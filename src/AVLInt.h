#ifndef AVLInt_H_
#define AVLInt_H_

#include "AVL.h"

#define avlAddInt(root, nodeToAdd) avlAdd((Node *)(root), (Node *)(nodeToAdd), compareInt)
#define avlRemoveInt(p2pNode, nodeToRemove) avlRemove((Node **)(p2pNode), (Node *)(nodeToRemove), compareInt)

typedef struct NodeInt NodeInt;

struct NodeInt{
  int balance; //different in height
  NodeInt *leftChild;
  NodeInt *rightChild;
  int data;
};

int compareInt(void *nodeInTree, void *nodeToCompare);

#endif
