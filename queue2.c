#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue
{
  int *pbase;
  int front;
  int rear;
}Queue;

void queue_init(Queue*);
bool queue_full(Queue*);
bool queue_input(Queue* , int);
bool queue_empty(Queue*);
bool queue_output(Queue*);
void queue_trans(Queue*);
int queue_len(Queue*);

int main()
{
  Queue q;
  int len;
  queue_init(&q);
  queue_input(&q, 1);
  queue_input(&q, 4);
  queue_input(&q, 3);
  queue_input(&q, 1);
  queue_input(&q, 4);
  queue_input(&q, 3);
  queue_input(&q, 5);
  queue_input(&q, 2);
  printf("队列添加元素后：");
  queue_trans(&q);
  printf("队列的长度是：%d\n", queue_len(&q));
  queue_output(&q);
  queue_output(&q);
  printf("队列删除元素后：");
  queue_trans(&q);
  printf("队列的长度是：%d\n", queue_len(&q));

  return 0;
}

void queue_init(Queue* pq)
{
  pq->pbase = (int*)malloc(sizeof(int) * 6);
  pq->front = 0;
  pq->rear = 0;
  return;
}

bool queue_full(Queue* pq)
{
  if ((pq->rear + 1) % 6 == pq->front)
    return true;
  else
    return false;
}

bool queue_input(Queue* pq, int i)
{
  if (queue_full(pq))
    return false;
  else
    {
      pq->pbase[pq->rear] = i;
      pq->rear = (pq->rear + 1) % 6;
    }
}

bool queue_empty(Queue* pq)
{
  if (pq->rear == pq->front)
    return true;
  else
    return false;
}

bool queue_output(Queue* pq)
{
  if (queue_empty(pq))
    return false;
  else
    {
      pq->front = (pq->front + 1) % 6;
      return true;
    }
}

void queue_trans(Queue* pq)
{
  int i = pq->front;
  while (i != pq->rear)
    {
      printf("%d ", pq->pbase[i]);
      i = (i + 1) % 6;
    }
  printf("\n");
  return;
}

int queue_len(Queue* pq)
{
  int i = pq->front;
  int j = 0;
  while (i != pq->rear)
    {
      ++j;
      i = (i + 1) % 6;
    }
  return j;
}
