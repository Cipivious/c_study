#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct ListElmt_
{
  int data;
  struct ListElmt_ *next;
}ListElmt;
typedef struct List_
{
  int size;
  ListElmt *head;
  ListElmt *tail;
};
void list_init(struct List *list);
void list_show(struct List *list);
bool list_is_empty(struct List *list);
bool list_is_full(struct List *list);
bool list_append(struct List *list, int val);
bool list_insert(struct List *list, int pos, int val);
bool list_delete(struct List *list, int pos);
bool list_delete_all(struct List *list);
void list_inversion(struct List *list);
void list_swap(struct List *list, int pos1, int pos2);
void list_sort(struct List *list);

int main(void)
{
  struct List list;
  list_init(&list, 6);
  list_show(&list);
  list_append(&list, 1);
  list_append(&list, 2);
  list_append(&list, 3);
  list_append(&list, 4);
  list_append(&list, 8);
  list_insert(&list, 2, 100);
  list_delete(&list, 1);
  list_show(&list);
  list_inversion(&list);
  //list_delete_all(&list);
  list_show(&list);
  list_sort(&list);
  list_show(&list);
  list_inversion(&list);
  list_show(&list);

  return 0;
}
void list_init(List *list, void (*destory)(void *data))
{
  list->size = 0;
  list->destory = destory;
  list->head = NULL;
  list->tail = NULL;

  return;
}

bool list_is_empty(struct List *list)
{
  if (list->cnt == 0)
    return true;
  else
    return false;
}

bool list_is_full(struct List *list)
{
  if (list->cnt == list->len)
    return true;
  else
    return false;
}
void list_show(struct List *list)
{
  if (list_is_empty(list))
    printf("数组为空\n");
  else
    {
      for(int i = 0; i < list->cnt; ++i)
        printf("%d\n", (list->pBase)[i]);
    }
  return;
}

bool list_append(struct List *list, int val)
{
  if (list_is_full(list))
    return false;
  else
    {
      list->pBase[list->cnt] = val;
      list->cnt++;
      return true;
    }
}
bool list_insert(struct List *list, int pos, int val)
{
  if (list_is_full(list))
    return false;
  else
    {
      if (pos < 0 | pos > list->cnt)
        return false;
      else
        {
        for (int i = list->cnt; i > pos; --i)
            {
              list->pBase[i] = list->pBase[i-1];
            }
        list->pBase[pos] = val;
        list->size++;
        return true;
        }
    }
}

bool list_delete(struct List *list, int pos)
{
  if (pos < 0 | pos > list->size - 1)
    return false;
  else
    {
      for (int i = pos; i < list->size; ++i)
        {
          list->pBase[i] = list->pBase[i+1];
        }
      list->size--;
      return true;
    }
}
bool list_delete_all(struct List *list)
{
  list->size = 0;
  return true;
}
void list_inversion(struct List *list)
{
  int *p;
  for (int i = 0; 2 * i < list->size; ++i)
    {
      p = list->pBase[i];
      list->pBase[i] = list->pBase[list->size-1-i];
      list->pBase[list->size - 1 - i] = p;
    }
  return;
}
void list_swap(struct List *list, int pos1, int pos2)
{
  if (pos1 < 0 | pos1 > list->size - 1 | pos2 < 0 | pos2> list->size - 1)
    printf("position wrong");
  else
    {
      int *p;
      p = list->pBase[pos1];
      list->pBase[pos1] = list->pBase[pos2];
      list->pBase[pos2] = p;
    }
  return;
}

void list_sort(struct List *list)
{
  for (int j = 0; j < list->size - 1; ++j)
    {
      for (int i = 0; i < list->size - 1; ++i)
        {
          if (list->pBase[i] < list->pBase[i + 1])
            {
              list_swap(list, i, i+1);
            }
        }
    }
  return;
}
