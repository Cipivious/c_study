#ifndef AVLTREE_H
#define AVLTREE_H

#include <stdio.h>
typedef struct Avltree_
{
  int key;
  struct Avltree_ *lchild;
  struct Avltree_ *rchild;
  int height;
}Avltree, Node;
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Height(x) ((x == NULL) ? (-1) : (x->height))
#define Get_New_Height(x) (Max(Height(x->lchild), Height(x->rchild)) + 1)
Node* avltree_create(int key);
Node* avltree_LL_Rotation(Avltree* tree);
Node* avltree_LR_Rotation(Avltree* tree);
Node* avltree_RR_Rotation(Avltree* tree);
Node* avltree_RL_Rotation(Avltree* tree);
void avltree_show_pre(Avltree* tree);
void avltree_show_mid(Avltree* tree);
Node* avltree_insert(Avltree* tree, int key);
Node* avltree_delete(Avltree* tree, int key);
Node* avltree_search(Avltree* tree, int key);


#endif
