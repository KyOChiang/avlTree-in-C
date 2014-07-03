#include "unity.h"
#include "AVL.h"
#include "Rotation.h"
#include "CustomAssert.h"

Node Node1, Node25, Node40, Node50, Node90, Node100, Node75, Node65, Node150, Node175, Node200, Node220, Node120, Node110, \
Node130, Node250, Node140, Node105, Node500,  Node550,  Node450,  Node600,  Node400,  Node350,  Node330,  Node300,  Node270;

void initNode(Node *node, int nodeData){
  node->balance = 0;
  node->data = nodeData;
  node->leftChild = NULL;
  node->rightChild = NULL;
}

void setUp(){
initNode(&Node1,1);     initNode(&Node25,25);     initNode(&Node40,40);
initNode(&Node50,50);   initNode(&Node100,100);   initNode(&Node90,90);
initNode(&Node75,75);   initNode(&Node65,65);     initNode(&Node150,150);
initNode(&Node175,175); initNode(&Node200,200);   initNode(&Node220,220);
initNode(&Node120,120); initNode(&Node110,110);   initNode(&Node130,130); 
initNode(&Node250,250); initNode(&Node140,140);   initNode(&Node105,105);
initNode(&Node300,300); initNode(&Node330,330);   initNode(&Node350,350);
initNode(&Node270,270); initNode(&Node400,400);   initNode(&Node450,450);
initNode(&Node500,500); initNode(&Node550,550);   initNode(&Node600,600);
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

  replacedNode = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL_PTR(&Node50,replacedNode);
  TEST_ASSERT_EQUAL_PTR(&Node1,root);
  TEST_ASSERT_EQUAL_INT(0, Node1.balance);
  TEST_ASSERT_NULL(Node1.rightChild);
  TEST_ASSERT_NULL(Node1.leftChild);
}

/**
 *      50             50
 *     /  \     =>    /
 *   25   150       25
 *
 * where 150 is being removed
 */

void test_avlGetReplacer_should_return_the_replace_node150_from_25_50_150(){
  Node *root = NULL; Node *replacedNode;
  root = avlAdd(root, &Node25);
  root = avlAdd(root, &Node50);
  root = avlAdd(root, &Node150);

  replacedNode = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL_AVL_Node(&Node25,NULL,-1,&Node50);
  TEST_ASSERT_EQUAL_PTR(&Node150,replacedNode);
}

 /**
 *      50             50
 *     /  \     =>    /  \
 *   25   200       25   150
 *        /
 *      150
 *
 * where 200 is being removed
 */
 
void test_avlGetReplacer_should_return_the_replace_node200_from_25_50_200_150(){
  Node *root = NULL; Node *replacedNode;
  root = avlAdd(root, &Node25);
  root = avlAdd(root, &Node50);
  root = avlAdd(root, &Node200);
  root = avlAdd(root, &Node150);

  replacedNode = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node150,0,&Node50);
  TEST_ASSERT_EQUAL_PTR(&Node200,replacedNode);
}

/**
 *      50             50
 *     /  \     =>    /  \
 *   25   200       25   200
 *        / \            /
 *      150 220        150
 * 
 * where 220 is being removed
 */
 
void test_avlGetReplacer_should_return_the_replace_node220_from_25_50_200_150_220(){
  Node *root = NULL; Node *replacedNode;
  root = avlAdd(root, &Node25);
  root = avlAdd(root, &Node50);
  root = avlAdd(root, &Node200);
  root = avlAdd(root, &Node150);
  root = avlAdd(root, &Node220);

  replacedNode = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node200,1,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(&Node150,NULL,-1,&Node200);
  TEST_ASSERT_EQUAL_PTR(&Node220,replacedNode);
}

/**
 *      50
 *        \     =>    50
 *        200
 *
 * where 200 is being removed
 */

 void test_avlGetReplacer_should_return_the_replace_node200_from_50_200(){
  Node *root = NULL; Node *replacedNode;
  root = avlAdd(root, &Node50);
  root = avlAdd(root, &Node200);

  replacedNode = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node50);
}

/**
 *        50                  50
 *      /   \               /   \
 *     25   200           25    200
 *    /    /  \    =>    /     /  \
 *   1   150  250       1    150  220
 *            /
 *          220
 * 
 * where 250 is being removed 1 1 -1 -> 0 0 0
 */
 
void test_avlGetReplacer_should_return_the_replace_node250_from_1_25_50_200_150_250_220(){
  Node *root = NULL; Node *replacedNode;
  root = avlAdd(root, &Node25);
  root = avlAdd(root, &Node50);
  root = avlAdd(root, &Node200);
  root = avlAdd(root, &Node150);
  root = avlAdd(root, &Node250);
  root = avlAdd(root, &Node220);
  root = avlAdd(root, &Node1);
  
  /*printf("1 : %p\n", &Node1);
  printf("25 : %p\n", &Node25);
  printf("50 : %p\n", &Node50);
  printf("150 : %p\n", &Node150);
  printf("200 : %p\n", &Node200);
  printf("220 : %p\n", &Node220);
  printf("250 : %p\n", &Node250);*/
  
  root = rightRotate(root);
  
  /*TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node200,1,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,NULL,-1,&Node25);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node150);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node220);
  TEST_ASSERT_EQUAL_AVL_Node(&Node150,&Node250,1,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(&Node220,NULL,-1,&Node250);*/

  replacedNode = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node200,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(&Node150,&Node220,0,&Node200);
  TEST_ASSERT_EQUAL_PTR(&Node250,replacedNode);
}

/**
 *        50                 50            25
 *      /   \               /            /   \
 *     25   150    =>     25       =>   1    50
 *    /                  /
 *   1                  1
 *
 * where 150 is being removed
 */

void test_avlGetReplacer_should_return_the_replace_node150_from_1_25_50_150(){
  Node *root = NULL; Node *replacedNode;
  root = avlAdd(root, &Node25);
  root = avlAdd(root, &Node50);
  root = avlAdd(root, &Node150);
  root = avlAdd(root, &Node1);
  
  /*printf("1 : %p\n", &Node1);
  printf("25 : %p\n", &Node25);
  printf("50 : %p\n", &Node50);
  printf("150 : %p\n", &Node150);*/
 
  replacedNode = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,&Node50,0,&Node25);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node50);
  TEST_ASSERT_EQUAL_PTR(&Node150,replacedNode);
}
 
/**
 *        100                  100                50
 *      /    \               /    \             /    \
 *     25    150           25     150         25     100
 *    /  \     \    =>    /  \          =>   /  \    /  \
 *   1   50    200       1   50             1   40  75  150
 *      /  \                /  \
 *     40  75              40  75
 *
 * where 200 is being removed
 */
 
void test_avlGetReplacer_should_return_the_replace_node200_from_1_25_50_40_75_200_150_100(){
  Node *root = NULL; Node *replacedNode;
  root = avlAdd(root, &Node25);
  root = avlAdd(root, &Node100);
  root = avlAdd(root, &Node150);
  root = avlAdd(root, &Node200);
  root = avlAdd(root, &Node1);
  root = avlAdd(root, &Node50);
  root = avlAdd(root, &Node40);
  root = avlAdd(root, &Node75);
  
  /*TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node150,-1,&Node100);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,&Node50,1,&Node25);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node200,1,&Node150);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node75);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node40);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(&Node40,&Node75,0,&Node50);*/

  replacedNode = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node100,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(&Node75,&Node150,0,&Node100);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,&Node40,0,&Node25);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node40);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node75);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node150);
  TEST_ASSERT_EQUAL_PTR(&Node200,replacedNode);
}

/**
 *        100                  100                50
 *      /    \               /    \             /    \
 *     25    150           25     150         25     100
 *    /  \     \    =>    /  \          =>   /       /  \
 *   1   50    200       1   50             1      75  150
 *         \                   \
 *         75                  75
 *
 * where 200 is being removed
 */

void test_avlGetReplacer_should_return_the_replace_node200_from_1_25_50_75_200_150_100(){
  Node *root = NULL; Node *replacedNode;
  root = avlAdd(root, &Node25);
  root = avlAdd(root, &Node100);
  root = avlAdd(root, &Node150);
  root = avlAdd(root, &Node50);
  root = avlAdd(root, &Node1);
  root = avlAdd(root, &Node75);
  root = avlAdd(root, &Node200);
  
  /*printf("1 : %p\n", &Node1);
  printf("25 : %p\n", &Node25);
  printf("50 : %p\n", &Node50);
  printf("75 : %p\n", &Node75);
  printf("100 : %p\n", &Node100);
  printf("150 : %p\n", &Node150);
  printf("200 : %p\n", &Node200);*/
  
  root = leftRotate(root);
  root->leftChild = rightRotate(root->leftChild);
  
  /*TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node150,-1,&Node100);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,&Node50,1,&Node25);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node200,1,&Node150);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node75);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node75,1,&Node50);*/
  

  replacedNode = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node100,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(&Node75,&Node150,0,&Node100);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,NULL,-1,&Node25);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node75);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node150);
  TEST_ASSERT_EQUAL_PTR(&Node200,replacedNode);
}
 
/**
 *        100                  100                50
 *      /    \               /    \             /    \
 *     25    150           25     150         25     100
 *    /  \     \    =>    /  \          =>   /  \       \
 *   1   50    200       1   50             1   40      150
 *      /                   /
 *     40                  40
 *
 * where 200 is being removed
 */
 
void test_avlGetReplacer_should_return_the_replace_node200_from_1_25_50_40_200_150_100(){
  Node *root = NULL; Node *replacedNode;
  root = &Node100;
  root->leftChild = &Node25;
  root->rightChild = &Node150;
  Node150.rightChild = &Node200;
  Node25.leftChild = &Node1;
  Node50.leftChild = &Node40;
  Node25.rightChild = &Node50;
  
  Node100.balance = -1;
  Node25.balance = 1;
  Node150.balance =1 ;
  Node50.balance = -1;
  
  replacedNode = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node100,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node150,1,&Node100);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,&Node40,0,&Node25);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node40);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node150);
  TEST_ASSERT_EQUAL_PTR(&Node200,replacedNode);
}

/**
 *        100                  100                40
 *      /    \               /    \             /    \
 *     40    150           40     150         25     100
 *    /  \     \    =>    /  \          =>   /       /  \
 *   25  75   200        25  75             1      75   150
 *  /    /              /    /                    /
 * 1    50             1    50                  50
 *
 * where 200 is being removed
 */

void test_avlGetReplacer_should_return_the_replace_node200_from_1_25_50_40_75_100_200_150(){
  Node *root = NULL; Node *replacedNode;
  root = &Node100;
  root->leftChild = &Node40;
  root->rightChild = &Node150;
  Node150.rightChild = &Node200;
  Node40.leftChild = &Node25;
  Node40.rightChild = &Node75;
  Node25.leftChild = &Node1;
  Node75.leftChild = &Node50;
  
  Node100.balance = -1;
  Node25.balance = -1;
  Node150.balance = 1 ;
  Node75.balance = -1;
  
  replacedNode = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node100,1,&Node40);
  TEST_ASSERT_EQUAL_AVL_Node(&Node75,&Node150,-1,&Node100);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,NULL,-1,&Node25);
  TEST_ASSERT_EQUAL_AVL_Node(&Node50,NULL,-1,&Node75);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node150);
  TEST_ASSERT_EQUAL_PTR(&Node200,replacedNode);
}
 
////////////////////////////////////////////////////////////
// Test avlRemove() on deletion of node on the left subtree
////////////////////////////////////////////////////////////
/**
 *      50  => NULL
 *
 * where 50 is being removed 
 */
 
void test_avlRemove_should_remove_node50_and_return(){
  Node *root = NULL, *removedNode;
  root = avlAdd(root,&Node50);
  
  removedNode = avlRemove(&root, &Node50);
  TEST_ASSERT_NULL(root);
  TEST_ASSERT_EQUAL_PTR(&Node50,removedNode);
}

/**
 *        50                 50
 *      /   \               /  \
 *     25   150    =>     25   150
 *             \                  \
 *             200                200
 *
 * Attempt to remove 1, which cannot be found in the tree.
 */
 
void test_avlRemove_should_remove_nothing_and_return_node1(){
  Node *root = NULL, *removedNode;
  root = avlAdd(root,&Node25);
  root = avlAdd(root,&Node50);
  root = avlAdd(root,&Node150);
  root = avlAdd(root,&Node200);
  
  removedNode = avlRemove(&root, &Node1);
  TEST_ASSERT_NULL(removedNode);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node25);
  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node150,1,&Node50);
}

/**
 *      50             50
 *     /  \     =>       \
 *   25   150            150
 *
 * where 25 is being removed
 */
 
void test_avlRemove_should_remove_node25_and_return_node25(){
  Node *root = NULL, *removedNode;
  root = avlAdd(root,&Node25);
  root = avlAdd(root,&Node50);
  root = avlAdd(root,&Node150);
  
  removedNode = avlRemove(&root, &Node25);
  TEST_ASSERT_EQUAL_PTR(&Node25,removedNode);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node150,1,&Node50);
}

/**
 *        50                 150
 *      /   \               /  \
 *     25   150    =>     50   200
 *             \
 *             200
 *
 * where 25 is being removed
 */
 
void test_avlRemove_should_remove_node25_and_return_node25_from_25_50_150_200(){
  Node *root = NULL, *removedNode;
  root = avlAdd(root,&Node25);
  root = avlAdd(root,&Node50);
  root = avlAdd(root,&Node150);
  root = avlAdd(root,&Node200);

  removedNode = avlRemove(&root, &Node25);
  TEST_ASSERT_EQUAL_PTR(&Node25,removedNode);
  TEST_ASSERT_EQUAL_AVL_Node(&Node50,&Node200,0,&Node150);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node200);
}

/**
 *        50                 50
 *      /   \               /  \
 *    25    150    =>     1    150
 *    /       \                  \
 *   1       200                 200
 *
 * where 25 is being removed
 */

void test_avlRemove_should_remove_node25_and_return_node25_from_1_25_50_150_200(){
  Node *root = NULL, *removedNode;
  root = &Node50;
  Node50.leftChild = &Node25;
  Node25.leftChild = &Node1;
  Node50.rightChild = &Node150;
  Node150.rightChild = &Node200;
  Node25.balance = -1;
  Node150.balance = 1;
  
  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node150,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,NULL,-1,&Node25);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node200,1,&Node150);
  
  removedNode = avlRemove(&root, &Node25);
  TEST_ASSERT_EQUAL_PTR(&Node25,removedNode);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node200,1,&Node150);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,&Node150,1,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
}

/**
 *        100                  100                    150
 *      /    \               /    \                 /    \
 *    25     200           25     200             100     200
 *    /     /  \    =>            /  \     =>    /  \     /  \
 *   1    150  220              150  220        25  120 175  220
 *       /  \                  /  \
 *     120  175              120  175
 *
 * where 1 is being removed
 */
 
void test_avlRemove_should_remove_node1_and_return_node1_from_1_25_100_150_200_220_120_175(){
  Node *root = NULL, *removedNode;
  root = &Node100;
  Node100.leftChild = &Node25;
  Node100.rightChild = &Node200;
  Node25.leftChild = &Node1;
  Node200.rightChild = &Node220;
  Node200.leftChild = &Node150;
  Node150.rightChild = &Node175;
  Node150.leftChild = &Node120;
  Node25.balance = -1;
  Node100.balance = 1;
  Node200.balance = -1;
  
  removedNode = avlRemove(&root, &Node1);
  TEST_ASSERT_EQUAL_PTR(&Node1,removedNode);
  TEST_ASSERT_EQUAL_AVL_Node(&Node100,&Node200,0,&Node150);
  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node120,0,&Node100);
  TEST_ASSERT_EQUAL_AVL_Node(&Node175,&Node220,0,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node220);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node120);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node175);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node25);
}

/**
 *        100                  100                    150
 *      /    \               /    \                 /    \
 *    25     200           25     200             100     200
 *    /     /  \    =>            /  \     =>    /  \       \
 *   1    150  220              150  220        25  120     220
 *       /                     /
 *     120                   120
 *
 * where 1 is being removed
 */

void test_avlRemove_should_remove_node1_and_return_node1_from_1_25_100_150_200_220_120(){
  Node *root = NULL, *removedNode;
  root = &Node100;
  Node100.leftChild = &Node25;
  Node100.rightChild = &Node200;
  Node25.leftChild = &Node1;
  Node200.rightChild = &Node220;
  Node200.leftChild = &Node150;
  Node150.leftChild = &Node120;
  Node25.balance = -1;
  Node100.balance = 1;
  Node150.balance = -1;
  Node200.balance = -1;
  
  removedNode = avlRemove(&root, &Node1);
  TEST_ASSERT_EQUAL_PTR(&Node1,removedNode);
  TEST_ASSERT_EQUAL_AVL_Node(&Node100,&Node200,0,&Node150);
  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node120,0,&Node100);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node220,1,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node220);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node120);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node25);
}
 
/**
 *        100                  100                    150
 *      /    \               /    \                 /    \
 *    25     200           25     200             100     200
 *    /     /  \    =>            /  \     =>    /        /  \
 *   1    150  220              150  220        25      175  220
 *          \                     \
 *          175                   175
 *
 * where 1 is being removed
 */

void test_avlRemove_should_remove_node1_and_return_node1_from_1_25_100_150_200_220_175(){
  Node *root = NULL, *removedNode;
  root = &Node100;
  Node100.leftChild = &Node25;
  Node100.rightChild = &Node200;
  Node25.leftChild = &Node1;
  Node200.rightChild = &Node220;
  Node200.leftChild = &Node150;
  Node150.rightChild = &Node175;
  Node25.balance = -1;
  Node100.balance = 1;
  Node150.balance = 1;
  Node200.balance = -1;
  
  removedNode = avlRemove(&root, &Node1);
  TEST_ASSERT_EQUAL_PTR(&Node1,removedNode);
  TEST_ASSERT_EQUAL_AVL_Node(&Node100,&Node200,0,&Node150);
  TEST_ASSERT_EQUAL_AVL_Node(&Node25,NULL,-1,&Node100);
  TEST_ASSERT_EQUAL_AVL_Node(&Node175,&Node220,0,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node220);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node175);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node25);
} 

/**
 *        100                  100                    200
 *      /    \               /    \                 /    \
 *    25     200           25     200             100     220
 *    /     /  \    =>            /  \     =>    /  \       \
 *   1    150  220              150  220        25  150     250
 *          \    \                \    \              \
 *          175  250              175  250            175
 *
 * where 1 is being removed
 */

void test_avlRemove_should_remove_node1_and_return_node1_from_1_25_100_150_200_220_175_250(){
  Node *root = NULL, *removedNode;
  root = &Node100;
  Node100.leftChild = &Node25;
  Node100.rightChild = &Node200;
  Node25.leftChild = &Node1;
  Node200.rightChild = &Node220;
  Node220.rightChild = &Node250;
  Node200.leftChild = &Node150;
  Node150.rightChild = &Node175;
  Node25.balance = -1;
  Node100.balance = 1;
  Node150.balance = 1;
  Node220.balance = 1;
  
  removedNode = avlRemove(&root, &Node1);
  TEST_ASSERT_EQUAL_PTR(&Node1,removedNode);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node175,1,&Node150);
  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node150,1,&Node100);
  TEST_ASSERT_EQUAL_AVL_Node(&Node100,&Node220,-1,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node250,1,&Node220);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node250);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node175);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node25);
} 
 
/**
 *      50             50
 *     /  \     =>    /  \
 *   25   200       40   200
 *    \
 *    40
 *
 * where 25 is being removed
 */

void test_avlRemove_should_remove_node25_and_return_node25_from_25_40_50_200(){
  Node *root = NULL, *removedNode;
  root = avlAdd(root,&Node25);
  root = avlAdd(root,&Node50);
  root = avlAdd(root,&Node200);
  root = avlAdd(root,&Node40);

  removedNode = avlRemove(&root, &Node25);
  TEST_ASSERT_EQUAL_PTR(&Node25,removedNode);
  TEST_ASSERT_EQUAL_AVL_Node(&Node40,&Node200,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node40);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node200);
}
 
/**
 *       50             50
 *      /  \     =>    /  \
 *    25   200        1   200
 *   / \               \
 *  1  40              40
 *
 * where 25 is being removed
 */

void test_avlRemove_should_remove_node25_and_return_node25_from_1_25_40_50_200(){
  Node *root = NULL, *removedNode;
  root = avlAdd(root,&Node25);
  root = avlAdd(root,&Node50);
  root = avlAdd(root,&Node200);
  root = avlAdd(root,&Node40);
  root = avlAdd(root,&Node1);

  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node200,-1,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,&Node40,0,&Node25);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node40);
  removedNode = avlRemove(&root, &Node25);
  TEST_ASSERT_EQUAL_PTR(&Node25,removedNode);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,&Node200,-1,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node40,1,&Node1);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node40);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node200);
}
 
 /**
 *      150              90
 *     /  \             /  \
 *   25   200    =>   25   200
 *  / \     \        / \     \
 * 1   50   250     1   50   250
 *       \
 *       90
 *
 * where 150 is being removed
 */

void test_avlRemove_should_remove_node150_and_return_node150_from_1_25_50_90_150_200_250(){
  Node *root = NULL, *removedNode;
  root = &Node150;
  Node150.leftChild = &Node25;
  Node25.leftChild = &Node1;
  Node150.rightChild = &Node200;
  Node25.rightChild = &Node50;
  Node50.rightChild = &Node90;
  Node200.rightChild = &Node250;
  Node150.balance = -1;
  Node25.balance = 1;
  Node50.balance = 1;
  Node200.balance = 1;
  
  /*printf("\nABC\n");
  printf("%d %d %d %d %d\n",Node25.balance,Node50.balance,Node200.balance,Node40.balance,Node1.balance);
  printf("Node 40 : %p\n", &Node40);
  printf("Node 25 : %p\n", &Node25);
  printf("Node 1 : %p\n", &Node1);*/
  
  removedNode = avlRemove(&root, &Node150);
  TEST_ASSERT_EQUAL_PTR(&Node150,removedNode);
  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node200,0,&Node90);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,&Node50,0,&Node25);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node40);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node250);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node250,1,&Node200);
}
 
/**
 *      150              90
 *     /  \             /  \
 *   25   200    =>   25   200
 *  / \     \        / \     \
 * 1   50   250     1   50   250
 *    /  \              /
 *   40  90            40
 *
 * where 150 is being removed
 */

/////////////////////////////////////////////////////////////
// Test avlRemove() on deletion of node on the right subtree
/////////////////////////////////////////////////////////////
/**
 *        50                 50
 *      /   \               /  \
 *     25   150    =>     25   150
 *    /                  /
 *   1                  1
 *
 * Attempt to remove 200, which cannot be found in the tree.
 */

void test_avlRemove_should_return_NULL_if_remove_node_not_found_in_tree(){
  Node *root = NULL, *removedNode;
  root = avlAdd(root,&Node25);
  root = avlAdd(root,&Node50);
  root = avlAdd(root,&Node150);
  root = avlAdd(root,&Node1);
  
  removedNode = avlRemove(&root,&Node200);
  
  TEST_ASSERT_NULL(removedNode);
  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node150,-1,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,NULL,-1,&Node25);
}

/**
 *      50             50
 *     /  \     =>    /
 *   25   150       25
 *
 * where 150 is being removed
 */
 
void test_avlRemove_should_return_Node150_from_25_50_150(){
  Node *root = NULL, *removedNode;
  root = avlAdd(root,&Node25);
  root = avlAdd(root,&Node50);
  root = avlAdd(root,&Node150);
  
  removedNode = avlRemove(&root,&Node150);
  TEST_ASSERT_EQUAL_PTR(removedNode,&Node150);
  TEST_ASSERT_EQUAL_AVL_Node(&Node25,NULL,-1,&Node50);
}

/**
 *        50                 50            25
 *      /   \               /            /   \
 *     25   150    =>     25       =>   1    50
 *    /                  /
 *   1                  1
 *
 * where 150 is being removed
 */
 
void test_avlRemove_should_return_Node150_from_1_25_50_150(){
  Node *root = NULL, *removedNode;
  root = avlAdd(root,&Node25);
  root = avlAdd(root,&Node50);
  root = avlAdd(root,&Node150);
  root = avlAdd(root,&Node1);
  
  removedNode = avlRemove(&root,&Node150);
  TEST_ASSERT_EQUAL_PTR(removedNode,&Node150);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,&Node50,0,&Node25);
}

/**
 *        50                 50
 *      /   \               /  \
 *     25   150    =>     25   200
 *    /       \          /
 *   1       200        1
 *
 * where 150 is being removed
 */
 
void test_avlRemove_should_return_Node150_from_1_25_50_150_200(){
  Node *root = NULL, *removedNode;
  root = &Node50;
  Node50.leftChild = &Node25;
  Node50.rightChild = &Node150;
  Node25.leftChild = &Node1;
  Node150.rightChild = &Node200;
  Node150.balance = 1;
  Node25.balance = -1;
  
  removedNode = avlRemove(&root,&Node150);
  TEST_ASSERT_EQUAL_PTR(removedNode,&Node150);
  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node200,-1,&Node50);
}

/**
 *        100                  100                50
 *      /    \               /    \             /    \
 *     25    150           25     150         25     100
 *    /  \     \    =>    /  \          =>   /  \    /  \
 *   1   50    200       1   50             1   40  75  150
 *      /  \                /  \
 *     40  75              40  75
 *
 * where 200 is being removed
 */
 
void test_avlRemove_should_return_Node200_from_1_25_40_50_75_100_150_200(){
  Node *root = NULL, *removedNode;
  root = &Node100;
  Node100.leftChild = &Node25;
  Node100.rightChild = &Node150;
  Node25.leftChild = &Node1;
  Node25.rightChild = &Node50;
  Node50.leftChild = &Node40;
  Node50.rightChild = &Node75;
  Node150.rightChild = &Node200;
  Node100.balance = -1;
  Node150.balance = 1;
  Node25.balance = 1;
  
  removedNode = avlRemove(&root,&Node200);
  TEST_ASSERT_EQUAL_PTR(removedNode,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node100,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,&Node40,0,&Node25);
  TEST_ASSERT_EQUAL_AVL_Node(&Node75,&Node150,0,&Node100);
}

/**
 *        100                  100                50
 *      /    \               /    \             /    \
 *     25    150           25     150         25     100
 *    /  \     \    =>    /  \          =>   /       /  \
 *   1   50    200       1   50             1      75  150
 *         \                   \
 *         75                  75
 *
 * where 200 is being removed
 */
 
void test_avlRemove_should_return_Node200_from_1_25_50_75_100_150_200(){
  Node *root = NULL, *removedNode;
  root = &Node100;
  Node100.leftChild = &Node25;
  Node100.rightChild = &Node150;
  Node25.leftChild = &Node1;
  Node25.rightChild = &Node50;
  Node50.rightChild = &Node75;
  Node150.rightChild = &Node200;
  Node100.balance = -1;
  Node150.balance = 1;
  Node50.balance = 1;
  Node25.balance = 1;
  
  removedNode = avlRemove(&root,&Node200);
  TEST_ASSERT_EQUAL_PTR(removedNode,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node100,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,NULL,-1,&Node25);
  TEST_ASSERT_EQUAL_AVL_Node(&Node75,&Node150,0,&Node100);
}

/**
 *        100                  100                50
 *      /    \               /    \             /    \
 *     25    150           25     150         25     100
 *    /  \     \    =>    /  \          =>   /  \       \
 *   1   50    200       1   50             1   40      150
 *      /                   /
 *     40                  40
 *
 * where 200 is being removed
 */
 
void test_avlRemove_should_return_Node200_from_1_25_40_50_100_150_200(){
  Node *root = NULL, *removedNode;
  root = &Node100;
  Node100.leftChild = &Node25;
  Node100.rightChild = &Node150;
  Node25.leftChild = &Node1;
  Node25.rightChild = &Node50;
  Node50.leftChild = &Node40;
  Node150.rightChild = &Node200;
  Node100.balance = -1;
  Node150.balance = 1;
  Node50.balance = -1;
  Node25.balance = 1;
  
  removedNode = avlRemove(&root,&Node200);
  TEST_ASSERT_EQUAL_PTR(removedNode,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node100,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,&Node40,0,&Node25);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node150,1,&Node100);
}

/**
 *        100                  100                40
 *      /    \               /    \             /    \
 *     40    150           40     150         25     100
 *    /  \     \    =>    /  \          =>   /       /  \
 *   25  75   200        25  75             1      75   150
 *  /    /              /    /                    /
 * 1    50             1    50                  50
 *
 * where 200 is being removed
 */
 
void test_avlRemove_should_return_Node200_from_1_25_40_75_50_100_150_200(){
  Node *root = NULL, *removedNode;
  root = &Node100;
  Node100.leftChild = &Node40;
  Node100.rightChild = &Node150;
  Node40.leftChild = &Node25;
  Node40.rightChild = &Node75;
  Node25.leftChild = &Node1;
  Node75.leftChild = &Node50;
  Node150.rightChild = &Node200;
  Node100.balance = -1;
  Node150.balance = 1;
  Node75.balance = -1;
  Node25.balance = -1;
  
  removedNode = avlRemove(&root,&Node200);
  TEST_ASSERT_EQUAL_PTR(removedNode,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node100,1,&Node40);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,NULL,-1,&Node25);
  TEST_ASSERT_EQUAL_AVL_Node(&Node75,&Node150,-1,&Node100);
  TEST_ASSERT_EQUAL_AVL_Node(&Node50,NULL,-1,&Node75);
}

/**
 *      50             50
 *     /  \     =>    /  \
 *   25   200       25   150
 *        /
 *      150
 *
 * where 200 is being removed
 */
 
void test_avlRemove_should_return_Node200_from_25_50_200_150(){
  Node *root = NULL, *removedNode;
  root = &Node50;
  Node50.leftChild = &Node25;
  Node50.rightChild = &Node200;
  Node200.leftChild = &Node150;
  Node200.balance = -1;
  Node50.balance = 1;
  
  removedNode = avlRemove(&root,&Node200);
  TEST_ASSERT_EQUAL_PTR(removedNode,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node150,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node150);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node25);
}

/**
 *      50             50
 *     /  \     =>    /  \
 *   25   200       25   150
 *        / \              \
 *      150 220            220
 *
 * where 200 is being removed
 */

void test_avlRemove_should_return_Node200_from_25_50_200_150_220(){
  Node *root = NULL, *removedNode;
  root = &Node50;
  Node50.leftChild = &Node25;
  Node50.rightChild = &Node200;
  Node200.leftChild = &Node150;
  Node200.rightChild = &Node220;
  Node50.balance = 1;
  
  removedNode = avlRemove(&root,&Node200);
  TEST_ASSERT_EQUAL_PTR(removedNode,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node150,1,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node220,1,&Node150);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node25);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node220);
}
 
/**
 *      50               50
 *     /  \             /  \
 *   25   200    =>   25   175
 *  /     / \        /    /  \
 * 1    150 220     1   150  220
 *        \
 *        175
 *
 * where 200 is being removed
 */
 
void test_avlRemove_should_return_Node200_from_25_50_200_150_220_175(){
  Node *root = NULL, *removedNode;
  root = &Node50;
  Node50.leftChild = &Node25;
  Node50.rightChild = &Node200;
  Node200.leftChild = &Node150;
  Node200.rightChild = &Node220; 
  Node150.rightChild = &Node175;
  Node25.leftChild = &Node1;
  Node50.balance = 1;
  Node25.balance = -1;
  Node200.balance = -1;
  Node150.balance = 1;
  
  removedNode = avlRemove(&root,&Node200);
  TEST_ASSERT_EQUAL_PTR(removedNode,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node175,0,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(&Node150,&Node220,0,&Node175);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,NULL,-1,&Node25);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node220);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node150);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
}

/**
 *      50               50
 *     /  \             /  \
 *   25   200    =>   25   175
 *  /     / \        /    /  \
 * 1    150 220     1   150  220
 *      / \             /
 *    120 175         120
 * 
 * where 200 is being removed
 */

void test_avlRemove_should_return_Node200_from_25_50_200_150_220_120_175(){
  Node *root = NULL, *removedNode;
  root = &Node50;
  Node50.leftChild = &Node25;
  Node50.rightChild = &Node200;
  Node200.leftChild = &Node150;
  Node200.rightChild = &Node220;
  Node150.leftChild = &Node120;
  Node150.rightChild = &Node175;
  Node25.leftChild = &Node1;
  Node50.balance = 1;
  Node25.balance = -1;
  Node200.balance = -1;
  
  /*TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node200,1,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(&Node150,&Node220,-1,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(&Node120,&Node175,0,&Node150);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,NULL,-1,&Node25);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node120);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node175);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node220);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);*/
  removedNode = avlRemove(&root,&Node200);
  TEST_ASSERT_EQUAL_PTR(removedNode,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node175,1,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(&Node150,&Node220,-1,&Node175);
  TEST_ASSERT_EQUAL_AVL_Node(&Node1,NULL,-1,&Node25);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node220);
  TEST_ASSERT_EQUAL_AVL_Node(&Node120,NULL,-1,&Node150);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node1);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,NULL,0,&Node120);
}
 
/**
 *              175                                   175
 *          /          \                         /          \
 *        100          400                     100          350
 *       /   \       /     \                  /   \       /     \
 *     50    150   250     500       =>     50    150   250     500
 *    / \    /   /    \     / \            / \    /   /    \     / \
 *  25  65 120 200    300 450 550        25  65 120 200    300 450 550
 *   \          \     / \      \          \          \     / \      \
 *   40         220 270 350    600        40         220 270 330    600
 *                      /
 *                    330
 *
 * where 400 is being removed
 */

void test_avlRemove_should_return_Node200_from_20_Nodes_tree(){
  Node *root = NULL, *removedNode;
  root = &Node175;
  Node175.leftChild = &Node100;
  Node175.rightChild = &Node400;
  Node100.leftChild = &Node50;
  Node100.rightChild = &Node150;
  Node50.leftChild = &Node25;
  Node50.rightChild = &Node65;
  Node25.rightChild = &Node40;
  Node400.leftChild = &Node250;
  Node400.rightChild = &Node500;
  Node150.leftChild = &Node120;
  Node250.leftChild = &Node200;
  Node250.rightChild = &Node300;
  Node200.rightChild = &Node220;
  Node300.leftChild = &Node270;
  Node300.rightChild = &Node350;
  Node350.leftChild = &Node330;
  Node500.leftChild = &Node450;
  Node500.rightChild = &Node550;
  Node550.rightChild = &Node600;
  Node50.balance = -1;
  Node25.balance = 1;
  Node200.balance = 1;
  Node100.balance = -1;
  Node150.balance = -1;
  Node175.balance = 1;
  Node400.balance = -1;
  Node250.balance = 1;
  Node300.balance = 1;
  Node350.balance = -1;
  Node500.balance = 1;
  Node550.balance = 1;
  
  /*TEST_ASSERT_EQUAL_AVL_Node(&Node100,&Node400,1,&Node175);
  TEST_ASSERT_EQUAL_AVL_Node(&Node50,&Node150,-1,&Node100);
  TEST_ASSERT_EQUAL_AVL_Node(&Node250,&Node500,-1,&Node400);
  TEST_ASSERT_EQUAL_AVL_Node(&Node200,&Node300,1,&Node250);
  TEST_ASSERT_EQUAL_AVL_Node(&Node270,&Node350,1,&Node300);
  TEST_ASSERT_EQUAL_AVL_Node(&Node330,NULL,-1,&Node350);
  TEST_ASSERT_EQUAL_AVL_Node(&Node450,&Node550,1,&Node500);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node600,1,&Node550);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node220,1,&Node200);
  TEST_ASSERT_EQUAL_AVL_Node(&Node330,NULL,-1,&Node350);
  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node65,-1,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(&Node120,NULL,-1,&Node150);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node40,1,&Node25);*/
  
  removedNode = avlRemove(&root,&Node400);
  
  TEST_ASSERT_EQUAL_PTR(removedNode,&Node400);
  TEST_ASSERT_EQUAL_AVL_Node(&Node100,&Node350,0,&Node175);
  TEST_ASSERT_EQUAL_AVL_Node(&Node50,&Node150,-1,&Node100);
  TEST_ASSERT_EQUAL_AVL_Node(&Node25,&Node65,-1,&Node50);
  TEST_ASSERT_EQUAL_AVL_Node(&Node120,NULL,-1,&Node150);
  TEST_ASSERT_EQUAL_AVL_Node(&Node250,&Node500,0,&Node350);
  TEST_ASSERT_EQUAL_AVL_Node(&Node200,&Node300,0,&Node250);
  TEST_ASSERT_EQUAL_AVL_Node(&Node270,&Node330,0,&Node300);
  TEST_ASSERT_EQUAL_AVL_Node(&Node450,&Node550,1,&Node500);
  TEST_ASSERT_EQUAL_AVL_Node(NULL,&Node600,1,&Node550);
}








