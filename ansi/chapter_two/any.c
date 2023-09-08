#include <stdio.h>

int conclude(char ch, char* s);

int squeeze(char* s1, char* s2)
{
  int tag = -1;
  for (int i = 0; s1[i] != '\0'; ++i)
    {
      if (conclude(s1[i], s2) == 1)
	{
	  tag = i;
	  break;
	}
    }
  return tag;
}

int conclude(char ch, char* s)
{
  for (int i = 0; s[i] != '\0'; ++i)
    {
      if (ch - s[i] == 0)
	{
	  return 1;
	}
    }
  return 0;
}

int main( )
{
  char s[] = "dldfshkjvksldf";
  char t[] = "gs";
  int tag = 0;
  printf("before squeeze s: %s\n", s);
  printf("before squeeze t: %s\n", t);
  tag = squeeze(&s[0], &t[0]);
  printf("after squeeze tag: %d\n", tag);
  return 0;
}
