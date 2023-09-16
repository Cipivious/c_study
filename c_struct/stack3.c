#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node_
{
  int data;
  struct Node_ * next;
}Node,* PNode;

typedef struct Stack_
{
  PNode stack_top;
  PNode stack_bol;
}Stack,* PStack;

void stack_init(PStack);
void stack_push(PStack, int i);
void stack_trans(PStack);
bool stack_empty(PStack);
bool stack_pop(PStack, int*);
void stack_clear(PStack);

int main()
{
  Stack S;
  int val;
  stack_init(&S);
  stack_push(&S, 3);
  stack_push(&S, 4);
  stack_push(&S, 5);
  stack_push(&S, 6);
  stack_push(&S, 7);
  stack_push(&S, 7);
  printf("after push: ");
  stack_trans(&S);
  stack_pop(&S, &val);
  stack_pop(&S, &val);
  printf("after pop: ");
  stack_trans(&S);
  stack_clear(&S);
  printf("after clear: ");
  if (stack_empty(&S))
    printf("stack is empty");
  else
    printf("stack is not empty");

  return 0;
}

void stack_init(PStack ps)
{
  ps->stack_top = (PNode)malloc(sizeof(Node));
  if (ps->stack_top == NULL)
    {
      printf("false design place");
      exit(-1);
    }
  else
    {
      ps->stack_bol = ps->stack_top;
      ps->stack_bol->next = NULL;
    }
  return;
}

void stack_push(PStack ps, int val)
{
  PNode pNew = (PNode)malloc(sizeof(Node));
  if (pNew == NULL)
    {
      printf("false design place");
      exit(-1);
    }
  pNew->data = val;
  pNew->next = ps->stack_top;
  ps->stack_top = pNew;
  return;
}

void stack_trans(PStack ps)
{
  PNode p = ps->stack_top;

  while (p != ps->stack_bol)
    {
      printf("%d ", p->data);
      p = p->next;
    }
  printf("\n");
  return;
}

bool stack_empty(PStack ps)
{
  if (ps->stack_top == ps->stack_bol)
    return true;
  else
    return false;
}

bool stack_pop(PStack ps, int* val)
{
  if (stack_empty(ps))
    return false;
  PNode r = ps->stack_top;
  *val = r->data;
  ps->stack_top = r->next;
  free(r);
  return true;
}

void stack_clear(PStack ps)
{
  if (stack_empty(ps))
    {
      return;
    }
  else
    {
      PNode p = ps->stack_top;
      PNode q = NULL;
      while (p != ps->stack_bol)
        {
          q = p->next;
          free(p);
          p = q;
        }
      ps->stack_top = ps->stack_bol;
      return;
    }
}
