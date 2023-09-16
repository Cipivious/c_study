#include <stdio.h>
#include <string.h>

/* reverse: reverse string s in place */
void reverse(char s[])
{
  int c, i, j;
  for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

/* itoa: convert n to characters in s */
void itob(int n, char s[], int b)
{
  int i, sign;
  if ((sign = n) < 0) /* record sign */
    n = -n;
  /* make n positive */
  i = 0;
  do {
    /* generate digits in reverse order */
    s[i++] = n % b + '0'; /* get next digit */
  } while ((n /= b) > 0);
  /* delete it */
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

int main( )
{
  int num = 56;
  char s[16];
  printf("num is: %d\n", num);
  itob(num, &s[0], 16);
  printf("s is: %s\n", s);
  return 0;
}
