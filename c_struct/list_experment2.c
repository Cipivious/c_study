#include <stdio.h>
#include "list.h"

int main()
{
  List list;
  ListElmt* listelmt;
  int a[10];
  void *data;
  int i;
  for (i = 0; i < 10; ++i)
    a[i] = i;
  list_init(&list, free);

  for (i = 0; i < 10; ++i)
    {
      list_ins_next(&list, NULL, (const void*)&a[i]);
    }
  listelmt = list.head;
  printf("第一次遍历的结果：");
  for (int i = 0; i < 10; ++i)
    {
      printf("%d ",*(int *)(listelmt->data));
      listelmt = listelmt->next;
    }
  printf("\n");
  list_rem_next(&list, NULL, (void**)&data);
  printf("第二次遍历的结果：");
  listelmt = list.head;
  for (int i = 0; i < 9; ++i)
    {
      printf("%d ",*(int *)(listelmt->data));
      listelmt = listelmt->next;
    }
  printf("\n");
  printf("删除的元素的值为：");
  printf("%d\n", *(int*)data);
  printf("链表的长度：%d\n", list.size);
  list_destroy(&list);
  printf("链表的长度：%d\n", list.size);
  return 0;
}
