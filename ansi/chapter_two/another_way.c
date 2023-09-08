for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
s[i] = c;
#include <stdio.h>

int getaline(int s[], int lim)
{
  int i;
  for(i = 0; i < lim - 1; ++i)
    {
      c = getchar();
      if(c != '\n')
	;
      else
	continue;
      if(c != EOF)
	;
      else
	continue;
      s[i] = c;
    }
  return s[];
}

int main( )
{
  int len = 80;
  int s[len];
  int l[];
  while((l = getaline(s[], len)) != ( '\n' && EOF))
    printf("%s",l);
  return 0;
}
