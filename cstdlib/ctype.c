#include <stdio.h>
#include <ctype.h>

int main()
{
  if (islower(tolower(97)))
    printf("yes");
  else
    printf("no");
  return 0;
}
