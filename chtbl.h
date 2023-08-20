/* chtbl.h */
#ifndef CHTBL_H
#define CHTBL_H

#include <stdlib.h>

#include "list.h"

/*Implement chtbls as linked lists.*/
typedef struct Chtbl_
{
  int buckets;

  int (*h)(const void *key);
  int (*match)(const void *key1, const void *key2);
  void (*destroy)(void *data);

  int size;
  List *table;
}Chtbl;

/*Public Interface*/
int chtbl_init(Chtbl *htbl, int buckets, int (*h)(const void *key), int (*match)(const void *key1, const void *key2), void(*destroy)(void *data));

void chtbl_destroy(Chtbl *htbl);

int chtbl_insert(Chtbl *htbl, const void* data);

int chtbl_remove(Chtbl *htbl, void **data);

int chtbl_lookup(const Chtbl *htbl, void **data);
#define chtbl_size(htbl)((htbl)->size)

#endif
