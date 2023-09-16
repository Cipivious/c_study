#include "calculator.h"
/* reverse Polish calculator */
int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;
int type;
double op2;
char s[MAXOP];

int main()
{
  type = getop(s);
  while (type != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
	push(pop() / op2);
      else
	printf("error: zero divisor\n");
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
    type = getop(s);
  }
  return 0;
}
