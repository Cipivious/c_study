#include <stdio.h>

long f(long n)
{
  if (n == 1)
    return 1;
  else
    return f(n - 1) * n;
}

int main()
{
  long n;
  printf("请输入你想要求阶乘的数:");
  scanf("%ld", &n);
  printf("%ld的阶乘是%ld\n", n, f(n));

  return 0;
}
