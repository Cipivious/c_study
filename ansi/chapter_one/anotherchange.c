#include <stdio.h>
#define yes 1
#define no 0
/* count digits, white space, others */
int main()
{
  int c, i;
  i = no;
  while ((c = getchar()) != EOF)
    {
      if (i == no && (c != '\\'))
	{
	  putchar(c);
	}
      else if (i == no && ( c == '\\'))
	{
	  i = yes;
	}
      else if (i == yes && ( c == 'n'))
	{
	  putchar('\n');
	  i = no;
	}
      else if (i = yes && (c == 't'))
	{
	  putchar('\t');
	  i = no;
	}
      else if  (i = yes && (c != 't' || c != 'n'))
	{
	  putchar('\\');
	  putchar(c);
	  i = no;
	}
      else
	{
	  printf("have another choice");
	}
    }
  return 0;
}
