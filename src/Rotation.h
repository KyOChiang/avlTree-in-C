#ifndef _ROTATION_H_
#define _ROTATION_H_

#include "AVL.h"

int getHeight(Node *elem);
Node* rightRotate(Node *elem);
Node* leftRotate(Node *elem);
Node* doubleRightRotate(Node *elem);
Node* doubleLeftRotate(Node *elem);

#endif