#include <stdio.h>
#define yes 1
#define no 0
/* count digits, white space, others */
int main()
{
  int c, i;
  i = no;
  while ((c = getchar()) != EOF)
    if (c == '\t')
      {
	putchar('\\');
	putchar('t');

      }
    else if (c == '\n')
      {
	putchar('\\');
	putchar('n');

      }
    else
      {
	putchar(c);
      }
  return 0;
}
