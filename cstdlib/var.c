#include <stdio.h>
#include <stdarg.h>

int sum(int count, ...)
{
  int res = 0;
  va_list list;
  va_start(list, count);
  for (int i = 0; i < count; i++)
    {
      res += va_arg(list, int);
    }
  return res;
}

int main()
{
  printf("%d ", sum(3, 3, 7, 8));

  return 0;
}
