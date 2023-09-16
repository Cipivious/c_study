#include <stdio.h>
#include <stdlib.h>
int main()
{
  int a[5] = {1, 2, 4, 5, 3};

  int len;
  printf("请输入你需要分配的数组的长度：");
  scanf("%d", &len);
  int * pArr = (int *)malloc(sizeof(int) * len);
  return 1;
}
