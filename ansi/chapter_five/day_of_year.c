#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define num 10
int a;
int s[num];
static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
char *month_name(int n);

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main( )
{
  int pmonth;
  int pday;
  char* p;
  a = day_of_year(2023, 9, 11);
  printf("2023-9-11 is the %dth day of the year\n", a);
  month_day(2023, a, &pmonth, &pday);
  printf("a is 2023-%d-%d\n", pmonth, pday);
  p = month_name(3);
  printf("p is : %s\n", p);
  return 0;
}

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
  int i, leap;
  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  for (i = 1; i < month; i++)
    day += daytab[leap][i];
  return day;
}
/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
  int i, leap;
  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  for (i = 1; yearday > daytab[leap][i]; i++)
    yearday -= daytab[leap][i];
  *pmonth = i;
  *pday = yearday;
}
/* month_name: return name of n-th month */
char *month_name(int n)
{
  static char *name[] = {
    "Illegal month",
    "January", "February", "March",
    "April", "May", "June",
    "July", "August", "September",
    "October", "November", "December"
  };
  return (n < 1 || n > 12) ? name[0] : name[n];
}
