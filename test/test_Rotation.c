#include "unity.h"
#include "AVL.h"
#include "AVLInt.h"
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
  NodeInt Node3 = {.data=3, .balance=0,  .leftChild=NULL, .rightChild = NULL};
  NodeInt Node2 = {.data=2, .balance=1,  .leftChild=NULL, .rightChild = &Node3};
  NodeInt Node1 = {.data=1, .balance=2, .leftChild=NULL, .rightChild = &Node2};
  NodeInt *root;
  
  root = (NodeInt *)leftRotate((Node *)&Node1);
  TEST_ASSERT_EQUAL_PTR(&Node2, root);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node3, root->rightChild);
  
  TEST_ASSERT_EQUAL(0, Node2.balance);
  TEST_ASSERT_EQUAL(0, Node1.balance);
  TEST_ASSERT_EQUAL(0, Node3.balance);
}

/*
 *        (3)           (2)
 *        /             / \
 *      (2)     =>    (1) (3)
 *      /
 *    (1)
 */
 
void test_rightRotate_given_3_elements_should_rotate_to_balance_tree(){
  NodeInt Node1 = {.data=1, .balance=0, .leftChild=NULL, .rightChild = NULL};
  NodeInt Node2 = {.data=2, .balance=-1,  .leftChild=&Node1, .rightChild = NULL};
  NodeInt Node3 = {.data=3, .balance=-2,  .leftChild=&Node2, .rightChild = NULL};
  NodeInt *root;
  
  root = (NodeInt *)rightRotate((Node *)&Node3);
  TEST_ASSERT_EQUAL_PTR(&Node2, root);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node3, root->rightChild);
  
  TEST_ASSERT_EQUAL(0, Node2.balance);
  TEST_ASSERT_EQUAL(0, Node1.balance);
  TEST_ASSERT_EQUAL(0, Node3.balance);
}

/*
 *        (3)           (3)           (2)
 *        /             /             / \
 *      (1)     =>    (2)      =>   (1) (3)
 *        \           /
 *        (2)       (1)
 *                 left-Rotate    right-Rotate
 */
 
void test_doubleRightRotate_given_3_elements_should_rotate_to_balance_tree(){
  NodeInt Node2 = {.data=2, .balance=0,  .leftChild=NULL, .rightChild = NULL};
  NodeInt Node1 = {.data=1, .balance=1, .leftChild=NULL, .rightChild = &Node2};
  NodeInt Node3 = {.data=3, .balance=-2,  .leftChild=&Node1, .rightChild = NULL};
  NodeInt *root;
  
  root = (NodeInt *)doubleRightRotate((Node *)&Node3);
  TEST_ASSERT_EQUAL_PTR(&Node2, root);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node3, root->rightChild);
  
  TEST_ASSERT_EQUAL(0, Node2.balance);
  TEST_ASSERT_EQUAL(0, Node1.balance);
  TEST_ASSERT_EQUAL(0, Node3.balance);
}

/*
 *        (50)             (50)                 (30)
 *        /  \             /  \                 /  \
 *      (10) (100)    => (30) (100)    =>     (10) (50)
 *      /  \             /  \                 /    /  \
 *    (5)  (30)        (10) (40)            (5)  (40) (100)
 *            \        /
 *            (40)   (5)
 *                 left-Rotate    right-Rotate
 */
 
void test_doubleRightRotate_given_6_elements_should_rotate_to_balance_tree(){
  NodeInt Node40 = {.data=40, .balance=0,  .leftChild=NULL, .rightChild = NULL};
  NodeInt Node30 = {.data=30, .balance=1,  .leftChild=NULL, .rightChild = &Node40};
  NodeInt Node5 = {.data=5, .balance=0,  .leftChild=NULL, .rightChild = NULL};
  NodeInt Node100 = {.data=100, .balance=0, .leftChild=NULL, .rightChild = NULL};
  NodeInt Node10 = {.data=10, .balance=1, .leftChild=&Node5, .rightChild = &Node30};
  NodeInt Node50 = {.data=50, .balance=-2,  .leftChild=&Node10, .rightChild = &Node100};
  NodeInt *root;
  
  root = (NodeInt *)doubleRightRotate((Node *)&Node50);
  TEST_ASSERT_EQUAL_PTR(&Node30, root);
  TEST_ASSERT_EQUAL_PTR(&Node10, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node5, root->leftChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node50, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node100, root->rightChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node40, root->rightChild->leftChild);
  
  TEST_ASSERT_NULL(Node10.rightChild);
  TEST_ASSERT_NULL(Node5.rightChild);
  TEST_ASSERT_NULL(Node40.rightChild);
  TEST_ASSERT_NULL(Node100.rightChild);
  TEST_ASSERT_NULL(Node5.leftChild);
  TEST_ASSERT_NULL(Node40.leftChild);
  TEST_ASSERT_NULL(Node100.leftChild);
  
  TEST_ASSERT_EQUAL(0,Node5.balance);
  TEST_ASSERT_EQUAL(0,Node40.balance);
  TEST_ASSERT_EQUAL(0,Node100.balance);
  TEST_ASSERT_EQUAL(0,Node30.balance);
  TEST_ASSERT_EQUAL(0,Node50.balance);
  TEST_ASSERT_EQUAL(-1,Node10.balance);
}

/*
 *        (50)             (50)                 (30)
 *        /  \             /  \                 /  \
 *      (10) (100)    => (30) (100)    =>     (10) (50)
 *      /  \             /                    /  \    \
 *    (5)  (30)        (10)                 (5)  (20) (100)
 *         /           /  \
 *      (20)         (5)  (20)
 *                 left-Rotate    right-Rotate
 */
 
void test_doubleRightRotate_given_6_elements_should_rotate_left_then_right_to_balance_tree(){
  NodeInt Node20 = {.data=20, .balance=0,  .leftChild=NULL, .rightChild = NULL};
  NodeInt Node30 = {.data=30, .balance=-1,  .leftChild=&Node20, .rightChild = NULL};
  NodeInt Node5 = {.data=5, .balance=0,  .leftChild=NULL, .rightChild = NULL};
  NodeInt Node100 = {.data=100, .balance=0, .leftChild=NULL, .rightChild = NULL};
  NodeInt Node10 = {.data=10, .balance=1, .leftChild=&Node5, .rightChild = &Node30};
  NodeInt Node50 = {.data=50, .balance=-2,  .leftChild=&Node10, .rightChild = &Node100};
  NodeInt *root;
  
  root = (NodeInt *)doubleRightRotate((Node *)&Node50);
  TEST_ASSERT_EQUAL_PTR(&Node30, root);
  TEST_ASSERT_EQUAL_PTR(&Node10, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node5, root->leftChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node50, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node100, root->rightChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node20, root->leftChild->rightChild);
  
  TEST_ASSERT_NULL(Node50.leftChild);
  TEST_ASSERT_NULL(Node5.rightChild);
  TEST_ASSERT_NULL(Node20.rightChild);
  TEST_ASSERT_NULL(Node100.rightChild);
  TEST_ASSERT_NULL(Node5.leftChild);
  TEST_ASSERT_NULL(Node20.leftChild);
  TEST_ASSERT_NULL(Node100.leftChild);
  
  TEST_ASSERT_EQUAL(0,Node5.balance);
  TEST_ASSERT_EQUAL(0,Node30.balance);
  TEST_ASSERT_EQUAL(0,Node100.balance);
  TEST_ASSERT_EQUAL(0,Node20.balance);
  TEST_ASSERT_EQUAL(1,Node50.balance);
  TEST_ASSERT_EQUAL(0,Node10.balance);
}

/*
 *        (50)                    ( 50 )                 (  30  )
 *        /  \                    /    \                 /      \
 *      (10) (100)        =>    ( 30 ) (100)    =>     (10)     (50)
 *      /  \     \              /    \     \           /  \     /  \
 *    (5)  (30)  (150)        (10)    (40) (150)     (5)  (20)(40) (100)
 *    /    /  \               /  \     /             /        /        \
 *  (1) (20)  (40)          (5)  (20)(36)          (1)      (36)       (150)
 *            /             /
 *          (36)          (1)
 *                           left-Rotate                right-Rotate
 */
 
void test_doubleRightRotate_given_10_elements_should_rotate_left_then_right_to_balance_tree(){
  NodeInt Node1 = {.data=1, .balance=0,  .leftChild=NULL, .rightChild = NULL};
  NodeInt Node36 = {.data=36, .balance=0,  .leftChild=NULL, .rightChild = NULL};
  NodeInt Node20 = {.data=20, .balance=0,  .leftChild=NULL, .rightChild = NULL};
  NodeInt Node40 = {.data=40, .balance=-1,  .leftChild=&Node36, .rightChild = NULL};
  NodeInt Node30 = {.data=30, .balance=1,  .leftChild=&Node20, .rightChild = &Node40};
  NodeInt Node5 = {.data=5, .balance=-1,  .leftChild=&Node1, .rightChild = NULL};
  NodeInt Node150 = {.data=150, .balance=0,  .leftChild=NULL, .rightChild = NULL};
  NodeInt Node100 = {.data=100, .balance=1, .leftChild=NULL, .rightChild = &Node150};
  NodeInt Node10 = {.data=10, .balance=1, .leftChild=&Node5, .rightChild = &Node30};
  NodeInt Node50 = {.data=50, .balance=-2,  .leftChild=&Node10, .rightChild = &Node100};
  NodeInt *root;
  
  root = (NodeInt *)doubleRightRotate((Node *)&Node50);
  TEST_ASSERT_EQUAL_PTR(&Node30, root);
  TEST_ASSERT_EQUAL_PTR(&Node10, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node20, root->leftChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node5, root->leftChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild->leftChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node50, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node100, root->rightChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node150, root->rightChild->rightChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node36, root->rightChild->leftChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node40, root->rightChild->leftChild);
  
  TEST_ASSERT_NULL(Node5.rightChild);
  TEST_ASSERT_NULL(Node100.leftChild);
  TEST_ASSERT_NULL(Node40.rightChild);
  TEST_ASSERT_NULL(Node1.rightChild);
  TEST_ASSERT_NULL(Node36.rightChild);
  TEST_ASSERT_NULL(Node150.rightChild);
  TEST_ASSERT_NULL(Node20.rightChild);
  TEST_ASSERT_NULL(Node1.leftChild);
  TEST_ASSERT_NULL(Node36.leftChild);
  TEST_ASSERT_NULL(Node150.leftChild);
  TEST_ASSERT_NULL(Node20.leftChild);
  
  TEST_ASSERT_EQUAL(0,Node1.balance);
  TEST_ASSERT_EQUAL(0,Node36.balance);
  TEST_ASSERT_EQUAL(0,Node150.balance);
  TEST_ASSERT_EQUAL(0,Node50.balance);
  TEST_ASSERT_EQUAL(-1,Node10.balance);
  TEST_ASSERT_EQUAL(0,Node30.balance);
  TEST_ASSERT_EQUAL(0,Node20.balance);
  TEST_ASSERT_EQUAL(-1,Node5.balance);
  TEST_ASSERT_EQUAL(-1,Node40.balance);
  TEST_ASSERT_EQUAL(1,Node100.balance);
}

void test_doubleRightRotate_given_10_balanced_elements_should_return_4_as_height(){
  NodeInt Node1 = {.data=1, .balance=0,  .leftChild=NULL, .rightChild = NULL};
  NodeInt Node36 = {.data=36, .balance=0,  .leftChild=NULL, .rightChild = NULL};
  NodeInt Node20 = {.data=20, .balance=0,  .leftChild=NULL, .rightChild = NULL};
  NodeInt Node40 = {.data=40, .balance=-1,  .leftChild=&Node36, .rightChild = NULL};
  NodeInt Node5 = {.data=5, .balance=-1,  .leftChild=&Node1, .rightChild = NULL};
  NodeInt Node150 = {.data=150, .balance=0,  .leftChild=NULL, .rightChild = NULL};
  NodeInt Node100 = {.data=100, .balance=1, .leftChild=NULL, .rightChild = &Node150};
  NodeInt Node10 = {.data=10, .balance=-1, .leftChild=&Node5, .rightChild = &Node20};
  NodeInt Node50 = {.data=50, .balance=0,  .leftChild=&Node40, .rightChild = &Node100};
  NodeInt Node30 = {.data=30, .balance=0,  .leftChild=&Node10, .rightChild = &Node50};
  int height;
  
  height=getHeight((Node *)&Node30);
  
  TEST_ASSERT_EQUAL(4,height);
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
  
  NodeInt Node2 = {.data=2, .balance=0,  .leftChild=NULL, .rightChild = NULL};
  NodeInt Node3 = {.data=3, .balance=-1,  .leftChild=&Node2, .rightChild = NULL};
  NodeInt Node1 = {.data=1, .balance=2, .leftChild=NULL, .rightChild = &Node3};
  NodeInt *root;
  
  root = (NodeInt *)doubleLeftRotate((Node *)&Node1);
  TEST_ASSERT_EQUAL_PTR(&Node2, root);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node3, root->rightChild);
  TEST_ASSERT_NULL(Node1.leftChild);
  TEST_ASSERT_NULL(Node1.rightChild);
  TEST_ASSERT_NULL(Node3.leftChild);
  TEST_ASSERT_NULL(Node3.rightChild);
  
  TEST_ASSERT_EQUAL(0,Node2.balance);
  TEST_ASSERT_EQUAL(0,Node3.balance);
  TEST_ASSERT_EQUAL(0,Node1.balance);
}

/*
 *        (18)                          (20)
 *        /  \                          /   \
 *     (10)  (30)           =>       (18)   (30)
 *           /   \                   /  \       \
 *         (20)  (40)             (10)  (19)    (40)
 *         /
 *      (19)
 *
 */
 
void test_leftRotate_to_balance_an_6elements_unbalanced_tree(){
  NodeInt Node40 = {.data=40, .balance=0,  .leftChild=NULL, .rightChild = NULL};
  NodeInt Node19 = {.data=19, .balance=0,  .leftChild=NULL, .rightChild = NULL};
  NodeInt Node20 = {.data=20, .balance=-1,  .leftChild=&Node19, .rightChild = NULL};
  NodeInt Node30 = {.data=30, .balance=-1,  .leftChild=&Node20, .rightChild = &Node40};
  NodeInt Node10 = {.data=10, .balance=0,  .leftChild=NULL, .rightChild = NULL};
  NodeInt Node18 = {.data=18, .balance=2,  .leftChild=&Node10, .rightChild =&Node30};

  NodeInt *root;
  root = (NodeInt *)doubleLeftRotate((Node *)&Node18);
  TEST_ASSERT_EQUAL_PTR(&Node20, root);
  TEST_ASSERT_EQUAL_PTR(&Node18,root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node30,root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node40,root->rightChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node10,root->leftChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node19,root->leftChild->rightChild);
  TEST_ASSERT_NULL(Node10.leftChild);
  TEST_ASSERT_NULL(Node19.leftChild);
  TEST_ASSERT_NULL(Node40.leftChild);
  TEST_ASSERT_NULL(Node30.leftChild);
  TEST_ASSERT_NULL(Node19.rightChild);
  TEST_ASSERT_NULL(Node10.rightChild);
  TEST_ASSERT_NULL(Node40.rightChild);
  
  TEST_ASSERT_EQUAL(1,Node30.balance);
  TEST_ASSERT_EQUAL(0,Node20.balance);
  TEST_ASSERT_EQUAL(0,Node18.balance);
  TEST_ASSERT_EQUAL(0,Node40.balance);
  TEST_ASSERT_EQUAL(0,Node19.balance);
  TEST_ASSERT_EQUAL(0,Node10.balance);
}

/*
 *      (1)       
 *        \          
 *        (2)     
 *        /       
 *      (3)        
 * 
 */
 
void test_getHeight_given_3_elements_tree_should_return_3(){
  
  NodeInt Node3 = {.data=3, .balance=0,  .leftChild=NULL, .rightChild = NULL};
  NodeInt Node2 = {.data=2, .balance=-1,  .leftChild=&Node3, .rightChild = NULL};
  NodeInt Node1 = {.data=1, .balance=2, .leftChild=NULL, .rightChild = &Node2};
  int height;
  
  height = getHeight((Node *)&Node1);
  
  TEST_ASSERT_EQUAL(3,height);
}

/*
 *        (50)                          (100)
 *        /  \                          /   \
 *     (10)  (100)           =>       (50)  (150)
 *           /   \                    /  \      \
 *         (70)  (150)             (10)  (70)   (200)
 *                  \
 *                  (200)
 *
 */
 
void test_leftRotate_to_balance_an_unbalanced_tree(){
  NodeInt Node200 = {.data=200, .balance=0,  .leftChild=NULL, .rightChild = NULL};
  NodeInt Node150 = {.data=150, .balance=1,  .leftChild=NULL, .rightChild = &Node200};
  NodeInt Node70 = {.data=70, .balance=0,  .leftChild=NULL, .rightChild = NULL};
  NodeInt Node100 = {.data=100, .balance=1,  .leftChild=&Node70, .rightChild = &Node150};
  NodeInt Node10 = {.data=10, .balance=0,  .leftChild=NULL, .rightChild = NULL};
  NodeInt Node50 = {.data=50, .balance=2,  .leftChild=&Node10, .rightChild =&Node100};

  NodeInt *root;
  root = (NodeInt *)leftRotate((Node *)&Node50);
  TEST_ASSERT_EQUAL_PTR(&Node100, root);
  TEST_ASSERT_EQUAL_PTR(&Node50,root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node150,root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node200,root->rightChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node10,root->leftChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node70,root->leftChild->rightChild);
  TEST_ASSERT_NULL(Node70.leftChild);
  TEST_ASSERT_NULL(Node10.leftChild);
  TEST_ASSERT_NULL(Node200.leftChild);
  TEST_ASSERT_NULL(Node70.rightChild);
  TEST_ASSERT_NULL(Node10.rightChild);
  TEST_ASSERT_NULL(Node200.rightChild);
  
  TEST_ASSERT_EQUAL(1,Node150.balance);
  TEST_ASSERT_EQUAL(0,Node200.balance);
  TEST_ASSERT_EQUAL(0,Node100.balance);
  TEST_ASSERT_EQUAL(0,Node70.balance);
  TEST_ASSERT_EQUAL(0,Node50.balance);
  TEST_ASSERT_EQUAL(0,Node10.balance);
}

/*
 *        (50)                          (20)
 *        /  \                          /   \
 *     (20)  (100)           =>       (5)   (50)
 *     /  \                           /     /  \
 *   (5)  (30)                      (1)  (30)   (100)
 *   /
 * (1)
 *
 */

void test_rightRotate_within_6_elements_to_balance_an_unbalanced_tree(){
  NodeInt Node1 = {.data=1, .balance=0,  .leftChild=NULL, .rightChild = NULL};
  NodeInt Node30 = {.data=30, .balance=0,  .leftChild=NULL, .rightChild = NULL};
  NodeInt Node5 = {.data=5, .balance=-1,  .leftChild=&Node1, .rightChild = NULL};
  NodeInt Node100 = {.data=100, .balance=0,  .leftChild=NULL, .rightChild = NULL};
  NodeInt Node20 = {.data=20, .balance=-1,  .leftChild=&Node5, .rightChild =&Node30};
  NodeInt Node50 = {.data=50, .balance=-2,  .leftChild=&Node20, .rightChild =&Node100};

  NodeInt *root;
  root = (NodeInt *)rightRotate((Node *)&Node50);
  TEST_ASSERT_EQUAL_PTR(&Node20, root);
  TEST_ASSERT_EQUAL_PTR(&Node5, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node1, root->leftChild->leftChild);
  TEST_ASSERT_EQUAL_PTR(&Node50, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node100, root->rightChild->rightChild);
  TEST_ASSERT_EQUAL_PTR(&Node30, root->rightChild->leftChild);
  TEST_ASSERT_NULL(root->leftChild->rightChild);
  TEST_ASSERT_NULL(root->leftChild->leftChild->leftChild);
  TEST_ASSERT_NULL(root->leftChild->leftChild->rightChild);
  TEST_ASSERT_NULL(root->rightChild->leftChild->leftChild);
  TEST_ASSERT_NULL(root->rightChild->leftChild->rightChild);
  TEST_ASSERT_NULL(root->rightChild->rightChild->rightChild);
  TEST_ASSERT_NULL(root->rightChild->rightChild->leftChild);
  
  TEST_ASSERT_EQUAL(0,Node20.balance);
  TEST_ASSERT_EQUAL(-1,Node5.balance);
  TEST_ASSERT_EQUAL(0,Node100.balance);
  TEST_ASSERT_EQUAL(0,Node30.balance);
  TEST_ASSERT_EQUAL(0,Node50.balance);
  TEST_ASSERT_EQUAL(0,Node1.balance);
}









