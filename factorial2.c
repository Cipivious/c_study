#include <stdio.h>

int facttail(int n, int a){
  if (n < 0)
    return 0;
  else if (n == 0)
    return a;
  else
    return facttail(n - 1, n * a);
}

int main(){
  int a;
  a=facttail(10,1);
  printf("%d",a);
}
