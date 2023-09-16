#include <stdio.h>
#include <ctype.h>
/* atof: convert string s to double */
double atof(char s[])
{
  double val, power, expand, num;
  int i, sign;
  for (i = 0; isspace(s[i]); i++) /* skip white space */
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }
  if (s[i] == 'e' || 'E')
    i++;
  if (s[i] == '-')
    i++;
  for (expand = 0.0; isdigit(s[i]); i++) {
    expand = expand * 10.0 + (s[i] - '0');
  }
  num = 1.0;
  for (int i = 0; i < expand; i++)
    num *= 10.0;
  return sign * val * num / power;
}

int main( )
{
  char s[] = "  134.74e-18";
  double num = atof(s);
  printf("s is: %s\n", s);
  printf("num is: %f\n", num);
  return 0;
}
