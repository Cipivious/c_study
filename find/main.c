#include <stdio.h>
#include <stdlib.h>
#include "avltree.h"


int main()
{
  int arr[] = {7, 4, 1, 3, 4, 9, 6, 12, 5};
  int length = sizeof(arr) / sizeof(arr[0]);
  Avltree* tree = NULL;
  for (int i = 0; i < length; i++)
    {
      tree = avltree_insert(tree, arr[i]);
    }
  printf("\n先序遍历：\n");
  avltree_show_pre(tree);
  printf("\n中序遍历：\n");
  avltree_show_mid(tree);
  avltree_delete(tree, 4);
  printf("\n先序遍历：\n");
  avltree_show_pre(tree);
  printf("\n后序遍历：\n");
  avltree_show_mid(tree);

  int key = 6;
  Node* p = avltree_search(tree, key);
  if (p == NULL)
    printf("\n找不到%d\n", key);
  else
    {
      /*printf("\n找到%d\n", key);
        printf("\np->key = %d\n", p->key);*/
    }
  return 0;
}











/*typedef struct ST
{
  int data;
  int index;
}ST;

void arr_show(int arr[], int length);
int compare(const void *a, const void *b);
int forward_search(int arr[], int length, int key);
int sentinel_search(int arr[], int length, int key);
int avlnary_search(int arr[], int length, int key);
int avlnary_search2(int arr[], int left, int right, int key);
int block_search(int arr[], int length, ST *st, int len_st, int key);

int main()
{
  int arr[10] = {2, 2, 3, 4, 4, 5, 7, 8, 9, 19};
  int position;
  int key = 7;
  arr_show(arr, 10);
  qsort(arr, 10, sizeof(int), compare);
  arr_show(arr, 10);
  ST st[4] = {
    {4, 4},
    {9, 8},
    {19, 9}
  };
  position = block_search(arr, 10, st, 3, key);
  printf("the position of %d is : %d\n", key, position);
  position = sentinel_search(arr, 10, key);
  printf("the position of %d is : %d\n", key, position);
  position = avlnary_search(arr, 10, key);
  printf("the position of %d is : %d\n", key, position);
  position = avlnary_search2(arr, 0, 9, key);
  printf("the position of %d is : %d\n", key, position);

  return 0;
}

void arr_show(int arr[], int length)
{
  for (int i = 0; i < length; i++)
    {
      printf("%d ", arr[i]);
    }
  printf("\n");
  return;
}

int compare(const void *a, const void *b)
{
  return *(int*)a - *(int*)b;
}

int forward_search(int arr[], int length, int key)
{
  for(int i = 0; i < length; i++)
    {
      if (arr[i] == key)
        {
          return i;
        }
    }
  return -1;
}

int sentinel_search(int arr[], int length, int key)
{
  arr[0] = key;
  for (int i = length - 1; i >= 0; i--)
    {
      if (arr[i] == arr[0])
        {
          return i;
        }
    }
}

int avlnary_search(int arr[], int length, int key)
{
  int left = 0, right = length - 1, mid;
  while (left < right)
    {
      mid = left + (right - left) / 2;
      if (key < arr[mid]) right = mid - 1;
      else if (key > arr[mid]) left = mid + 1;
      else return mid;
    }
  return -1;
}

int avlnary_search2(int arr[], int left, int right, int key)
{
  if (left > right) return -1;
  int mid = left + (right - left) / 2;
  if (arr[mid] == key)
    return mid;
  else
    {
      if (arr[mid] < key)
        {
          return avlnary_search2(arr, mid + 1, right, key);
        }
      else
        {
          return avlnary_search2(arr, left, mid - 1, key);
        }
    }
  return -1;
}

int block_search(int arr[], int length, ST *st, int len_st, int key)
{
  int left = 0, right = len_st - 1, mid = left + (right - left) / 2;

  while (left < right)
    {
      if (st[mid].data > key)
        {
          if (st[mid - 1].data < key)
            {
              mid = mid - 1;
              break;
            }
          else
            {
              right = mid - 1;
            }
        }
      if (st[mid].data < key)
        {
          if (st[mid + 1].data > key)
            {
              break;
            }
          else
            {
              left = mid + 1;
            }
        }
      mid = left + (right - left) / 2;
    }
  int begin = st[mid].index;
  int end = st[mid + 1].index;
  for (int i = begin; i < end; i++)
    {
      if (arr[i] == key)
        {
          return i;
        }
    }
  return -1;
}*/
