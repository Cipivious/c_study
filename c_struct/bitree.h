/* bitree */
#ifndef BITREE_H
#define BITREE_H

#include <stdlib.h>

typedef struct BitreeNode_
{
  void *data;
  struct BitreeNode_ *left;
  struct BitreeNode_ *right;
} BitreeNode;

typedef struct Bitree_ {
    int size;
    int (*compare)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    BitreeNode *root;
} Bitree;

/* Define a structure for binary trees */
void bitree_init(Bitree *bitree, void (*destroy)(void *data));
void bitree_destroy(Bitree *bitree);
int bitree_ins_left(Bitree *bitree, BitreeNode *node, const void *data);
int bitree_ins_right(Bitree *bitree, BitreeNode *node, const void *data);
void bitree_rem_left(Bitree *bitree, BitreeNode *node);
void bitree_rem_right(Bitree *bitree, BitreeNode *node);
int bitree_merge(Bitree *merge, Bitree *left, Bitree *right, const void *data);

#define bitree_size(tree) ((tree)->size)
#define bitree_root(tree) ((tree)->root)
#define bitree_is_eob(node) ((node) == NULL)
#define bitree_is_leaf(node) ((node)->left == NULL && (node)->right == NULL)
#define bitree_data(node) ((node)->data)
#define bitree_left(node) ((node)->left)
#define bitree_right(node) ((node)->right)

#endif
