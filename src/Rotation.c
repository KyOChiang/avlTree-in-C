#include <stdio.h>
#include "AVL.h"
#include "Rotation.h"

Node* leftRotate(Node *parent){
  Node *root = parent->rightChild;
  parent->rightChild->leftChild = parent;
  parent->rightChild = NULL;
  
  root->leftChild->rank = 0;
  root->rightChild->rank = 0;
  root->rank = 0;
  
  return root;
}

Node* rightRotate(Node *parent){
  Node *root = parent->leftChild;
  root->rightChild = parent->leftChild->leftChild;
  root->leftChild = parent;
  parent ->leftChild = NULL;
  
  root->leftChild->rank = 0;
  root->rightChild->rank = 0;
  root->rank = 0;
  
  return root;
}

