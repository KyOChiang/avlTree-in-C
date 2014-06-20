#ifndef CustomAssert_H_
#define CustomAssert_H_

#define TEST_ASSERT_EQUAL_AVL_Node(expectedLeft, expectedRight, balance, actual)    \
                     assertAvlNode(expectedLeft, expectedRight, balance, actual,__LINE__);

#endif