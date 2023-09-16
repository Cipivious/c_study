#include <stdio.h>

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
  int low, high, mid;
  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low+high)/2;
    if (x < v[mid])
      high = mid + 1;
    else if ( x > v[mid])
      low = mid + 1;
    else
      return mid;
  }
  return -1;
  /* no match */
}

int main( )
{
  int a[] = {1, 3, 5, 6, 7, 12, 24, 34};
  int pos;
  pos = binsearch(3, &a[0], 8);
  printf("a is: ");
  for (int i = 0; i < 8; i++)
    printf("%d ", a[i]);
  printf("\n");
  printf("pos of 3 is: %d", pos);
  printf("\n");
  return 0;
}
