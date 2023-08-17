#include <stdio.h>

int f(int n)
{
  if (n == 0)
    return 0;
  else
    return f(n-1) + n;
}

int main()
{
  int val;
  printf("请输入你想要的数：");
  scanf("%d", &val);
  printf("累加之后的和为：%d\n", f(val));
}
