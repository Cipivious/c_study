#include <stdio.h>
//x is a number, p is position, n 
int main(int argc, char *argv[])
{
  
  return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
  unsigned mask = (1 << n) - 1 
}
/* int setbits(unsigned x, int p, int n, unsigned y) */
/* { */
/*   unsigned z; */
/*   z = (y << (p + 1)) & (~0); */
/*   unsigned m; */
/*   m = (~((~0) << (n))) >> (p + 1 - n); */
/*   unsigned n; */
/*   n = m | x; */
/*   return n & z; */
/* } */

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
  return (x >> (p+1-n)) & ~(~0 << n);
}

x &= (x-1)

  x = x & (x - 1);
