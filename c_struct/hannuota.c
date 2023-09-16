#include <stdio.h>

void hannuota(int n, char A, char B, char C)
{
  if (n == 1)
    {
      printf("将编号为%d的盘子从%c移动到%c\n", n, A, C);
    }
  else
    {
      hannuota(n-1, A, C, B);
      printf("将编号为%d的盘子从%c移动到%c\n", n, A, C);
      hannuota(n-1, B, C, A);
    }
}

int main()
{
  char ch1 = 'A';
  char ch2 = 'B';
  char ch3 = 'C';
  hannuota(3, ch1, ch2, ch3);

  return 0;
}
