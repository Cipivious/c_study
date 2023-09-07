#include <stdio.h>
/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300; floating-point version */
int main()
{
  float fahr, celsius;
  float lower, upper, step;
  lower = -17.8;
  upper = 100;
  step = 11.2;
  /* lower limit of temperatuire scale */
  /* upper limit */
  /* step size */
  celsius = lower;
  printf("Fahrenheit-Celsius table\n");
  while (celsius <= upper) {
    fahr = celsius /(5.0/9.0) + 32;
    printf("%3.0f %6.1f\n", fahr, celsius);

    celsius = celsius + step;
  }
  return 0;
}
