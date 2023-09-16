#include <stdio.h>

void escape(char s[], char t[]);

int main( )
{
  char t[] = "alghaksfdalsfa\n\t\t\nadfksf\nsf\tglagf\n";
  char s[50];
  printf("t is: %s\n", t);
  escape(&s[0], &t[0]);
  printf("s is: %s\n", s);
  return 0;
}

void escape(char s[], char t[])
{
  int j = 0;
  for (int i = 0; t[i] != '\0'; i++)
    {
      switch (t[i]) {
      case '\n': {
	s[j++] = '\\';
	s[j++] = 'n';
	break;
      }
      case '\t': {
	s[j++] = '\\';
	s[j++] = 't';
	break;
      }
      default:
	s[j++] = t[i];
	break;
      }
    }
}
