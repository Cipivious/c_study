#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node_
{
  int data;
  struct Node_ * next;
}Node,* PNode;

typedef struct List_
{
  PNode head;
  PNode tail;
  int size;
}List,* PList;

void list_init(PList);
void list_append(PList, int i);
void list_ins(PList, int pos, int val);
void list_rem(PList, int pos, int * val);
void list_trans(PList);
bool list_empty(PList);
void list_clear(PList);

int main()
{
  List list;
  int val;
  list_init(&list);
  list_append(&list, 3);
  list_append(&list, 4);
  list_append(&list, 5);
  list_append(&list, 6);
  list_append(&list, 7);
  list_append(&list, 7);
  printf("after append: ");
  list_trans(&list);
  printf("after ins: ");
  list_ins(&list, 3, 100);
  list_trans(&list);
  printf("after rem: ");
  list_rem(&list, 4, &val);
  list_trans(&list);
  printf("被删除元素的值为：%d\n", val);
  list_clear(&list);
  printf("after clear: ");
  if (list_empty(&list))
    printf("list is empty\n");
  else
    printf("list is not empty\n");

  return 0;
}

void list_init(PList plist)
{
  plist->head = NULL;
  plist->tail = NULL;
  plist->size = 0;
  return;
}

void list_append(PList plist, int val)
{
  PNode pNew = (PNode)malloc(sizeof(Node));
  if (pNew == NULL)
    {
      printf("false design place");
      exit(-1);
    }
  pNew->data = val;
  if (list_empty(plist))
    {
      pNew->next = NULL;
      plist->tail = pNew;
      plist->head = pNew;
    }
  else
    {
      pNew->next = NULL;
      plist->tail->next = pNew;
      plist->tail = pNew;
    }
  plist->size++;
  return;
}

void list_ins(PList plist, int pos, int val)
{
  PNode pNew = (PNode)malloc(sizeof(Node));
  PNode p = plist->head;
  int size;
  int i = 1;
  size = plist->size;
  if (pNew == NULL)
    {
      printf("false design place");
      exit(-1);
    }
  pNew->data = val;
  if (list_empty(plist))
    {
      pNew->next = NULL;
      plist->tail = pNew;
      plist->head = pNew;
    }
  else
    {
      if (pos < 1 || pos > size - 1)
        {
          printf("pos wrong");
          exit(-1);
        }
      else
        {
          if (pos == 1)
            {
              pNew->next = plist->head->next;
              plist->head = pNew;
              plist->size++;
            }
          else
            {
              while (i < pos - 1)
                {
                  p = p->next;
                  i++;
                }
              pNew->next = p->next;
              p->next = pNew;
              plist->size++;
            }
        }
    }
  return;
}

void list_rem(PList plist, int pos, int* val)
{
  PNode p;
  PNode q;
  int size;
  int i = 1;
  if (list_empty(plist))
    {
      return;
    }
  else
    {
      if (pos < 1 || pos > size - 1)
        {
          printf("pos wrong");
          exit(-1);
        }
      else
        {
          if (pos == 1)
            {
              p = plist->head;
              *val = p->data;
              plist->head = p->next;
              free(p);
              plist->size--;
            }
          else
            {
              while (i < pos - 2)
                {
                  p = p->next;
                  i++;
                }
              q = p->next;
              *val = q->data;
              p->next = q->next;
              free(q);
              plist->size--;
            }
        }
    }
  return;
}

void list_trans(PList plist)
{
  PNode p = plist->head;

  while (p != plist->tail)
    {
      printf("%d ", p->data);
      p = p->next;
    }
  printf("%d ", p->data);
  printf("\n");
  return;
}

bool list_empty(PList plist)
{
  if (plist->size == 0)
    return true;
  else
    return false;
}

void list_clear(PList plist)
{
  if (list_empty(plist))
    {
      return;
    }
  else
    {
      PNode p = plist->head;
      PNode q = NULL;
      while (p != plist->tail)
        {
          q = p->next;
          free(p);
          p = q;
          plist->size--;
        }
      plist->size--;
      free(p);
      plist->head = NULL;
      plist->tail = NULL;
      return;
    }
}
