#include <ctype.h>
#include <stdio.h>

char lower(char ch)
{
  return (isupper(ch)) ? (ch - 'A' + 'a') : ch;
}

int main()
{
  char ch = 'A';
  printf("before lower: %c\n", ch);
  ch = lower(ch);
  printf("after lower: %c\n", ch);
  return 0;
}
