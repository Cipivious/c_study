#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
  int data;
  struct Node* next;
};

typedef struct Node LNode;
typedef struct Node * LinkedList;

void LinkedListInit(LinkedList L);
int LinkedListLength(LinkedList L);
int LinkedListGet(LinkedList L, int i);
LNode LinkedListLocate(LinkedList L, int i);
void LinkedListInsert(LinkedList L, LinkedList p, int e);
void LinkedListDel(LinkedList L, int e);
void LinkedListCreate(LinkedList L, int a[]);

int main()
{

  return 0;
}

void LinkedListInit(LinkedList L)
{
  L = (LNode *)malloc(sizeof(LNode));
  if (L == NULL)
    {
      printf("false design place");
      exit(0);
    }
  L->next = NULL;
}

int LinkedListLength(LinkedList L)
{
  LNode *p;
  int j = 0;
  p = L->next;
  while (p != NULL)
    {
      j++;
      p = p->next;
    }
  return j;
}

LNode* LinkedListGet(LinkedList L, int i)
{
  LNode* p = L->next;
  int j = 1;
  while (p != NULL && j < i)
    {
      p = p->next;
      j++;
    }
  return p;
}

LNode LinkedListLocate(LinkedList L, int e)
{
  LNode* p = L->next;
  int j = 1;
  while (p != NULL && p->data == e)
    p = p->next;
  return p;
}

void LinkedListInsert(LinkedList L, LinkedList p, int e)
{
  LNode* q = (LNode *)malloc(sizeof(LNode));
  if (q == NULL)
    {
      printf("false design place");
      exit(0);
    }
  q->data = e;

  LNode* pre = L->next;
  while (pre != NULL && pre->next != p)
    pre = pre->next;

  q->next = pre->next;
  pre->next = q;
  return;
}

void LinkedListDel(LinkedList L, int e)
{
  LNode* pre = L->next;
  while (pre->next != NULL && pre->next->data != e)
    {
      pre = pre->next;
    }
  LNode* p = pre->next;
  if (p != NULL)
    {
      pre->next = p->next;
      free(p);
    }
  return;
}

void LinkedListCreate(LinkedList L, int a[])
{
  LNode* pre = L->next;
  L = (LNode*)malloc(sizeof(LNode));
  if (L == NULL)
    {
      printf("false design place");
      exit(0);
    }
  L->next = NULL;

  for (int i = 0; i < n; i++)
    {
      p = (LNode*)malloc(sizeof(LNode));
      if (p = NULL)
        {
          printf("false design place");
          exit(0);
        }

      p->data = a[i];
      p->next = L->next;
      L->next = p;
    }
}
