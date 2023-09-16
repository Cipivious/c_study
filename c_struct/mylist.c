#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Listelmt
{
  int data;
  struct Listelmt * next;
}Listelmt, *List;

List list_init();
bool list_append(List, int val);
int list_len(List);
bool list_trans(List);
bool list_ins(List, int ,int);
bool list_rem(List, int, int*);

int main()
{
  List list;
  int val;
  list = list_init();
  list_append(list, 1);
  list_append(list, 2);
  list_append(list, 3);
  list_append(list, 4);
  printf("链表的长度%d\n", list_len(list));
  printf("第一次链表遍历\n");
  list_trans(list);
  list_ins(list, 3, 4);
  printf("第二次链表遍历,在第3个位置插入4\n");
  list_trans(list);
  list_rem(list, 4, &val);
  printf("第三次链表遍历,移除第四个元素\n");
  list_trans(list);
  printf("被移去的第四个元素的值为：%d\n", val);
  return 0;
}

List list_init()
{
  List list = (Listelmt*)malloc(sizeof(Listelmt));
  if (list == NULL)
    {
      printf("内存分配失败");
      exit(-1);
    }
  list->next = NULL;
  return list;
}

int list_len(List list)
{
  Listelmt* p = list->next;
  int i = 0;
  while (p != NULL)
    {
      p = p->next;
      ++i;
    }
  return i;
}

bool list_append(List list, int val)
{
  Listelmt* p = list;
  Listelmt* new_elmt = (Listelmt *)malloc(sizeof(Listelmt));
  if (new_elmt == NULL)
    {
      printf("内存分配失败");
      exit(-1);
    }
  while (p->next != NULL)
    p = p->next;

  new_elmt->data = val;
  new_elmt->next = NULL;
  p->next = new_elmt;
  return 0;
}

bool list_trans(List list)
{
  Listelmt* listelmt = list->next;
  while (listelmt != NULL)
    {
      printf("%d ",listelmt->data);
      listelmt = listelmt->next;
    }
  printf("\n");
  return 0;
}

bool list_ins(List list, int pos, int val)
{
  Listelmt* new_elmt = (Listelmt*)malloc(sizeof(Listelmt));
  if (new_elmt == NULL)
    {
      printf("内存分配失败");
      exit(-1);
    }
  Listelmt* p = list;
  int i = 0;
  while (p->next != NULL && i < pos - 1)
    {
      p = p->next;
      i++;
    }

  new_elmt->data = val;
  new_elmt->next = p->next;
  p->next = new_elmt;
  return 0;
}

bool list_rem(List list, int pos, int* val)
{
  Listelmt* p = list;
  int i = 0;
  while (p->next != NULL && i < pos - 1)
    {
      p = p->next;
      i++;
    }
  if (i > pos - 1 || p->next == NULL)
    return false;

  *val = p->next->data;
  Listelmt *old_elmt = p->next;
  p->next = p->next->next;
  free(old_elmt);
  return true;
}
