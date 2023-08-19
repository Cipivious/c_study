#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "bitree.h"

/*bitree init*/
void bitree_init(Bitree *bitree, void (*destroy)(void *data))
{
  bitree->size = 0;
  bitree->destroy = destroy;
  bitree->root = NULL;

  return;
}
/*bitree destroy*/
void bitree_destroy(Bitree *bitree)
{
  bitree_rem_left(bitree, NULL);
  memset(bitree, 0, sizeof(Bitree));
  return;
}


int bitree_ins_left(Bitree *bitree, BitreeNode *node, const void *data)
{
  BitreeNode * new_bitreenode, **position;

  if (node == NULL)
    {
      if (bitree_size(bitree) > 0)
        return -1;
      position = &bitree->root;
    }
  else
    {
      if (bitree_left(node) != NULL)
        return -1;

      position = &node->left;
    }
  new_bitreenode = (BitreeNode *)malloc(sizeof(BitreeNode));
  if (new_bitreenode == NULL)
    {
      return -1;
    }
  new_bitreenode->data = (void*)data;
  new_bitreenode->left = NULL;
  new_bitreenode->right = NULL;
  *position = new_bitreenode;
  bitree->size++;
  return 0;
}

int bitree_ins_right(Bitree *bitree, BitreeNode *node, const void *data)
{
  BitreeNode * new_bitreenode, **position;

  if (node == NULL)
    {
      if (bitree_size(bitree) > 0)
        return -1;
      position = &bitree->root;
    }
  else
    {
      if (bitree_right(node) != NULL)
        return -1;

      position = &node->right;
    }
  new_bitreenode = (BitreeNode *)malloc(sizeof(BitreeNode));
  if (new_bitreenode == NULL)
    {
      return -1;
    }
  new_bitreenode->data = (void*)data;
  new_bitreenode->left = NULL;
  new_bitreenode->right = NULL;
  *position = new_bitreenode;
  bitree->size++;
  return 0;
}

void bitree_rem(Bitree *bitree, BitreeNode *node)
{
  if (node != NULL)
  {
    if (bitree_left(node) != NULL)
      bitree_rem(bitree, bitree_left(node));
    if (bitree_right(node) != NULL)
      bitree_rem(bitree, bitree_right(node));

    if (bitree->destroy != NULL)
      bitree->destroy(bitree_data(node));

    free(node);
    bitree->size--;
  }
}

void bitree_rem_left(Bitree *bitree, BitreeNode *node)
{
  if (bitree_size(bitree) == 0)
    return;

  if (node == NULL)
    {
      bitree_rem(bitree, bitree_left(bitree_root(bitree)));
      bitree_left(bitree_root(bitree)) = NULL;
    }
  else
    {
      bitree_rem(bitree, bitree_left(node));
      bitree_left(node) = NULL;
    }

}

void bitree_rem_right(Bitree *bitree, BitreeNode *node)
{
  if (bitree_size(bitree) == 0)
    return;

  if (node == NULL)
    {
      bitree_rem(bitree, bitree_right(bitree_root(bitree)));
      bitree_right(bitree_root(bitree)) = NULL;
    }
  else
    {
      bitree_rem(bitree, bitree_right(node));
      bitree_right(node) = NULL;
    }
  
  return;
}

int bitree_merge(Bitree *merge, Bitree *left, Bitree *right, const void *data)
{
  bitree_init(merge, left->destroy);

  bitree_ins_left(merge, NULL, data);

  bitree_root(merge)->left = bitree_root(left);
  bitree_root(merge)->right = bitree_root(right);

  merge->size = merge->size + bitree_size(left) + bitree_size(right);

  left->root = NULL;
  left->size = 0;
  right->root = NULL;
  right->size = 0;

  return 0;
}
