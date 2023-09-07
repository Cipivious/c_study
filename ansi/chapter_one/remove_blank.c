#include <stdio.h>
#define MAXLINE 1000
/* maximum input line length */
int getaline(char line[], int maxline);
void copy(char to[], char from[]);
/* print the longest input line */
int main()
{
  /* save the old data */
  int old;
  /* get the new data */
  int new;
  
  int len;
  /* current line length */
  int max;
  /* maximum length seen so far */
  char line[MAXLINE];
  /* current input line */
  char longest[MAXLINE]; /* longest line saved here */
  max = 50;
  while ((len = getaline(line, MAXLINE)) > 0)
    {
      if (len == 1)
	continue;
      for (int i = 0; i < len; i++)
	{
	  new = line[i];
	  if (old == ' ' && new == ' ')
	    ;
	  else
	    {
	      putchar(new);
	    }
	  old = new;
	}
    }
  return 0;
}
/* getaline: read a line into s, return length */
int getaline(char s[],int lim)
{
  int c, i;
  for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}

/* if (tag == yes and next == blank) { */
/*   tag = yes; */
/*  } */
/*  else if */
/*  { */
/*    tag = no; */
/*    putchar; */
/*  } */
/*******************************************************************************************************************************/
/* input after your getting, save the forth in a blank, after we get the next one then we think how to get the correct input. */
/*******************************************************************************************************************************/
