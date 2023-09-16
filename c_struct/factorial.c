#include <stdio.h>

int fact(int n){
  if (n < 0)
    return 0;
  else if (n == 0)
    return 1;
  else if (n == 1)
    return 1;
  else
    return n * fact(n - 1);
}

int main(){
  int a;
  int b;
  a=fact(10);
  printf("%d",a);
  b=10*9*8*7*6*5*4*3*2;
  printf("%d",b);
}
