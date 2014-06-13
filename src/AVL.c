#include <stdio.h>
#include "AVL.h"
#include "Rotation.h"

Node *avlAdd(Node *root, Node *newNode){
  Node *tempRoot, *newRoot;
  
  if(root == NULL){
    newRoot = newNode;
    return newRoot;
  }
  else{
    if((root->data) > (newNode->data)){
      root->leftChild = newNode;
    }
    else if((root->data) < (newNode->data)){
      root->rightChild = newNode;
      root->balance = root->balance + 1;
    }
  }
  return root;
}
