#ifndef _AVL_H_
#define _AVL_H_

typedef struct Node Node;

typedef struct Node{
int rank; //different in height
Node *leftChild;
Node *rightChild;
int data;
}Node;

Node avlAdd(Node *root, Node *elem);
Node avlRemove(Node *root, Node *elem);

#endif