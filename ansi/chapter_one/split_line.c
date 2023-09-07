#include <stdio.h>
/* count digits, white space, others */
int main()
{
  int c;
  while ((c = getchar()) != EOF)
    if (c == ' ' || c == '\n' || c == '\t')
      putchar('\n');
    else
      putchar(c);
  return 0;
}
