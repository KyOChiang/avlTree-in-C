#ifndef _AVL_H_
#define _AVL_H_

typedef struct Node Node;

struct Node{
  int balance; //different in height
  Node *leftChild;
  Node *rightChild;
};

typedef enum { NO_ERROR,
			   ERR_INVALID_EQUAL_DATA
} ExceptionError;

Node *avlAdd(Node *root, Node *elem, int (*compare)(void *,void *));
Node *avlRemove(Node **ptrPtrNode, Node *nodeToRemove, int (*compare)(void *,void *));
Node *avlGetReplacer(Node **ptrToRoot);

/* **variable ptr-ptr that point to certain pointer which point to some variable/element
// Use when want to change a pointer direction from one to another(If return statement not 
// using to return the pointer which address reference has changed from last. 
// When come out from function, pointer inside function itself not related to pointer that pass into that function,
// so there are no any changes to pointer that pass into unless using return statement.
// E.g funct change(Node* ptrNode, Node* newNode){} / invoke funct change(root,xxx), root itself not the ptrNode, but share same content
 (pass-by-value).*/

#endif