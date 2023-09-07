#include <stdio.h>

void detab(int n);

int main( )
{
  int c = 20;
  /* XXX: accept input */
  detab(c);
  return 0;
}

void detab(int n)
{
  int c;
  while((c = getchar()) != EOF)
    {
      if(c == '\t')
	{
	  for(int i = 0; i < n; i++)
	    {
	      putchar(' ');
	    }
	}
      else
	{
	  putchar(c);
	}
    }
}
