#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
  while (list_size(list) > 0)
    {
      if (list_rem_next(list, NULL) == 0 && list->destory != NULL)
      {
      list_destory(data);
      }
    }
  memset(list, 0, sizeof(List));
}


int list_ins_next(List *list, ListElmt *element, const void *data)
{
  ListElmt * new_listelmt;
  new_listelmt = (ListElmt *)malloc(sizeof(ListElmt));
  if (new_listelmt == NULL)
    return -1;
  new_listelmt->data = (void *)data;
  if (element == NULL)
    {
      if (list_size(list) == 0)
        list->tail = new_listelmt;
      new_listelmt->next = list->head;
      list->head = new_listelmt;
    }
  else
    {
      if (element->next == NULL)
        list->tail = new_listelmt;
      new_listelmt->next = element->next;
      element->next = new_listelmt;
    }
  list->size++;
  return 0;
}

int list_rem_next(List *list, ListElmt *element)
{
  ListElmt* old_listelmt;
  if (list->size == 0)
    return -1;
  if (element == NULL)
    {
      old_listelmt = list->head;
      list->head = list->head->next;

      if (list_size(list) == 1)
        list->tail = NULL;
    }
  else
    {
      if (element->next = NULL)
        return -1;
      old_listelmt = element->next;
      element->next = element->next->next;
    }
  free(old_listelmt);
  list->size--;
  return 0;
}

