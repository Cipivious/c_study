#include <stdlib.h>
#include <stdio.h>
/* #include <string.h> */

int main(int argc, char *argv[])
{
  system("git add *");
  char command[20];
  sprintf(command, "git commit -m \"%s\"", argv[1]);
  /* printf("%s", command); */
  system(command);
  system("git push origin main");
  return 0;
}
