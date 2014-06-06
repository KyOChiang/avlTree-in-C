#include <stdio.h>
#include "AVL.h"
#include "Rotation.h"

Node* leftRotate(Node *parent){
  parent->rightChild->leftChild = parent;
  parent->rightChild = NULL;
  
}


