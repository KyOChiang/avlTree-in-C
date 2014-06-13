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
  return root;
}

Node* rightRotate(Node *parent){

  Node *root = parent->leftChild;
  if(parent->leftChild->rightChild != NULL){
    parent->leftChild = parent->leftChild->rightChild;
  }
  else{
    parent->leftChild = NULL;
  }  
  root->rightChild = parent;
  return root;
}

Node* doubleRightRotate(Node *parent){
  Node *root;
  Node *leftChild = parent->leftChild;
  leftChild = leftRotate(leftChild);
  parent->leftChild = leftChild;
  root = rightRotate(parent);
  
  return root;
}

Node* doubleLeftRotate(Node *parent){
  Node *root;
  Node *rightChild = parent->rightChild;
  rightChild = rightRotate(rightChild);
  parent->rightChild = rightChild;
  root = leftRotate(parent);
  
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




















