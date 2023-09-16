#include <stdio.h>

int strindex(char s[], char t[])
{
  int i, j, k;
  for (i = 0; s[i] != '\0'; i++) {
    for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
      {
	if (k > 0 && t[k + 1] == '\0')
	  return j + 1;

      }
  }
  return -1;
}

int main( )
{
  char pattern[] = "dfj";
  char s[] = "algdkhaldfjsfdhasf";
  int pos = strindex(s, pattern);
  printf("s is: %s\n", s);
  printf("pattern is: %s\n", pattern);
  printf("pos is: %d\n", pos);
  return 0;
}
