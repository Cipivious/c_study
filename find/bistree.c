#include <stdio.h>
#include <stdlib.h>
#include "bistree.h"
#include <assert.h>

Node* bistree_create(int key)
{
  Node* newNode = (Node*)malloc(sizeof(Node));
  assert(newNode);
  newNode->key = key;
  newNode->lchild = NULL;
  newNode->rchild = NULL;
  return newNode;
}
void bistree_show_pre(Bistree* tree)
{
  if (tree == NULL)
    return;
  printf("%d ", tree->key);
  bistree_show_pre(tree->lchild);
  bistree_show_pre(tree->rchild);
}
void bistree_show_mid(Bistree* tree)
{
  if (tree == NULL)
    return;
  bistree_show_mid(tree->lchild);
  printf("%d ", tree->key);
  bistree_show_mid(tree->rchild);
}

Node* bistree_insert(Bistree* tree, int key)
{
  if (tree == NULL)
    return bistree_create(key);
  if (key < tree->key)
    {
      tree->lchild = bistree_insert(tree->lchild, key);
    }
  else
    {
      tree->rchild = bistree_insert(tree->rchild, key);
    }
  return tree;
}

Node* bistree_findmax(Bistree* tree)
{
  while(tree->rchild)
    tree = tree->rchild;
  return tree;
}

Node* bistree_delete(Bistree* tree, int key)
{
  if (tree == NULL)
    return NULL;
  if (key < tree->key)
    {
      tree->lchild = bistree_delete(tree->lchild, key);
    }
  else
    {
      if (key > tree->key)
        {
          tree->rchild = bistree_delete(tree->rchild, key);
        }
      else
        {
          if (tree->lchild && tree->rchild)
            {
              Node* maxNode = bistree_findmax(tree->lchild);
              tree->key = maxNode->key;
              tree->lchild = bistree_delete(tree->lchild, maxNode->key);
            }
          else
            {
              Node* temp = tree;
              tree = tree->lchild ? tree->lchild : tree->rchild;
              free(temp);
            }
        }
    }
  return tree;
}

Node* bistree_search(Bistree* tree, int key)
{
  if (tree == NULL)
    return NULL;
  if (key < tree->key)
    {
      return bistree_search(tree->lchild, key);
    }
  else if (key > tree->key)
    {
      return bistree_search(tree->rchild, key);
    }
  else
    {
      return tree;
    }
}
