#include <stdio.h>

int main() {

  unsigned int p = 60; /* 60 = 0011 1100 */

  unsigned int q = 13; /* 13 = 0000 1101 */

  int r = 0;

  r = p | q; /* 61 = 0011 1101 */

  printf("Line 1 – The value of r is %d\n", r );

  r = p & q; /* 12 = 0000 1100 */

  printf("Line 2 – The value of r is %d\n", r );

  r = ~p; /*-61 = 1100 0011 */

  printf("Line 3 – The value of r is %d\n", r );

  r = p ^ q; /* 49 = 0011 0001 */

  printf("Line 4 – The value of r is %d\n", r );

  r = p >> 2; /* 15 = 0000 1111 */

  printf("Line 5 – The value of r is %d\n", r );

  r = p << 2; /* 240 = 1111 0000 */

  printf("Line 6 – The value of r is %d\n", r );
  return 0;
}
