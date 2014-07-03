#include <stdio.h>
#include "CException.h"
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
    if(root->data == newNode->data)
      Throw(ERR_INVALID_EQUAL_DATA);
  }
  
  
  if(root->balance == 2){
    if(root->rightChild->balance == 1||root->rightChild->balance == 0){
      root = leftRotate(root);
    }
    else if(root->rightChild->balance == -1){
      root = doubleLeftRotate(root);
    }
  }
  if(root->balance == -2){
    if(root->leftChild->balance == -1||root->leftChild->balance == 0){
      root = rightRotate(root);
    }
    if(root->leftChild->balance == 1){
      root = doubleRightRotate(root);
    }
  }
  return root;
}

/*
 * avlRemove - To remove the node selected
 * Input rootNode -> Temp data store for parent node
 *       lNode    -> Temp data store for leftChild node
 *       rNode    -> Temp data store for rightChild node
 *       lBalance -> Temp data store for leftChild/ rightChild node balance
 *
 * How to         -> Get the node to be removed and compare to parent node
 *                -> Big > parent node, check on the rightChild else check on the leftChild
 *                -> leftChild/ rightChild = NULL? No, keep comparing data else compare the equality between both data
 *                -> If the data equal? Yes, remove it and go to next else return a NULL.
 *                -> Check the leftChild, it NULL?
 *                    -> Yes, replace the parent node remove just now with the rightChild and rebalance factor if necessary
 *                    -> Otherwise, avlGetReplacer start and return a node to replace the parent /
 *                       Link the new parent node to leftChild and rightChild from parent node removed just now. /
 *                       Rebalance again if necessary, depend on balance on leftChild /
 *                       From 1 or -1 to 0, it show that height reduce by 1 on leftChild, so balance of parent will + 1
 *                       From 0 to 1 or -1, the height does not change, so balance remain.
 *
 * Return NULL, if node not exist
 * Otherwise return the node pointer (replacedNode) which remove from tree.
 */
Node *avlRemove(Node **p2pNode, Node *remove){
  Node *rootNode = *p2pNode, *replacedNode = *p2pNode, *lChild = NULL, *rChild = NULL;
  int lBalance;
  if(remove == NULL|| *p2pNode == NULL)
    return NULL;
  
  if(remove->data > rootNode->data){
    if(rootNode->rightChild != NULL)
      lBalance = rootNode->rightChild->balance;
    replacedNode = avlRemove(&rootNode->rightChild,remove);
    if(rootNode->leftChild == NULL && rootNode->rightChild != NULL)
      rootNode->balance = rootNode->balance + 1;
    if(rootNode->leftChild != NULL && rootNode->rightChild == NULL)
      rootNode->balance = rootNode->balance - 1;
    if(rootNode->leftChild == NULL && rootNode->rightChild == NULL)
      rootNode->balance = 0;
    if(rootNode->rightChild!=NULL){
      if(rootNode->rightChild->balance == 0 && (lBalance == 1||lBalance == -1))
        rootNode->balance = rootNode->balance - 1;
    }
  }
  
  else if(remove->data < rootNode->data){
    if(rootNode->leftChild != NULL)
      lBalance = rootNode->leftChild->balance;
    replacedNode = avlRemove(&rootNode->leftChild,remove);
    if(rootNode->leftChild == NULL && rootNode->rightChild != NULL)
      rootNode->balance = rootNode->balance + 1;
    if(rootNode->leftChild == NULL && rootNode->rightChild == NULL)
      rootNode->balance = 0;
    if(rootNode->leftChild !=NULL && rootNode->rightChild == NULL)
      rootNode->balance = rootNode->balance - 1;
    if(rootNode->leftChild!=NULL){
      if(rootNode->leftChild->balance == 0 && (lBalance == 1||lBalance == -1))
        rootNode->balance = rootNode->balance + 1;
    }
  }

 if(rootNode->data == remove->data){
    lChild = rootNode->leftChild;
    rChild = rootNode->rightChild;
    if(rootNode->leftChild != NULL)
      lBalance = rootNode->leftChild->balance;
    if(rootNode->leftChild == NULL)
      (*p2pNode) = rootNode->rightChild;
    else{
      (*p2pNode) = avlGetReplacer(&lChild);
      (*p2pNode)->leftChild = lChild;
      (*p2pNode)->rightChild = rChild;
      if((*p2pNode)->leftChild == NULL && (*p2pNode)->rightChild == NULL)
        (*p2pNode)->balance = 0;
      if((*p2pNode)->leftChild == NULL && (*p2pNode)->rightChild != NULL)
        (*p2pNode)->balance = (*p2pNode)->balance + 1;
      if((*p2pNode)->leftChild != NULL){
        if((*p2pNode)->leftChild->balance == -1 && lBalance == 0)
          (*p2pNode)->balance = rootNode->balance;
        if((*p2pNode)->leftChild->balance == 0 && (lBalance == 1||lBalance == -1))
          (*p2pNode)->balance = rootNode->balance + 1;
      }
    }
    return replacedNode;
  }
  
  if((*p2pNode)->balance == 2){
    if((*p2pNode)->rightChild->balance == 1||(*p2pNode)->rightChild->balance == 0)
      (*p2pNode) = leftRotate((*p2pNode));
    if((*p2pNode)->rightChild->balance == -1)
      (*p2pNode) = doubleLeftRotate((*p2pNode));
  }
  if((*p2pNode)->balance == -2){
    if((*p2pNode)->leftChild->balance == -1||(*p2pNode)->leftChild->balance == 0)
      (*p2pNode) = rightRotate((*p2pNode));
    if((*p2pNode)->leftChild->balance == 1)
      (*p2pNode) = doubleRightRotate((*p2pNode));
  }

  return replacedNode;
}

Node *avlGetReplacer(Node **ptrToRoot){
  Node *rootNode = *ptrToRoot, *replaceNode = *ptrToRoot;
  //rtBal - rootBalance, rCBal - rightChildBalance, lCBal - leftChildBalance
  int rtBal, rCBal, lCBal; 
  
  if(rootNode == NULL){
    return rootNode;
  }
  
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
    if(rtBal == 1 && (lCBal == 0||lCBal == -1||lCBal==1) && rCBal == 0){
      rootNode->balance = 0;
    }
    if(rtBal == -1 && (lCBal == 1||lCBal == 0) && (rCBal == 0||rCBal == -1)){
      rootNode->balance = rootNode->balance - 1;
    }
  }
  
  if(rootNode->balance == 2){
    if(rootNode->rightChild->balance == 1||rootNode->rightChild->balance == 0){
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
