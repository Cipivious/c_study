#include <stdio.h>

typedef struct Student
{
  int sid;
  char name[100];
  int age;
}*Pst;

int main(void)
{
  struct Student st;
  Pst pst = &st;
  pst->sid = 100;
  printf("%d", st.sid);
  return 0;

}
