#include "unity.h"
#include "AVL.h"
#include "Rotation.h"

void setUp(){}
void tearDown(){}

/*
 *    (empty) -> (1)
 *
 */

void test_avlAdd_should_add_one_node_to_empty_root(){
  Node *root = NULL;
  Node Node1 = {.data=1, .balance=0, .leftChild=NULL, .rightChild = NULL};
  root = avlAdd(root,&Node1);
  
  TEST_ASSERT_EQUAL_PTR(&Node1,root);
}

/*
 *    (1) -> (1)
 *             \
 *             (50) 
 *
 */

void test_avlAdd_should_add_1_50(){
  Node Node1 = {.data=1, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node50 = {.data=50, .balance=0, .leftChild=NULL, .rightChild = NULL};
  
  Node *root = NULL;
  
  root = avlAdd(root,&Node1);
  root = avlAdd(root,&Node50);
  
  TEST_ASSERT_EQUAL_PTR(&Node1,root);
  TEST_ASSERT_EQUAL_PTR(&Node50,root->rightChild);
  
  TEST_ASSERT_NULL(Node1.leftChild);
  
  TEST_ASSERT_EQUAL(1,Node1.balance);
}

/*
 *    (1)                 (50)
 *      \                 /  \
 *      (50)     ->     (1)  (100)
 *        \
 *        (100)
 */

void test_avlAdd_should_add_from_1_50_100(){
  
  Node Node100 = {.data=100, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node50 = {.data=50, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node1 = {.data=1, .balance=0, .leftChild=NULL, .rightChild = NULL};
  
  
  Node *root = NULL;
  
  root = avlAdd(root,&Node1);
  root = avlAdd(root,&Node50);
  root = avlAdd(root,&Node100);
  
  TEST_ASSERT_EQUAL_PTR(&Node50,root);
  TEST_ASSERT_EQUAL_PTR(&Node100,root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node1,root->leftChild);
  
  TEST_ASSERT_NULL(Node1.leftChild);
  TEST_ASSERT_NULL(Node1.rightChild);
  TEST_ASSERT_NULL(Node100.leftChild);
  TEST_ASSERT_NULL(Node100.rightChild);
  
  TEST_ASSERT_EQUAL(0,Node1.balance);
  TEST_ASSERT_EQUAL(0,Node50.balance);
  TEST_ASSERT_EQUAL(0,Node100.balance);
}

/*
 *        (50)               (50)
 *        /  \               /  \
 *      (1)  (100)  ->     (1)  (100)
 *                              /
 *                           (75)
 */

void test_avlAdd_should_add_from_1_50_100_75(){
  
  Node Node100 = {.data=100, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node50 = {.data=50, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node1 = {.data=1, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node75 = {.data=75, .balance=0, .leftChild=NULL, .rightChild = NULL};
  
  
  Node *root = NULL;
  
  root = avlAdd(root,&Node1);
  root = avlAdd(root,&Node50);
  root = avlAdd(root,&Node100);
  root = avlAdd(root,&Node75);
  
  TEST_ASSERT_EQUAL_PTR(&Node50,root);
  TEST_ASSERT_EQUAL_PTR(&Node100,root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node1,root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node75,root->rightChild->leftChild);
  
  TEST_ASSERT_NULL(Node1.leftChild);
  TEST_ASSERT_NULL(Node1.rightChild);
  TEST_ASSERT_NULL(Node75.leftChild);
  TEST_ASSERT_NULL(Node75.rightChild);
  TEST_ASSERT_NULL(Node100.rightChild);
  
  TEST_ASSERT_EQUAL(0,Node1.balance);
  TEST_ASSERT_EQUAL(0,Node75.balance);
  TEST_ASSERT_EQUAL(1,Node50.balance);
  TEST_ASSERT_EQUAL(-1,Node100.balance);
}

/*
 *       (50)             (50)
 *       /  \             /  \
 *     (1)  (100)  ->   (1)  (100)
 *          /                /   \
 *       (75)             (75)   (150)
 */

void test_avlAdd_should_add_from_1_50_100_75_150(){
  
  Node Node100 = {.data=100, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node150 = {.data=150, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node50 = {.data=50, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node1 = {.data=1, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node75 = {.data=75, .balance=0, .leftChild=NULL, .rightChild = NULL};
  
  
  Node *root = NULL;
  
  root = avlAdd(root,&Node1);
  root = avlAdd(root,&Node50);
  root = avlAdd(root,&Node100);
  root = avlAdd(root,&Node75);
  root = avlAdd(root,&Node150);
  
  TEST_ASSERT_EQUAL_PTR(&Node50,root);
  TEST_ASSERT_EQUAL_PTR(&Node100,root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node1,root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node75,root->rightChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node150,root->rightChild->rightChild);
  
  TEST_ASSERT_NULL(Node1.leftChild);
  TEST_ASSERT_NULL(Node1.rightChild);
  TEST_ASSERT_NULL(Node75.leftChild);
  TEST_ASSERT_NULL(Node150.leftChild);
  TEST_ASSERT_NULL(Node75.rightChild);
  TEST_ASSERT_NULL(Node150.rightChild);
  
  TEST_ASSERT_EQUAL(0,Node1.balance);
  TEST_ASSERT_EQUAL(0,Node75.balance);
  TEST_ASSERT_EQUAL(1,Node50.balance);
  TEST_ASSERT_EQUAL(0,Node100.balance);
  TEST_ASSERT_EQUAL(0,Node150.balance);
}

/*
 *      (50)                    (50)                             (100)   
 *      /  \                    /  \                             /   \
 *    (1)  (100)      ->      (1)  (100)             ->       (50)   (150)
 *         /   \                   /   \                      /  \       \
 *      (75)   (150)            (75)   (150)                (1)  (75)    (200)
 *                                         \
 *                                         (200)
 */

void test_avlAdd_should_add_from_1_50_100_75_150_200(){
  
  Node Node100 = {.data=100, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node200 = {.data=200, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node150 = {.data=150, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node50 = {.data=50, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node1 = {.data=1, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node75 = {.data=75, .balance=0, .leftChild=NULL, .rightChild = NULL};
  
  
  Node *root = NULL;
  
  root = avlAdd(root,&Node1);
  root = avlAdd(root,&Node50);
  root = avlAdd(root,&Node100);
  root = avlAdd(root,&Node75);
  root = avlAdd(root,&Node150);
  printf("balance -> 200: %d 150: %d 100: %d 50: %d 75: %d 1: %d\n",Node200.balance,Node150.balance,Node100.balance,Node50.balance,Node75.balance,Node1.balance);
  root = avlAdd(root,&Node200);
  printf("balance -> 200: %d 150: %d 100: %d 50: %d 75: %d 1: %d\n",Node200.balance,Node150.balance,Node100.balance,Node50.balance,Node75.balance,Node1.balance);
  
  printf("root 50: %p\n",&Node50);
  printf("root 75: %p\n",&Node75);
  printf("root 100: %p\n",&Node100);
  printf("root 150: %p\n",&Node150);
  TEST_ASSERT_EQUAL_PTR(&Node100,root);
  TEST_ASSERT_EQUAL_PTR(&Node150,root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node50,root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node200,root->rightChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node75,root->leftChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node1,root->leftChild->leftChild);
  
  TEST_ASSERT_NULL(Node1.leftChild);
  TEST_ASSERT_NULL(Node1.rightChild);
  TEST_ASSERT_NULL(Node75.leftChild);
  TEST_ASSERT_NULL(Node150.leftChild);
  TEST_ASSERT_NULL(Node75.rightChild);
  TEST_ASSERT_NULL(Node200.leftChild);
  TEST_ASSERT_NULL(Node200.rightChild);
  
  TEST_ASSERT_EQUAL(0,Node1.balance);
  TEST_ASSERT_EQUAL(0,Node75.balance);
  TEST_ASSERT_EQUAL(0,Node50.balance);
  TEST_ASSERT_EQUAL(0,Node100.balance);
  TEST_ASSERT_EQUAL(1,Node150.balance);
  TEST_ASSERT_EQUAL(0,Node200.balance);
}

/*
 *      (50)
 *      /
 *    (1) 
 *
 */

void test_avlAdd_should_add_50_1(){
  
  Node Node50 = {.data=50, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node1 = {.data=1, .balance=0, .leftChild=NULL, .rightChild = NULL};
  
  Node *root = NULL;
  
  root = avlAdd(root,&Node50);
  root = avlAdd(root,&Node1);
  
  TEST_ASSERT_EQUAL_PTR(root,&Node50);
  TEST_ASSERT_EQUAL_PTR(root->leftChild,&Node1);
  
  TEST_ASSERT_NULL(Node1.leftChild);
  TEST_ASSERT_NULL(Node1.rightChild);
  TEST_ASSERT_NULL(Node50.rightChild);
  
  TEST_ASSERT_EQUAL(0,Node1.balance);
  TEST_ASSERT_EQUAL(-1,Node50.balance);
}

/*
 *      (50)          (50)
 *      /     ->      /  \
 *    (1)           (1)  (75)
 *
 */

void test_avlAdd_should_add_50_1_75(){
  
  Node Node50 = {.data=50, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node75 = {.data=75, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node1 = {.data=1, .balance=0, .leftChild=NULL, .rightChild = NULL};
  
  Node *root = NULL;
  
  root = avlAdd(root,&Node50);
  root = avlAdd(root,&Node1);
  root = avlAdd(root,&Node75);
  
  TEST_ASSERT_EQUAL_PTR(root,&Node50);
  TEST_ASSERT_EQUAL_PTR(root->leftChild,&Node1);
  TEST_ASSERT_EQUAL_PTR(root->rightChild,&Node75);
  
  TEST_ASSERT_NULL(Node1.leftChild);
  TEST_ASSERT_NULL(Node75.leftChild);
  TEST_ASSERT_NULL(Node1.rightChild);
  TEST_ASSERT_NULL(Node75.rightChild);
  
  TEST_ASSERT_EQUAL(0,Node1.balance);
  TEST_ASSERT_EQUAL(0,Node50.balance);
  TEST_ASSERT_EQUAL(0,Node75.balance);
}














