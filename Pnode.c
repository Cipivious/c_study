#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node
{
  int data;
  struct Node * next;
}*Pnode, Node;

Pnode pnode_create();
void pnode_trans(Pnode phead);
bool pnode_is_empty(Pnode phead);
int pnode_length(Pnode phead);

int main(void)
{
  Pnode phead;
  phead = pnode_create();
  pnode_trans(phead);
  if (pnode_is_empty(phead))
    printf("链表为空");
  else
    printf("链表不为空\n");
  printf("len of pnode is %d\n", pnode_length(phead));
  return 0;
}

Pnode pnode_create()
{
  int len;
  int val;
  int i;
  Pnode ptail = (Pnode)malloc(sizeof(Node));
  Pnode phead = (Pnode)malloc(sizeof(Node));
  if (phead == NULL | ptail == NULL)
    {
      printf("内存分配失败");
      exit(-1);
    }
  ptail->next = NULL;
  phead->next = ptail;
  printf("请输入您需要的节点的个数：len = ");
  scanf("%d", &len);

  for (i = 0; i < len; ++i)
    {
      printf("请输入第%d个节点的取值：", i + 1);
      scanf("%d", &val);

      Pnode pNew = (Pnode)malloc(sizeof(Node));
      if (pNew == NULL)
        {
          printf("内存分配失败");
          exit(-1);
        }
      pNew->data = val;
      ptail->next = pNew;
      pNew->next = NULL;
      ptail = pNew;
    }
  return phead;
}

void pnode_trans(Pnode phead)
{
  int i;
  for (int j = 0; phead->next != NULL; ++j)
    {
      printf("%d ", phead->next->data);
      phead = phead->next;
    }
  printf("\n");
  return;
}

bool pnode_is_empty(Pnode phead)
{
  if (phead->next = NULL)
    return true;
  else
    return false;
}

int pnode_length(Pnode phead)
{
  int i = 0;
  while (phead != NULL)
    {
      phead = phead->next;
      ++i;
    }
  return i;
}
