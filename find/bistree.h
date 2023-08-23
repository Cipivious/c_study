#ifndef BISTREE_H
#define BISTREE_H

#include <stdio.h>
typedef struct Bistree_
{
  int key;
  struct Bistree_ *lchild;
  struct Bistree_ *rchild;
}Bistree, Node;

Node* bistree_create(int key);
void bistree_show_pre(Bistree* tree);
void bistree_show_mid(Bistree* tree);
Node* bistree_insert(Bistree* tree, int key);
Node* bistree_delete(Bistree* tree, int key);
Node* bistree_search(Bistree* tree, int key);

#endif
