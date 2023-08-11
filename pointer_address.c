#include <stdio.h>
int main(){
  int a, *ptr, *ptr2;
  a = 10;
  ptr = &a;
  ptr2 = &(*ptr);
  printf("%d\n",a);
  printf("%d\n",*ptr);
  printf("%d\n",*ptr2);
  return 0;
}
