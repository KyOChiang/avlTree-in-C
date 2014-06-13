#include "unity.h"
#include "AVL.h"
#include "Rotation.h"

void setUp(){}
void tearDown(){}

void test_avlAdd_should_add_one_node_to_empty_root(){
  Node *root;
  Node Node1 = {.data=1, .balance=0, .leftChild=NULL, .rightChild = NULL};
  root = avlAdd(NULL,&Node1);
  
  TEST_ASSERT_EQUAL_PTR(&Node1,root);
}

void test_avlAdd_should_add_one_node_to_the_right_child_of_root(){
  Node Node1 = {.data=1, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node50 = {.data=50, .balance=0, .leftChild=NULL, .rightChild = NULL};
  
  Node *root;
  
  root = avlAdd(&Node1,&Node50);
  
  TEST_ASSERT_EQUAL_PTR(&Node1,root);
  TEST_ASSERT_EQUAL_PTR(&Node50,Node1.rightChild);
  
  TEST_ASSERT_NULL(Node1.leftChild);
  
  TEST_ASSERT_EQUAL(1,Node1.balance);
}



