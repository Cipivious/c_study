#include <stdio.h>
#define yes 1
#define no 0
/* count digits, white space, others */
int main()
{
  int c, i;
  i = no;
  while ((c = getchar()) != EOF)
    if (i == yes && ( c == ' ' || c == '\t' || c== '\n'))
      ;
    else if (i == no && ( c == ' ' || c == '\t' || c== '\n'))
      {
	i = yes;
	putchar(c);
      }
    else
      {
	i = no;
	putchar(c);
      }
  return 0;
}
