#include <stdio.h>
/* inside a word */
/* outside a word */
/* count lines, words, and characters in input */
int main()
{
  int c;
  while ((c = getchar()) != EOF) {
    if (c == '\n')
      ;
    else
      putchar(c);
    }

  return 0;
}
