#include <stdio.h>
#include <stdlib.h>

struct Student
{
  int sid;
  int age;
};

struct Student * CreateStudent(void)
{
  struct Student *ptr = (struct Student *)malloc(sizeof(struct Student));
  ptr->sid = 11;
  ptr->age = 20;
  return ptr;
}

void ShowStudent(struct Student *ptr)
{
  printf("%d %d", ptr->sid, ptr->age);
}

int main(void)
{
  struct Student *ps;

  ps = CreateStudent();
  ShowStudent(ps);
  return 0;
}
