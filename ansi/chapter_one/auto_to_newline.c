#include <stdio.h>
#define MAXLINE 1000
void auto_to_newline(char line[], int max, int len, int tag);
/* maximum input line length */
int getaline(char line[], int maxline);
int main()
{
  int len;
  /* current line length */
  int max;
  /* maximum length seen so far */
  char line[MAXLINE];
  /* current input line */
  int tag;
  /* tag *********************************************************************/
  max = 20;
  tag = 0;
  while ((len = getaline(line, MAXLINE)) > 0)
    {
      auto_to_newline(line, max, len, tag);

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

void auto_to_newline(char line[], int max, int len, int tag)
{
  int time;
  time = 1;
  while(len > max)
    {
      for (tag; tag < time * max; tag++)
	putchar(line[tag]);
      putchar('\n');
      len = len - max;
      time++;
    }
  for (tag; tag < len; tag++)
    putchar(line[tag]);

}
