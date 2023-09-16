#include <stdlib.h>
#include <stdio.h>
void stradd(char s[], int *pos, char s2[]);
void strpro(char forth, char after, char s[]);
void expand(char s1[], char s2[]);

int main( )
{
  char s1[] = "dfvhf-lk3-9khf";
  char s2[100];
  char s[27];
  int pos = 0;
  char forth = 'a';
  char after = 'z';
  printf("before expand s1: %s\n", s1);
  stradd(&s1[0], &pos, &s2[0]);
  printf("after stradd s2: %s\n" , s2);
  printf("pos is: %d\n", pos);
  strpro(forth, after, &s[0]);
  printf("after strpro s: %s\n", s);
  expand(&s1[0], &s2[0]);
  printf("after expand s2: %s\n", s2);
  return 0;
}

void expand(char s1[], char s2[])
{
  char forth;
  char after;
  int j = 0;
  char* s = (char *)malloc(sizeof(char) * 27);
  for (int i = 0; s1[i] != '\0'; ++i)
    {
      if (s1[i] == '-')
	{
	  if (i != 0)
	    {
	      forth = s1[i - 1];
	    }
	  else
	    continue;
	  if (s1[i + 1] != '\0')
	    {
	      after = s1[i + 1];
	    }
	  else
	    continue;
	  if (after - forth > 0)
	    {
	      strpro(forth, after, &s[0]);
	      stradd(&s[0], &j, &s2[0]);
	    }
	}
      else
	s2[j++] = s1[i];

    }
  free(s);
}

void strpro(char forth, char after, char s[])
{
  int i = 0;
  for (char ch = (char)(forth + 1); after - ch > 0; )
    {
      s[i++] = ch;
      ch = (char)(ch + 1);
    }
  s[i] = '\0';
}

void stradd(char s[], int *pos, char s2[])
{
  for (int i = 0; s[i] != '\0'; i++)
    {
      s2[*pos] = s[i];
      *pos += 1;
    }
}

