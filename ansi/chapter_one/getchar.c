#include <stdio.h>
/* copy input to output; 1st version */
int main()
{
  int c;
  c = getchar();
  /* while (c != EOF) { */
  /*   putchar(c); */
  /*   /\* printf("%d ",c[1]); *\/ */
  /*   c = getchar(); */
  /* } */
  printf("first c: %d", c);
  printf("\n");
  c = getchar();
  printf("second c: %d", c);
  printf("\n");
  printf("%d", EOF);
  printf("\n");
  return 0;
}
