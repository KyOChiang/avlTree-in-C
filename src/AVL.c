#include <stdio.h>
#include "AVL.h"
#include "Rotation.h"

Node *avlAdd(Node *root, Node *newNode){
  int tempBal = 0;
  if(root == NULL){
    root = newNode;
  }
  else{
    if((newNode->data) < (root->data)){
      if(root->leftChild == NULL){
        root->leftChild = avlAdd(root->leftChild,newNode);
        root->balance = root->balance - 1;
      }
      else{
        tempBal = root->leftChild->balance;
        root->leftChild = root->leftChild = avlAdd(root->leftChild,newNode); 
        if((root->leftChild->balance != 0)&&(root->leftChild->balance-tempBal != 0)){
          root->balance = root->balance - 1;
        }
      }
    }
    else if((newNode->data) > (root->data)){
      if(root->rightChild == NULL){
        root->rightChild = avlAdd(root->rightChild,newNode);
        root->balance = root->balance + 1;
      }
      else{
        tempBal = root->rightChild->balance;
        root->rightChild = root->rightChild = avlAdd(root->rightChild,newNode); 
        if((root->rightChild->balance != 0)&&(root->rightChild->balance-tempBal != 0)){
          root->balance = root->balance + 1;
        }
      }
    }
  }
  
  
  if(root->balance == 2){
    if(root->rightChild->balance == 1){
      root = leftRotate(root);
    }
    else if(root->rightChild->balance == -1){
      root = doubleLeftRotate(root);
    }
  }
  if(root->balance == -2){
    if(root->leftChild->balance == -1){
      root = rightRotate(root);
    }
    if(root->leftChild->balance == 1){
      root = doubleRightRotate(root);
    }
  }
  return root;
}
