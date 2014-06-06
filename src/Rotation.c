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
  root->rightChild = parent;
  parent->leftChild = NULL;
  
  root->leftChild->rank = 0;
  root->rightChild->rank = 0;
  root->rank = 0;
  
  return root;
}

Node* doubleRightRotate(Node *parent){
  Node *leftChild = parent->leftChild->rightChild;
  Node *root = parent->leftChild;
  root->rightChild = parent;
  root->leftChild = leftChild;
  
  root->leftChild->rank = 0;
  root->rightChild->rank = 0;
  root->rank = 0;
  
  return root;
}

Node* doubleLeftRotate(Node *parent){
  Node *root = parent->rightChild->leftChild;
  Node *rightChild = parent->rightChild;
  root->leftChild = parent;
  root->rightChild = rightChild;
  root->leftChild->rightChild = NULL;
  root->rightChild->leftChild = NULL;
  
  root->leftChild->rank = 0;
  root->rightChild->rank = 0;
  root->rank = 0;
  
  return root;
}




















