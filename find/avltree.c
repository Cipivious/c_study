#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "avltree.h"

Node* avltree_create(int key)
{
  Node* newNode = (Avltree*)malloc(sizeof(Avltree));
  assert(newNode);
  newNode->key = key;
  newNode->lchild = NULL;
  newNode->rchild = NULL;
  newNode->height = 1;
  return newNode;
}

Node* avltree_LL_Rotation(Avltree* tree)
{
  if (tree == NULL || tree->lchild == NULL) {
    // Handle the case of invalid input
    return NULL; // You can customize this error handling as needed
  }
  Node* newRoot = tree->lchild;
  tree->lchild = newRoot->rchild;
  newRoot->rchild = tree;

  tree->height = Get_New_Height(tree);
  newRoot->height = Get_New_Height(newRoot);
  return newRoot;
}
Node* avltree_RR_Rotation(Avltree* tree)
{
  if (tree == NULL || tree->rchild == NULL) {
    // Handle the case of invalid input
    return NULL; // You can customize this error handling as needed
  }
  Node* newRoot = tree->rchild;
  tree->rchild = newRoot->lchild;
  newRoot->lchild = tree;

  tree->height = Get_New_Height(tree);
  newRoot->height = Get_New_Height(newRoot);
  return newRoot;
}
Node* avltree_LR_Rotation(Avltree* tree)
{
  if (tree == NULL || tree->lchild == NULL) {
    // Handle the case of invalid input
    return NULL; // You can customize this error handling as needed
  }
  tree->lchild = avltree_RR_Rotation(tree->lchild);
  return avltree_LL_Rotation(tree);
}
Node* avltree_RL_Rotation(Avltree* tree)
{
  if (tree == NULL || tree->lchild == NULL) {
    // Handle the case of invalid input
    return NULL; // You can customize this error handling as needed
  }
  tree->rchild = avltree_LL_Rotation(tree->rchild);
  return avltree_RR_Rotation(tree);
}
void avltree_show_pre(Avltree* tree)
{
  if (tree == NULL) return;
  printf("%d ", tree->key);
  avltree_show_pre(tree->lchild);
  avltree_show_pre(tree->rchild);
}
void avltree_show_mid(Avltree* tree)
{
  if (tree == NULL) return;
  avltree_show_mid(tree->lchild);
  printf("%d ", tree->key);
  avltree_show_mid(tree->rchild);
}
Node* avltree_insert(Node* node, int key)
{
    if (node == NULL)
      {
        return avltree_create(key);
      }

    if (key < node->key)
      {
        node->lchild = avltree_insert(node->lchild, key);
      }
    else if (key > node->key)
      {
        node->rchild = avltree_insert(node->rchild, key);
      }
    else
      {
        return node;
      }

    // Update height of current node
    node->height = 1 + Max(Height(node->lchild), Height(node->rchild));

    // Get balance factor
    int balance = Height(node->lchild) - Height(node->rchild);

    // Perform rotations if needed
    // Left Left Rotation (LL)
    if (balance > 1 && key < node->lchild->key) {
        return avltree_LL_Rotation(node);
    }

    // Right Right Rotation (RR)
    if (balance < -1 && key > node->rchild->key) {
        return avltree_RR_Rotation(node);
    }

    // Left Right Rotation (LR)
    if (balance > 1 && key > node->lchild->key) {
        return avltree_LR_Rotation(node);
    }

    // Right Left Rotation (RL)
    if (balance < -1 && key < node->rchild->key) {
        return avltree_RL_Rotation(node);
    }

    return node;
}


Node* avltree_delete(Avltree* tree, int key)
{
  if (tree == NULL)
    return NULL;  // The tree is empty, nothing to delete

  if (key < tree->key)
  {
    tree->lchild = avltree_delete(tree->lchild, key);
    // Perform balancing operations
  }
  else if (key > tree->key)
  {
    tree->rchild = avltree_delete(tree->rchild, key);
    // Perform balancing operations
  }
  else
  {
    // Node with the key to be deleted is found

    if (tree->lchild == NULL)
    {
      Node* temp = tree->rchild;
      free(tree);
      return temp;
    }
    else
    {
      Node* temp = tree->lchild;
      free(tree);
      return temp;
    }

    /* Node has two children
    Node* temp = avltree_find_min(tree->rchild);
    tree->key = temp->key;
    tree->rchild = avltree_delete(tree->rchild, temp->key);
    // Perform balancing operations*/
  }

  tree->height = Get_New_Height(tree); // Update the height
  // Perform balancing operations
  return tree;
}

Node* avltree_search(Avltree* tree, int key)
{
  if (tree == NULL || tree->key == key)
    return tree;

  if (key < tree->key)
    return avltree_search(tree->lchild, key);
  else
    return avltree_search(tree->rchild, key);
}
