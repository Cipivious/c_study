#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Arr
{
  int *pBase;
  int len;
  int cnt;
};
void arr_init(struct Arr *arr, int length);
void arr_show(struct Arr *arr);
bool arr_is_empty(struct Arr *arr);
int main(void)
{
  struct Arr arr;
  arr_init(&arr, 6);
  arr_show(&arr);

  return 0;
}

void arr_init(struct Arr *arr, int length)
{
  arr->pBase = (int *)malloc(sizeof(int) * length);
  if (arr->pBase == NULL)
    {
      printf("内存分配失败");
      exit(-1);
    }
  else
    {
      arr->len = length;
      arr->cnt = 0;
    }
  return;
}

bool arr_is_empty(struct Arr *arr)
{
  if (arr->cnt == 0)
    return true;
  else
    return false;
}
void arr_show(struct Arr *arr)
{
  if (arr_is_empty(arr))
    printf("数组为空");
  else
    {
      for(int i = 0; i < arr->cnt; ++i)
        printf("%d\n", (arr->pBase)[i]);
    }
  return;
}
