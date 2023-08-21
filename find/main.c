#include <stdio.h>
#include <stdlib.h>

void arr_show(int arr[], int length);
int compare(const void *a, const void *b);
int forward_search(int arr[], int length, int key);
int sentinel_search(int arr[], int length, int key);
int binary_search(int arr[], int length, int key);
int binary_search2(int arr[], int left, int right, int key);

int main()
{
  int arr[10] = {2, 4, 7, 2, 8, 9, 4, 5, 3, 19};
  int position;
  int key = 88;
  arr_show(arr, 10);
  qsort(arr, 10, sizeof(int), compare);
  arr_show(arr, 10);
  position = forward_search(arr, 10, key);
  printf("the position of %d is : %d\n", key, position);
  position = sentinel_search(arr, 10, key);
  printf("the position of %d is : %d\n", key, position);
  position = binary_search(arr, 10, key);
  printf("the position of %d is : %d\n", key, position);
  position = binary_search2(arr, 0, 9, key);
  printf("the position of %d is : %d\n", key, position);

  return 0;
}

void arr_show(int arr[], int length)
{
  for (int i = 0; i < length; i++)
    {
      printf("%d ", arr[i]);
    }
  printf("\n");
  return;
}

int compare(const void *a, const void *b)
{
  return *(int*)a - *(int*)b;
}

int forward_search(int arr[], int length, int key)
{
  for(int i = 0; i < length; i++)
    {
      if (arr[i] == key)
        {
          return i;
        }
    }
  return -1;
}

int sentinel_search(int arr[], int length, int key)
{
  arr[0] = key;
  for (int i = length - 1; i >= 0; i--)
    {
      if (arr[i] == arr[0])
        {
          return i;
        }
    }
}

int binary_search(int arr[], int length, int key)
{
  int left = 0, right = length - 1, mid;
  while (left < right)
    {
      mid = left + (right - left) / 2;
      if (key < arr[mid]) right = mid - 1;
      else if (key > arr[mid]) left = mid + 1;
      else return mid;
    }
  return -1;
}

int binary_search2(int arr[], int left, int right, int key)
{
  if (left > right) return -1;
  int mid = left + (right - left) / 2;
  if (arr[mid] == key)
    return mid;
  else
    {
      if (arr[mid] < key)
        {
          return binary_search2(arr, mid + 1, right, key);
        }
      else
        {
          return binary_search2(arr, left, mid - 1, key);
        }
    }
  return -1;
}
