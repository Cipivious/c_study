#include <stdio.h>

/* atoi: convert s to integer */
int atoi(char s[])
{
  int i, n;
  n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    n = 10 * n + (s[i] - '0');
  return n;
}

int main( )
{
  char num[5];
  printf("please enter your number: ");
  scanf("%s", &num[0]);
  int n;
  n = atoi(&num[0]);
  printf("after convert: %d\n", n);
  return 0;
}
