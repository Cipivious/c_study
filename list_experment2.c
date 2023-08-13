#include <stdio.h>
#include "list.h"

int main()
{
  List * list;
  ListElmt *element;
  void **data;
  list_init(list, free);
  for (int i = 0; i < 10; ++i)
    {
      list_ins_next(list, list->head, &i);
    }
  element = list->head;
  for (int i = 0; i < 10; ++i)
    {
      printf("%p", element->data);
      element = element->next;
    }
  list_rem_next(list, list->head, data);
  list_destory(list);
  return 0;
}
