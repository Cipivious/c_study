#include <stdio.h>

/* atoi: convert s to integer */
int htoi(char s[])
{
  int i, n;
  n = 0x0;
  for (i = 2; s[i] >= '0' && s[i] <= '9' || s[i] >= 'A' && s[i] <= 'F'; ++i)
    {
      if (s[i] >= '0' && s[i] <= '9')
	{
	  switch (s[i]) {
	  case '0': {
	    n = 0x10 * n + 0x0;
	    break;
	  }
	  case '1': {
	    n = 0x10 * n + 0x1;
	    break;
	  }
	  case '2': {
	    n = 0x10 * n + 0x2;
	    break;
	  }
	  case '3': {
	    n = 0x10 * n + 0x3;
	    break;
	  }
	  case '4': {
	    n = 0x10 * n + 0x4;
	    break;
	  }
	  case '5': {
	    n = 0x10 * n + 0x5;
	    break;
	  }
	  case '6': {
	    n = 0x10 * n + 0x6;
	    break;
	  }
	  case '7': {
	    n = 0x10 * n + 0x7;
	    break;
	  }
	  case '8': {
	    n = 0x10 * n + 0x8;
	    break;
	  }
	  case '9': {
	    n = 0x10 * n + 0x9;
	    break;
	  }
	  default:
	    break;
	  }
	}
      else
	{
	  switch (s[i]) {
	  case 'A': {
	    n = 0x10 * n + 0xA;
	    break;
	  }
	  case 'B': {
	    n = 0x10 * n + 0xB;

	    break;
	  }
	  case 'C': {
	    n = 0x10 * n + 0xC;
	    break;

	  }
	  case 'D': {
	    n = 0x10 * n + 0xD;
	    break;
	  }
	  case 'E': {
	    n = 0x10 * n + 0xE;
	    break;
	  }
	  case 'F': {
	    n = 0x10 * n + 0xF;
	    break;
	  }
	  default:
	    break;
	  }
	}
    }

  return n;
}

int main( )
{
  char num[8];
  printf("please enter your number: ");
  scanf("%s", &num[0]);
  int n;
  n = htoi(&num[0]);
  printf("after convert: 0x%X\n", n);
  return 0;
}
