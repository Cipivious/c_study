#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

#define MAXOP 100
#define NUMBER '0'
#define BUFSIZE 100
#define MAXVAL 100

extern int sp;
extern double val[MAXVAL];
extern char buf[BUFSIZE];
extern int bufp;
extern int type;
extern double op2;
extern char s[MAXOP];

extern int getop(char []);
extern void push(double);
extern double pop(void);
extern int getch(void);
extern void ungetch(int c);

#endif /* CALCULATOR_H */
