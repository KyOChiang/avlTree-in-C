#include <stdio.h>
#include "AVL.h"
#include "Rotation.h"

Node *avlAdd(Node *root, Node *newNode){
  Node *tempRoot, *temp2Root, *newRoot;
  
  if(root == NULL){
    newRoot = newNode;
    return newRoot;
  }
  else{
    if((root->data) > (newNode->data)){
      root->leftChild = newNode;
    }
    else if((root->data) < (newNode->data)){
      // tempRoot = root->rightChild;
      // while(((newNode->data) > (tempRoot->data))&&(tempRoot!=NULL)){
        // temp2Root = tempRoot;
        // tempRoot = tempRoot->rightChild;
        // if(tempRoot==NULL){
          // temp2Root->rightChild = newNode;
        // }
      // }
      
      root->rightChild = newNode;
      root->balance = root->balance + 1;
    }
  }
  return root;
}

// if(new>root)
  // temp = root->right;
// while(new>temp && temp != NULL)
  // abs = temp;
  // temp = temp->right;
  // if(temp == NULL)
    // abs->right = new;
  
// while(new