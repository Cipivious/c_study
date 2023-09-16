#include <stdio.h>
#include "list.h"
#include "stack.h"

int main()
{
  Stack stack;
  ListElmt* stackelmt;
  int a[10];
  void *data;
  int i;
  for (i = 0; i < 10; ++i)
    a[i] = i;
  stack_init(&stack, free);

  for (i = 0; i < 10; ++i)
    {
      stack_push(&stack, (const void*)&a[i]);
    }
  stackelmt = stack.head;
  printf("第一次遍历的结果：");
  for (int i = 0; i < 10; ++i)
    {
      printf("%d ",*(int *)(stackelmt->data));
      stackelmt = stackelmt->next;
    }
  printf("\n");
  stack_pop(&stack, (void**)&data);
  printf("第二次遍历的结果：");
  stackelmt = stack.head;
  for (int i = 0; i < 9; ++i)
    {
      printf("%d ",*(int *)(stackelmt->data));
      stackelmt = stackelmt->next;
    }
  printf("\n");
  printf("删除的元素的值为：");
  printf("%d\n", *(int*)data);
  printf("链表的长度：%d\n", stack.size);
  stack_destroy(&stack);
  printf("链表的长度：%d\n", stack.size);
}
