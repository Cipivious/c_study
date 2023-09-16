#include <stdio.h>
void swap(int, int); // defined in Listing 2-2
int main(void) {
  int a = 21;
  int b = 17;
  swap(&a,&b);
  printf("main: a = %d, b = %d\n", a, b);
  return 0;
}
