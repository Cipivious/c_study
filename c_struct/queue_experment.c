#include <stdio.h>
#include "list.h"
#include "queue.h"

int main()
{
  Queue queue;
  ListElmt* queueelmt;
  int a[10];
  void *data;
  int i;
  for (i = 0; i < 10; ++i)
    a[i] = i;
  queue_init(&queue, free);

  for (i = 0; i < 10; ++i)
    {
      queue_enqueue(&queue, (const void*)&a[i]);
    }
  queueelmt = queue.head;
  printf("第一次遍历的结果：");
  for (int i = 0; i < 10; ++i)
    {
      printf("%d ",*(int *)(queueelmt->data));
      queueelmt = queueelmt->next;
    }
  printf("\n");
  queue_dequeue(&queue, (void**)&data);
  printf("第二次遍历的结果：");
  queueelmt = queue.head;
  for (int i = 0; i < 9; ++i)
    {
      printf("%d ",*(int *)(queueelmt->data));
      queueelmt = queueelmt->next;
    }
  printf("\n");
  printf("删除的元素的值为：");
  printf("%d\n", *(int*)data);
  printf("链表的长度：%d\n", queue.size);
  queue_destroy(&queue);
  printf("链表的长度：%d\n", queue.size);
}
