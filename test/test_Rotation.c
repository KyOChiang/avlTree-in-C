#include "unity.h"
#include "AVL.h"
#include "Rotation.h"

void setUp(){}
void tearDown(){}


/*
 *    (1)               (2)
 *      \               / \
 *      (2)     =>    (1) (3)
 *        \
 *        (3)
 */
 
void test_leftRotate_given_3_elements_should_rotate_to_balance_tree(){
  Node Node3 = {.data=3, .rank=0,  .leftChild=NULL, .rightChild = NULL};
  Node Node2 = {.data=2, .rank=1,  .leftChild=NULL, .rightChild = &Node3};
  Node Node1 = {.data=1, .rank=2, .leftChild=NULL, .rightChild = &Node2};
  Node *root;
  
  root = leftRotate(&Node1);
  TEST_ASSERT_EQUAL_PTR(&Node2, root);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node3, root->rightChild);
  
  TEST_ASSERT_EQUAL(0, Node2.rank);
  TEST_ASSERT_EQUAL(0, Node1.rank);
  TEST_ASSERT_EQUAL(0, Node3.rank);
}

/*
 *        (3)           (2)
 *        /             / \
 *      (2)     =>    (1) (3)
 *      /
 *    (1)
 */
 
void test_rightRotate_given_3_elements_should_rotate_to_balance_tree(){
  Node Node1 = {.data=1, .rank=0, .leftChild=NULL, .rightChild = NULL};
  Node Node2 = {.data=2, .rank=-1,  .leftChild=&Node1, .rightChild = NULL};
  Node Node3 = {.data=3, .rank=-2,  .leftChild=&Node2, .rightChild = NULL};
  Node *root;
  
  root = rightRotate(&Node3);
  TEST_ASSERT_EQUAL_PTR(&Node2, root);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node3, root->rightChild);
  
  TEST_ASSERT_EQUAL(0, Node2.rank);
  TEST_ASSERT_EQUAL(0, Node1.rank);
  TEST_ASSERT_EQUAL(0, Node3.rank);
}

/*
 *        (3)           (3)           (2)
 *        /             /             / \
 *      (2)     =>    (2)      =>   (1) (3)
 *        \           /
 *        (1)       (1)
 *                 left-Rotate    right-Rotate
 */
 
void test_doubleRightRotate_given_3_elements_should_rotate_to_balance_tree(){
  Node Node1 = {.data=1, .rank=0, .leftChild=NULL, .rightChild = NULL};
  Node Node2 = {.data=2, .rank=1,  .leftChild=NULL, .rightChild = &Node1};
  Node Node3 = {.data=3, .rank=-2,  .leftChild=&Node2, .rightChild = NULL};
  Node *root;
  
  root = doubleRightRotate(&Node3);
  TEST_ASSERT_EQUAL_PTR(&Node2, root);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node3, root->rightChild);
  
  TEST_ASSERT_EQUAL(0, Node2.rank);
  TEST_ASSERT_EQUAL(0, Node1.rank);
  TEST_ASSERT_EQUAL(0, Node3.rank);
}

/*
 *      (1)           (1)               (2)
 *        \             \               / \
 *        (3)     =>    (2)      =>   (1) (3)
 *        /               \
 *      (2)               (3)
 *                 right-Rotate     left-Rotate
 */
 
void test_doubleLeftRotate_given_3_elements_should_rotate_to_balance_tree(){
  
  Node Node2 = {.data=2, .rank=0,  .leftChild=NULL, .rightChild = NULL};
  Node Node3 = {.data=3, .rank=-1,  .leftChild=&Node2, .rightChild = NULL};
  Node Node1 = {.data=1, .rank=2, .leftChild=NULL, .rightChild = &Node3};
  Node *root;
  
  root = doubleLeftRotate(&Node1);
  TEST_ASSERT_EQUAL_PTR(&Node2, root);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node3, root->rightChild);
  TEST_ASSERT_NULL(Node1.leftChild);
  TEST_ASSERT_NULL(Node1.rightChild);
  TEST_ASSERT_NULL(Node3.leftChild);
  TEST_ASSERT_NULL(Node3.rightChild);
  TEST_ASSERT_EQUAL(0, Node2.rank);
  TEST_ASSERT_EQUAL(0, Node1.rank);
  TEST_ASSERT_EQUAL(0, Node3.rank);
}

/*
 *      (1)       
 *        \          
 *        (2)     
 *        /       
 *      (3)        
 * 
 */
 
void test_getHeight_given_3_elements_should_return_3(){
  
  Node Node3 = {.data=3, .rank=0,  .leftChild=NULL, .rightChild = NULL};
  Node Node2 = {.data=2, .rank=-1,  .leftChild=&Node3, .rightChild = NULL};
  Node Node1 = {.data=1, .rank=2, .leftChild=NULL, .rightChild = &Node2};
  int height;
  
  height = getHeight(&Node1);
  
  TEST_ASSERT_EQUAL(3,height);
}






