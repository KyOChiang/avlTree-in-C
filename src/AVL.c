#include <stdio.h>
#include "AVL.h"
#include "Rotation.h"

Node *avlAdd(Node *root, Node *newNode){
  
  if(root == NULL){
    root = newNode;
  }
  else{
    if((root->data) > (newNode->data)){
      root->leftChild = avlAdd(root->leftChild,newNode);
      if(root->rightChild == NULL){
        root->balance = root->balance - 1;
      }
      else if((root->leftChild != NULL)&&(root->rightChild != NULL)){
        if((root->leftChild->leftChild == NULL)&&(root->leftChild->rightChild == NULL)&&(root->rightChild->rightChild == NULL)&&(root->rightChild->leftChild == NULL)){
          root->balance = 0;
        }
        else if((root->rightChild->leftChild == NULL)&&(root->rightChild->rightChild == NULL)){
          if(root->leftChild->balance == 0){
            root->balance = root->leftChild->balance - 1;
          }
          else if(root->leftChild->balance == 1){
            if(root->leftChild->leftChild->balance == 0){
              root->balance = -1;
            }
            else{
              root->balance = -2;
            }
          }
          else if(root->leftChild->balance == -1){
            if(root->leftChild->rightChild->balance == 0){
                root->balance = -1;
            }
            else{
              root->balance = -2;
            }
          }
        }
      }
    }
    else if((root->data) < (newNode->data)){
      root->rightChild = avlAdd(root->rightChild,newNode);
      /* Because add to right side, before check the node at left side.
       * Make sure it not empty so can access to it child.
       * If right side got child but not left, balance + 1.
       * If has left and right child, make balance = 0.
       * If both left and right child have it child, balance still 0.
       * Unless only right child has child, balance + 1.
       */
      if(root->leftChild == NULL){
        root->balance = root->balance + 1;
      }
      else if((root->leftChild != NULL)&&(root->rightChild != NULL)){
        if((root->leftChild->leftChild == NULL)&&(root->leftChild->rightChild == NULL)&&(root->rightChild->rightChild == NULL)&&(root->rightChild->leftChild == NULL)){
          root->balance = 0;
        }
        else if((root->leftChild->leftChild == NULL)&&(root->leftChild->rightChild == NULL)){
          if(root->rightChild->balance == 0){
            root->balance = root->rightChild->balance + 1;
          }
          else if(root->rightChild->balance == 1){
            if(root->rightChild->rightChild->balance == 0){
              root->balance = 1;
            }
            else{
              root->balance = 2;
            }
          }
          else if(root->rightChild->balance == -1){
            if(root->rightChild->leftChild->balance == 0){
              root->balance = 1;
            }
            else{
              root->balance = 2;
            }
          }
        }
      }
    }
  }
  if(root->balance == 2){
    if(root->rightChild->balance == 1){
      root = leftRotate(root);
    }
  }
  if(root->balance == -2){
    if(root->rightChild->balance == -1){
      root = rightRotate(root);
    }
  }
  return root;
}
