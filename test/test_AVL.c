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
  root = avlAdd(root,&Node200);
  
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
 *          (100)   
 *          /   \
 *       (50)    (150)
 *       /  \    /   \
 *     (1) (75) (120)(200)
 *                ^
 *             add this
 */

void test_avlAdd_should_add_from_1_50_100_75_150_200_120(){
  
  Node Node100 = {.data=100, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node120 = {.data=120, .balance=0, .leftChild=NULL, .rightChild = NULL};
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
  root = avlAdd(root,&Node200);
  root = avlAdd(root,&Node120);
  
  TEST_ASSERT_EQUAL_PTR(&Node100,root);
  TEST_ASSERT_EQUAL_PTR(&Node150,root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node50,root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node200,root->rightChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node120,root->rightChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node75,root->leftChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node1,root->leftChild->leftChild);
  
  TEST_ASSERT_NULL(Node1.leftChild);
  TEST_ASSERT_NULL(Node1.rightChild);
  TEST_ASSERT_NULL(Node75.leftChild);
  TEST_ASSERT_NULL(Node120.leftChild);
  TEST_ASSERT_NULL(Node120.rightChild);
  TEST_ASSERT_NULL(Node75.rightChild);
  TEST_ASSERT_NULL(Node200.leftChild);
  TEST_ASSERT_NULL(Node200.rightChild);
  
  TEST_ASSERT_EQUAL(0,Node1.balance);
  TEST_ASSERT_EQUAL(0,Node75.balance);
  TEST_ASSERT_EQUAL(0,Node50.balance);
  TEST_ASSERT_EQUAL(0,Node100.balance);
  TEST_ASSERT_EQUAL(0,Node150.balance);
  TEST_ASSERT_EQUAL(0,Node120.balance);
  TEST_ASSERT_EQUAL(0,Node200.balance);
}

/*
 *          (100)                                     (120)
 *          /   \                                     /   \
 *       (50)    (150)                            (100)   (150)
 *       /  \    /   \                            /   \    /  \
 *     (1) (75) (120)(200)            ->       (50) (110)(130)(200)
 *              /   \    \                     /  \         \     \
 *     1st>(110) 2nd>(130) (250)<3rd         (1)  (75)      (140) (250)
 *                     \
 *                     (140)<last
 *
 */

void test_avlAdd_should_add_from_1_50_100_75_150_200_120_110_130_250_140(){
  
  Node Node100 = {.data=100, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node120 = {.data=120, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node200 = {.data=200, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node150 = {.data=150, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node50 = {.data=50, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node1 = {.data=1, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node75 = {.data=75, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node110 = {.data=110, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node130 = {.data=130, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node250 = {.data=250, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node140 = {.data=140, .balance=0, .leftChild=NULL, .rightChild = NULL};
  
  
  Node *root = NULL;
  
  root = avlAdd(root,&Node1);
  root = avlAdd(root,&Node50);
  root = avlAdd(root,&Node100);
  root = avlAdd(root,&Node75);
  root = avlAdd(root,&Node150);
  root = avlAdd(root,&Node200);
  root = avlAdd(root,&Node120);
  root = avlAdd(root,&Node110);
  printf("balance of 100: %d\n\n", Node100.balance);
  root = avlAdd(root,&Node130);
  printf("balance of 100: %d\n", Node100.balance);
  printf("balance of 120: %d\n", Node120.balance);
  printf("balance of 150: %d\n\n", Node150.balance);
  root = avlAdd(root,&Node250);
  printf("balance of 100: %d\n", Node100.balance);
  printf("balance of 120: %d\n", Node120.balance);
  printf("balance of 150: %d\n", Node150.balance);
  printf("balance of 200: %d\n\n", Node200.balance);
  root = avlAdd(root,&Node140);
  
  printf("root 50: %p\n",&Node50);
  printf("root 75: %p\n",&Node75);
  printf("root 100: %p\n",&Node100);
  printf("root 150: %p\n",&Node150);
  TEST_ASSERT_EQUAL_PTR(&Node120,root);
  TEST_ASSERT_EQUAL_PTR(&Node150,root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node100,root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node110,root->leftChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node200,root->rightChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node250,root->rightChild->rightChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node130,root->rightChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node140,root->rightChild->leftChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node75,root->leftChild->leftChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node50,root->leftChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node1,root->leftChild->leftChild->leftChild);
  
  TEST_ASSERT_NULL(Node1.leftChild);
  TEST_ASSERT_NULL(Node1.rightChild);
  TEST_ASSERT_NULL(Node75.leftChild);
  TEST_ASSERT_NULL(Node75.rightChild);
  TEST_ASSERT_NULL(Node110.leftChild);
  TEST_ASSERT_NULL(Node110.rightChild);
  TEST_ASSERT_NULL(Node140.leftChild);
  TEST_ASSERT_NULL(Node140.rightChild);
  TEST_ASSERT_NULL(Node250.leftChild);
  TEST_ASSERT_NULL(Node200.leftChild);
  TEST_ASSERT_NULL(Node130.leftChild);
  TEST_ASSERT_NULL(Node250.rightChild);
  
  TEST_ASSERT_EQUAL(0,Node1.balance);
  TEST_ASSERT_EQUAL(0,Node75.balance);
  TEST_ASSERT_EQUAL(0,Node50.balance);
  TEST_ASSERT_EQUAL(-1,Node100.balance);
  TEST_ASSERT_EQUAL(0,Node150.balance);
  TEST_ASSERT_EQUAL(0,Node120.balance);
  TEST_ASSERT_EQUAL(1,Node200.balance);
  TEST_ASSERT_EQUAL(0,Node110.balance);
  TEST_ASSERT_EQUAL(1,Node130.balance);
  TEST_ASSERT_EQUAL(0,Node140.balance);
  TEST_ASSERT_EQUAL(0,Node250.balance);
}

/*
 *          (100)                                     (120)
 *          /   \                                     /   \
 *       (50)    (150)                            (100)   (150)
 *       /  \    /   \                            /   \    /  \
 *     (1) (75) (120)(200)            ->       (50) (110)(130)(200)
 *              /   \    \                     /  \   /           \
 *     1st>(110) 2nd>(130) (250)<3rd         (1) (75)(105)        (250)
 *         /
 *     (105)<last
 *
 */

void test_avlAdd_should_add_from_1_50_100_75_150_200_120_110_130_250_105(){
  
  Node Node100 = {.data=100, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node120 = {.data=120, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node200 = {.data=200, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node150 = {.data=150, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node50 = {.data=50, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node1 = {.data=1, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node75 = {.data=75, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node110 = {.data=110, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node130 = {.data=130, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node250 = {.data=250, .balance=0, .leftChild=NULL, .rightChild = NULL};
  Node Node105 = {.data=105, .balance=0, .leftChild=NULL, .rightChild = NULL};
  
  
  Node *root = NULL;
  
  root = avlAdd(root,&Node1);
  root = avlAdd(root,&Node50);
  root = avlAdd(root,&Node100);
  root = avlAdd(root,&Node75);
  root = avlAdd(root,&Node150);
  root = avlAdd(root,&Node200);
  root = avlAdd(root,&Node120);
  root = avlAdd(root,&Node110);
  printf("balance of 100: %d\n\n", Node100.balance);
  root = avlAdd(root,&Node130);
  printf("balance of 100: %d\n", Node100.balance);
  printf("balance of 120: %d\n", Node120.balance);
  printf("balance of 150: %d\n\n", Node150.balance);
  root = avlAdd(root,&Node250);
  printf("balance of 100: %d\n", Node100.balance);
  printf("balance of 120: %d\n", Node120.balance);
  printf("balance of 150: %d\n", Node150.balance);
  printf("balance of 200: %d\n\n", Node200.balance);
  root = avlAdd(root,&Node105);
  
  printf("root 50: %p\n",&Node50);
  printf("root 75: %p\n",&Node75);
  printf("root 100: %p\n",&Node100);
  printf("root 150: %p\n",&Node150);
  TEST_ASSERT_EQUAL_PTR(&Node120,root);
  TEST_ASSERT_EQUAL_PTR(&Node150,root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node100,root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node110,root->leftChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node200,root->rightChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node250,root->rightChild->rightChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node130,root->rightChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node105,root->leftChild->rightChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node75,root->leftChild->leftChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node50,root->leftChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node1,root->leftChild->leftChild->leftChild);
  
  TEST_ASSERT_NULL(Node1.leftChild);
  TEST_ASSERT_NULL(Node1.rightChild);
  TEST_ASSERT_NULL(Node75.leftChild);
  TEST_ASSERT_NULL(Node75.rightChild);
  TEST_ASSERT_NULL(Node110.rightChild);
  TEST_ASSERT_NULL(Node105.leftChild);
  TEST_ASSERT_NULL(Node105.rightChild);
  TEST_ASSERT_NULL(Node250.leftChild);
  TEST_ASSERT_NULL(Node200.leftChild);
  TEST_ASSERT_NULL(Node130.leftChild);
  TEST_ASSERT_NULL(Node130.rightChild);
  TEST_ASSERT_NULL(Node250.rightChild);
  
  TEST_ASSERT_EQUAL(0,Node1.balance);
  TEST_ASSERT_EQUAL(0,Node75.balance);
  TEST_ASSERT_EQUAL(0,Node50.balance);
  TEST_ASSERT_EQUAL(0,Node100.balance);
  TEST_ASSERT_EQUAL(1,Node150.balance);
  TEST_ASSERT_EQUAL(0,Node120.balance);
  TEST_ASSERT_EQUAL(1,Node200.balance);
  TEST_ASSERT_EQUAL(-1,Node110.balance);
  TEST_ASSERT_EQUAL(0,Node130.balance);
  TEST_ASSERT_EQUAL(0,Node105.balance);
  TEST_ASSERT_EQUAL(0,Node250.balance);
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














