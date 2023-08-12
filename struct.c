#include <stdio.h>
#include <string.h>

struct Student
{
  int sid;
  char name[200];
  int age;
};

int main(void)
{
  struct Student st;
  struct Student st2;
  struct Student *pst;
  pst = &st2;
  st.sid = 1000;
  stpcpy(st.name, "Tom");
  st.age = 15;
  printf("%d %s %d\n", st.sid, st.name, st.age);
  pst->sid = 99;
  stpcpy(pst->name, "Jack");
  pst->age = 20;
  printf("%d %s %d\n", st2.sid, st2.name, st2.age);
  return 1;
}
