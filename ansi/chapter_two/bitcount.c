/* def bitcount(x):   */
/*     count = 0   */
/*     while x:   */
/*         x &= (x-1)   */
/*         count += 1   */
/*     return count */
#include <stdio.h>
int bitcount(unsigned x);

int main( )
{
  unsigned m = 14;
  int num;
  num = bitcount(m);
  printf("Binary representation of %d is: %b\n", num); 
  return 0;
}

int bitcount(unsigned x)
{
  int b;
  while (x != 0)
    {
      x &= (x - 1);
      b++;
    }
  return b;
}
//* * bitcount: count 1 bits in x *\/ */
/* int bitcount(unsigned x) */
/* { */
/* int b; */
/* for (b = 0; x != 0; x >>= 1) */
/* if (x & 01) */
/* b++; */
/* return b; */
/* } */
