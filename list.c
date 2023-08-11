#include <stdlib.h>
#include <stdio.h>

#include "list.h"

/*list init*/
void list_init(List *list, void (*destory)(void *data))
{
  list->size = 0;
  list->destory = destory;
  list->head = NULL;
  list->tail = NULL;

  return;
}
/*list destory*/
void list_destory(List *list)
{
  void *data;
  /*remove each element*/
  while (list_size(list) > 0){
    if (list_rem_next(list, NULL, (void **)&data) == 0 && list->destory != NULL){
      list_destory(data);
    }
  }
}
