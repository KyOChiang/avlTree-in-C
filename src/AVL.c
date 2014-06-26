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
        root->leftChild = avlAdd(root->leftChild,newNode); 
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
        root->rightChild = avlAdd(root->rightChild,newNode); 
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

Node *avlRemove(Node **ptrPtrNode, Node *nodeToRemove){
  Node *smallThanNode, *bigThanNode;
  
  if(nodeToRemove == NULL|| *ptrPtrNode == NULL)
    return NULL;
  else{
    return nodeToRemove;
  }
}

Node *avlGetReplacer(Node **ptrToRoot){
  Node *rootNode = *ptrToRoot, *replaceNode = *ptrToRoot;
  //rtBal - rootBalance, rCBal - rightChildBalance, lCBal - leftChildBalance
  int rtBal, rCBal, lCBal; 

  if(rootNode->rightChild == NULL){
    *ptrToRoot = rootNode->leftChild;
    return rootNode;
  }
  
  replaceNode = avlGetReplacer(&replaceNode->rightChild);
  if(rootNode->rightChild==NULL){
    rootNode->balance = rootNode->balance - 1;
  }
  else{
    rtBal = rootNode->balance;
    lCBal = rootNode->leftChild->balance;
    rCBal = rootNode->rightChild->balance;
    if(rtBal == 1 && (lCBal == 0||lCBal == -1) && rCBal == 0){
      rootNode->balance = 0;
    }
    if(rtBal == -1 && (lCBal == 1||lCBal == 0) && (rCBal == 0||rCBal == -1)){
      rootNode->balance = rootNode->balance - 1;
    }
  }
  
  if(rootNode->balance == 2){
    if(rootNode->rightChild->balance == 1||rootNode->leftChild->balance == -1){
      rootNode = leftRotate(rootNode);
    }
    else if(rootNode->rightChild->balance == -1){
      rootNode = doubleLeftRotate(rootNode);
    }
  }
  if(rootNode->balance == -2){
    if(rootNode->leftChild->balance == -1||rootNode->leftChild->balance == 0){
      rootNode = rightRotate(rootNode);
    }
    if(rootNode->leftChild->balance == 1){
      rootNode = doubleRightRotate(rootNode);
    }
  }
  return replaceNode;
}

// printf("Inside: %p\n", *ptrToRoot);
// printf("Inside: %p\n", rootNode);
//printf("%p\n",rootNode);