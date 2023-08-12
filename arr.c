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
bool arr_is_full(struct Arr *arr);
bool arr_append(struct Arr *arr, int val);
bool arr_insert(struct Arr *arr, int pos, int val);
bool arr_delete(struct Arr *arr, int pos);
bool arr_delete_all(struct Arr *arr);
void arr_inversion(struct Arr *arr);
void arr_swap(struct Arr *arr, int pos1, int pos2);
void arr_sort(struct Arr *arr);

int main(void)
{
  struct Arr arr;
  arr_init(&arr, 6);
  arr_show(&arr);
  arr_append(&arr, 1);
  arr_append(&arr, 2);
  arr_append(&arr, 3);
  arr_append(&arr, 4);
  arr_append(&arr, 8);
  arr_insert(&arr, 2, 100);
  arr_delete(&arr, 1);
  arr_show(&arr);
  arr_inversion(&arr);
  //arr_delete_all(&arr);
  arr_show(&arr);
  arr_sort(&arr);
  arr_show(&arr);
  arr_inversion(&arr);
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

bool arr_is_full(struct Arr *arr)
{
  if (arr->cnt == arr->len)
    return true;
  else
    return false;
}
void arr_show(struct Arr *arr)
{
  if (arr_is_empty(arr))
    printf("数组为空\n");
  else
    {
      for(int i = 0; i < arr->cnt; ++i)
        printf("%d\n", (arr->pBase)[i]);
    }
  return;
}

bool arr_append(struct Arr *arr, int val)
{
  if (arr_is_full(arr))
    return false;
  else
    {
      arr->pBase[arr->cnt] = val;
      arr->cnt++;
      return true;
    }
}
bool arr_insert(struct Arr *arr, int pos, int val)
{
  if (arr_is_full(arr))
    return false;
  else
    {
      if (pos < 0 | pos > arr->cnt)
        return false;
      else
        {
        for (int i = arr->cnt; i > pos; --i)
            {
              arr->pBase[i] = arr->pBase[i-1];
            }
        arr->pBase[pos] = val;
        arr->cnt++;
        return true;
        }
    }
}

bool arr_delete(struct Arr *arr, int pos)
{
  if (pos < 0 | pos > arr->cnt - 1)
    return false;
  else
    {
      for (int i = pos; i < arr->cnt; ++i)
        {
          arr->pBase[i] = arr->pBase[i+1];
        }
      arr->cnt--;
      return true;
    }
}
bool arr_delete_all(struct Arr *arr)
{
  arr->cnt = 0;
  return true;
}
void arr_inversion(struct Arr *arr)
{
  int *p;
  for (int i = 0; 2 * i < arr->cnt; ++i)
    {
      p = arr->pBase[i];
      arr->pBase[i] = arr->pBase[arr->cnt-1-i];
      arr->pBase[arr->cnt - 1 - i] = p;
    }
  return;
}
void arr_swap(struct Arr *arr, int pos1, int pos2)
{
  if (pos1 < 0 | pos1 > arr->cnt - 1 | pos2 < 0 | pos2> arr->cnt - 1)
    printf("position wrong");
  else
    {
      int *p;
      p = arr->pBase[pos1];
      arr->pBase[pos1] = arr->pBase[pos2];
      arr->pBase[pos2] = p;
    }
  return;
}

void arr_sort(struct Arr *arr)
{
  for (int j = 0; j < arr->cnt - 1; ++j)
    {
      for (int i = 0; i < arr->cnt - 1; ++i)
        {
          if (arr->pBase[i] < arr->pBase[i + 1])
            {
              arr_swap(arr, i, i+1);
            }
        }
    }
  return;
}
