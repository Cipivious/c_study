#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Queueelmt
{
  int data;
  struct Queueelmt * next;
}Queueelmt, *Queue;

Queue queue_init();
int queue_len(Queue);
bool queue_trans(Queue);
bool queue_input(Queue, int);
bool queue_output(Queue, int*);

int main()
{
  Queue queue;
  int val;
  queue = queue_init();
  queue_input(queue, 1);
  queue_input(queue, 2);
  queue_input(queue, 3);
  queue_input(queue, 4);
  printf("队列的长度%d\n", queue_len(queue));
  printf("第一次链表遍历\n");
  queue_trans(queue);
  queue_input(queue, 4);
  printf("第二次链表遍历,插入队列元素4\n");
  queue_trans(queue);
  queue_output(queue, &val);
  printf("第三次链表遍历,移除队列元素\n");
  queue_trans(queue);
  printf("被移去的队列元素的值为：%d\n", val);
  return 0;
}

Queue queue_init()
{
  Queue queue = (Queueelmt*)malloc(sizeof(Queueelmt));
  if (queue == NULL)
    {
      printf("内存分配失败");
      exit(-1);
    }
  queue->next = NULL;
  return queue;
}

int queue_len(Queue queue)
{
  Queueelmt* p = queue->next;
  int i = 0;
  while (p != NULL)
    {
      p = p->next;
      ++i;
    }
  return i;
}

bool queue_trans(Queue queue)
{
  Queueelmt* p = queue;
  Queueelmt* q = NULL;
  while (q != queue->next)
    {
        while (p->next != q)
          {
            p = p->next;
          }
        printf("%d ", p->data);
        q = p;
        p = queue;

    }
  printf("\n");
  return 0;
}

bool queue_input(Queue queue, int val)
{
  Queueelmt* new_elmt = (Queueelmt*)malloc(sizeof(Queueelmt));
  if (new_elmt == NULL)
    {
      printf("内存分配失败");
      exit(-1);
    }
  Queueelmt* p = queue;

  new_elmt->data = val;
  new_elmt->next = p->next;
  p->next = new_elmt;
  return 0;
}

bool queue_output(Queue queue, int* val)
{
  Queueelmt* p = queue;
  while (p->next->next != NULL)
    {
      p = p->next;
    }

  *val = p->next->data;
  Queueelmt *old_elmt = p->next;
  p->next = NULL;
  free(old_elmt);
  return true;
}
