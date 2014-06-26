#include "unity.h"
#include "AVL.h"
#include "Rotation.h"
#include "CustomAssert.h"

Node Node1, Node50, Node100, Node75, Node150, Node200, Node120, Node110, \
Node130, Node250, Node140, Node105;

void initNode(Node *node, int nodeData){
  node->balance = 0;
  node->data = nodeData;
  node->leftChild = NULL;
  node->rightChild = NULL;
}

void setUp(){
initNode(&Node1,1);
initNode(&Node50,50);
initNode(&Node100,100);
initNode(&Node75,75);
initNode(&Node150,150);
initNode(&Node200,200);
initNode(&Node120,120);
initNode(&Node110,110);
initNode(&Node130,130);
initNode(&Node250,250);
initNode(&Node140,140);
initNode(&Node105,105);
}
void tearDown(){}

/*
 *    (empty) -> (1)
 *
 */

void test_avlAdd_should_add_one_node_to_empty_root(){
  Node *root = NULL;
  root = avlAdd(root,&Node1);
  
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
}

/*
 *    (1) -> (1)
 *             \
 *             (50) 
 *
 */

void test_avlAdd_should_add_1_50(){
  Node *root = NULL;
  
  root = avlAdd(root,&Node1);
  root = avlAdd(root,&Node50);
  
  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node50,1,&Node1);
}

/*
 *    (1)                 (50)
 *      \                 /  \
 *      (50)     ->     (1)  (100)
 *        \
 *        (100)
 */

void test_avlAdd_should_add_from_1_50_100(){
  Node *root = NULL;
  
  root = avlAdd(root,&Node1);
  root = avlAdd(root,&Node50);
  root = avlAdd(root,&Node100);
  
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,&Node100,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node100);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
}

/*
 *        (50)               (50)
 *        /  \               /  \
 *      (1)  (100)  ->     (1)  (100)
 *                              /
 *                           (75)
 */

void test_avlAdd_should_add_from_1_50_100_75(){
  Node *root = NULL;
  
  root = avlAdd(root,&Node1);
  root = avlAdd(root,&Node50);
  root = avlAdd(root,&Node100);
  root = avlAdd(root,&Node75);
  
  
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,&Node100,1,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(&Node75,NULL,-1,&Node100);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node75);
}

/*
 *       (50)             (50)
 *       /  \             /  \
 *     (1)  (100)  ->   (1)  (100)
 *          /                /   \
 *       (75)             (75)   (150)
 */

void test_avlAdd_should_add_from_1_50_100_75_150(){
  Node *root = NULL;
  
  root = avlAdd(root,&Node1);
  root = avlAdd(root,&Node50);
  root = avlAdd(root,&Node100);
  root = avlAdd(root,&Node75);
  root = avlAdd(root,&Node150);
  
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,&Node100,1,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(&Node75,&Node150,0,&Node100);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node75);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node150);
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
  Node *root = NULL;
  
  root = avlAdd(root,&Node1);
  root = avlAdd(root,&Node50);
  root = avlAdd(root,&Node100);
  root = avlAdd(root,&Node75);
  root = avlAdd(root,&Node150);
  root = avlAdd(root,&Node200);
  
  TEST_ASSERT_EQUAL_AVL_Node(&Node50,&Node150,0,&Node100);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,&Node75,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node200,1,&Node150);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node75);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node200);
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
  Node *root = NULL;
  
  root = avlAdd(root,&Node1);
  root = avlAdd(root,&Node50);
  root = avlAdd(root,&Node100);
  root = avlAdd(root,&Node75);
  root = avlAdd(root,&Node150);
  root = avlAdd(root,&Node200);
  root = avlAdd(root,&Node120);
  
  TEST_ASSERT_EQUAL_AVL_Node(&Node50,&Node150,0,&Node100);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,&Node75,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(&Node120,&Node200,0,&Node150);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node75);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node120);
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
  Node *root = NULL;
  
  root = avlAdd(root,&Node1);
  root = avlAdd(root,&Node50);
  root = avlAdd(root,&Node100);
  root = avlAdd(root,&Node75);
  root = avlAdd(root,&Node150);
  root = avlAdd(root,&Node200);
  root = avlAdd(root,&Node120);
  root = avlAdd(root,&Node110);
  root = avlAdd(root,&Node130);
  root = avlAdd(root,&Node250);
  root = avlAdd(root,&Node140);
  
  TEST_ASSERT_EQUAL_AVL_Node(&Node100,&Node150,0,&Node120);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,&Node75,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(&Node50,&Node110,-1,&Node100);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node140,1,&Node130);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node250,1,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(&Node130,&Node200,0,&Node150);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node75);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node250);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node140);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node110);
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
  Node *root = NULL;
  
  root = avlAdd(root,&Node1);
  root = avlAdd(root,&Node50);
  root = avlAdd(root,&Node100);
  root = avlAdd(root,&Node75);
  root = avlAdd(root,&Node150);
  root = avlAdd(root,&Node200);
  root = avlAdd(root,&Node120);
  root = avlAdd(root,&Node110);
  root = avlAdd(root,&Node130);
  root = avlAdd(root,&Node250);
  root = avlAdd(root,&Node105);
  
  TEST_ASSERT_EQUAL_AVL_Node(&Node100,&Node150,0,&Node120);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,&Node75,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(&Node50,&Node110,0,&Node100);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node130);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node250,1,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(&Node130,&Node200,1,&Node150);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node75);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node250);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node105);
  TEST_ASSERT_EQUAL_AVL_Node(&Node105,NULL,-1,&Node110);
}

/*
 *      (50)
 *      /
 *    (1) 
 *
 */

void test_avlAdd_should_add_50_1(){
  Node *root = NULL;
  
  root = avlAdd(root,&Node50);
  root = avlAdd(root,&Node1);
  
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,NULL,-1,&Node50);
}

/*
 *      (50)          (50)
 *      /     ->      /  \
 *    (1)           (1)  (75)
 *
 */

void test_avlAdd_should_add_50_1_75(){
  Node *root = NULL;
  
  root = avlAdd(root,&Node50);
  root = avlAdd(root,&Node1);
  root = avlAdd(root,&Node75);
  
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,&Node75,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node75);
}

void test_avlRemove_fail_to_remove_and_return_NULL_if_root_is_NULL(){
  Node *root = NULL;
  Node *removedNode;
  removedNode = avlRemove(&root,&Node1);
  TEST_ASSERT_EQUAL_PTR(NULL,removedNode);
}

/*
 *    (root) -> (1)  => (root) -> empty
 */

void test_avlGetReplacer_should_return_the_replace_node_from_1_node(){
  Node *root = NULL;
  root = avlAdd(root, &Node1);
  Node *replacedNode;
  replacedNode = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL_PTR(&Node1,replacedNode);
  TEST_ASSERT_EQUAL_PTR(NULL,root);
}

/*
 *    (root) -> (1) ->(50)  => (root) -> (1) -> empty
 */

void test_avlGetReplacer_should_return_the_replace_node_from_2_node(){
  Node *root = NULL; Node *replacedNode;
  root = avlAdd(root, &Node1);
  root = avlAdd(root, &Node50);
  TEST_ASSERT_EQUAL_PTR(&Node50,Node1.rightChild);
  
  // printf("%p\n", &Node1);
  // printf("%p\n---------\n", &Node50);
  replacedNode = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL_PTR(&Node50,replacedNode);
  TEST_ASSERT_EQUAL_PTR(&Node1,root);
  TEST_ASSERT_EQUAL_INT(0, Node1.balance);
  TEST_ASSERT_NULL(Node1.rightChild);
}

/*    (root)        (root)
 *       |             |
 *      (50)     =>   (1)
 *      /
 *    (1)
 */

void test_avlGetReplacer_should_return_the_replace_node_from_50_1(){
  Node *root = NULL; Node *replacedNode;
  root = avlAdd(root, &Node50);
  root = avlAdd(root, &Node1);
  TEST_ASSERT_EQUAL_PTR(&Node1,Node50.leftChild);
  TEST_ASSERT_EQUAL_INT(-1,Node50.balance);
  
  // printf("%p\n", &Node1);
  // printf("%p\n---------\n", &Node50);
  replacedNode = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL_PTR(&Node50,replacedNode);
  TEST_ASSERT_EQUAL_PTR(&Node1,root);
  TEST_ASSERT_EQUAL_INT(0, Node1.balance);
  TEST_ASSERT_NULL(Node1.rightChild);
  TEST_ASSERT_NULL(Node1.leftChild);
}











