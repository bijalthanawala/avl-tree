/*******************************************************
 * 
 * Project: avl-tree
 *
 * Description:  Generic implementation of AVL tree
 *
 *******************************************************/


#ifndef AVL_TREE_INCLUDED
#define AVL_TREE_INCLUDED

#include <stdint.h>

#define BOOL int16_t
#define TRUE  ((BOOL)1)
#define FALSE ((BOOL)0)

#define NUMBER_CHILD_BINARY_TREE 2
#define LCHILD 0
#define RCHILD 1


#define TREE_NODE_FLAG_ROOT    0x0001
#define TREE_NODE_FLAG_LCHILD  0x0002
#define TREE_NODE_FLAG_RCHILD  0x0004

#define SET_ROOT(ptreenode) { \
                             ptreenode->flags |= TREE_NODE_FLAG_ROOT; \
                           }

#define SET_LCHILD(ptreenode) { \
                               ptreenode->flags |= TREE_NODE_FLAG_LCHILD; \
                             }

#define SET_RCHILD(ptreenode) { \
                               ptreenode->flags |= TREE_NODE_FLAG_RCHILD; \
                             }

#define IS_ROOT(ptreenode)        (ptreenode->flags & TREE_NODE_FLAG_ROOT)
#define IS_THIS_LCHILD(ptreenode) (ptreenode->flags & TREE_NODE_FLAG_LCHILD)
#define IS_THIS_RCHILD(ptreenode) (ptreenode->flags & TREE_NODE_FLAG_RCHILD)
#define HAS_LCHILD(ptreenode)     (!(ptreenode->pchild[LCHILD] == NULL)
#define HAS_RCHILD(ptreenode)     (!(ptreenode->pchild[RCHILD]) == NULL)
#define GET_LCHILD(ptreenode)     (ptreenode->pchild[LCHILD])
#define GET_RCHILD(ptreenode)     (ptreenode->pchild[RCHILD])



typedef struct treenode {
    void *pdata;
    uint32_t height;
    struct treenode *pparent;
    uint16_t flags;
    struct treenode *pchild[NUMBER_CHILD_BINARY_TREE];    
    uint32_t child_height[NUMBER_CHILD_BINARY_TREE];
} TREENODE, *PTREENODE;


typedef enum {
    CMP_RESULT_UNKNOWN,
    CMP_RESULT_A_B_SAME,
    CMP_RESULT_A_LARGER,
    CMP_RESULT_A_SMALLER
} CMP_RESULT;


typedef CMP_RESULT (*PFNTREEDATACMP)(void *pdata_a, void *pdata_b);
typedef BOOL (*PFNTREEDATADEL)(void *pdata);


#define TREE_ATTRIB_IGNORE_DUP  0x0001

typedef struct tree {
    PTREENODE proot;
    uint32_t count;
    uint32_t attrib;
    PFNTREEDATACMP pfncmp;
    PFNTREEDATADEL pfndel;
} TREE, *PTREE;



PTREE tree_init(uint16_t attributes, 
                PFNTREEDATACMP pfncmp, 
                PFNTREEDATADEL pfndel);
void tree_destroy(PTREE ptree);
BOOL tree_insert(PTREE ptree, void *pdata);
int32_t tree_height(PTREE ptree);


#endif
