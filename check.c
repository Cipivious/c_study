#include <stdio.h>
void main()
{
int c = 0;

c = getchar();
if ( c != EOF && c > '0' && c < '6')
{
    printf('you are right');
}
else
    printf('you are wrong');
}
