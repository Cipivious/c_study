#include <stdio.h>
#include <stdlib.h>
typedef struct BTNode
{
  char data;
  struct BTNode * pLchild;
  struct BTNode * pRchild;
}BTNode;

struct BTNode* tree_create();
void tree_pretrans(BTNode *);

int main()
{
  struct BTNode * pT = tree_create();
  printf("先序访问树：");
  tree_pretrans(pT);
  printf("\n");
  return 0;
}

struct BTNode* tree_create()
{
  struct BTNode* pa = (struct BTNode*)malloc(sizeof(BTNode));
  struct BTNode* pb = (struct BTNode*)malloc(sizeof(BTNode));
  struct BTNode* pc = (struct BTNode*)malloc(sizeof(BTNode));
  struct BTNode* pd = (struct BTNode*)malloc(sizeof(BTNode));
  struct BTNode* pe = (struct BTNode*)malloc(sizeof(BTNode));
  pa->data = 'A';
  pb->data = 'B';
  pc->data = 'C';
  pd->data = 'D';
  pe->data = 'E';
  pa->pLchild = pb;
  pa->pRchild = pc;
  pb->pLchild = NULL;
  pb->pRchild = pd;
  pc->pLchild = pe;
  pc->pRchild = NULL;
  pd->pLchild = NULL;
  pd->pRchild = NULL;
  pe->pLchild = NULL;
  pe->pRchild = NULL;

  return pa;
}

void tree_pretrans(BTNode * ptree)
{
  printf("%c", ptree->data);
  if (ptree->pLchild != NULL)
    tree_pretrans(ptree->pLchild);
  if (ptree->pRchild != NULL)
    tree_pretrans(ptree->pRchild);
}
