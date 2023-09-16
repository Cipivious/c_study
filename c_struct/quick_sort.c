#include <stdio.h>

void quick_sort(int *a, int low, int high);

int main()
{
  int a[6] = {1, 8, 5, 9, 3, 0};
  int i;

  quick_sort(a, 0, 5);

  for (i = 0; i < 6; ++i)
    {
      printf("%d ", a[i]);
    }
  printf("\n");

  return 0;
}

void quick_sort(int *a, int low, int high)
{
  if (low < high) {
    int val;
    int low1, high1;
    low1 = low;
    high1 = high;
    val = a[low1];
    while (low1 != high1)
    {
      while (low1 < high1 && a[high1] >= val)
      {
        high1--;
      }
      a[low1] = a[high1];
      while (low1 < high1 && a[low1] <= val)
      {
        low1++;
      }
      a[high1] = a[low1];
    }
    a[low1] = val;

    quick_sort(a, low, low1 - 1);
    quick_sort(a, low1 + 1, high);
  }
}
