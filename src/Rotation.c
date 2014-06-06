#include <stdio.h>
#include "AVL.h"
#include "Rotation.h"

Node* leftRotate(Node *parent){

  Node *root = parent->rightChild;
  if(parent->rightChild->leftChild != NULL){
    parent->rightChild = parent->rightChild->leftChild;
  }
  else{
    parent->rightChild = NULL;
  }
  root->leftChild = parent;
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

int getHeight(Node *parent){
  int l = 0, r = 0, h;
  if((parent->leftChild == NULL)&&(parent->rightChild == NULL)){
    return 1;
  }
  else if(parent->leftChild == NULL){
    r = getHeight(parent->rightChild);
  }
  else if(parent->rightChild == NULL){
    l = getHeight(parent->leftChild);
  }
  else{
    l = getHeight(parent->leftChild);
    r = getHeight(parent->rightChild);
  }
  
  h = (l>=r) ? l+1:r+1;
  return h;
}




















