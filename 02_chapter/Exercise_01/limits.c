/* Exercise 2.1: Write a program to determine the ranges of char, short, int,
 * and long variables, both signed and unsigned, by printing appropriate values
 * from standard headers and by direct computation. Harder if you compute them;
 * dtermine the ranges of the various floating-point types. */

#include <float.h>
#include <limits.h>
#include <stdio.h>

int main(void) {

  printf("Signed Char Min:          %12d\n", SCHAR_MIN);
  printf("Signed Char Max:          %12d\n", SCHAR_MAX);
  printf("Unsigned Char Max:        %12d\n", UCHAR_MAX);
  printf("Char Min:                 %12d\n", CHAR_MIN);
  printf("Char Max:                 %12d\n", CHAR_MAX);
  printf("Short Min:                %12d\n", SHRT_MIN);
  printf("Short Max:                %12d\n", SHRT_MAX);
  printf("Unsigned Short Max:       %12d\n", USHRT_MAX);
  printf("Int Min:                  %12d\n", INT_MIN);
  printf("Int Max:                  %12d\n", INT_MAX);
  printf("Unsigned Int Max:         %12d\n", UINT_MAX);
  printf("Long Min:                 %12d\n", LONG_MIN);
  printf("Long Max:                 %12d\n", LONG_MAX);
  printf("Unsigned Long Max:        %12d\n", ULONG_MAX);
  printf("Long Long Min:            %12d\n", LLONG_MIN);
  printf("Long Long Max:            %12d\n", LLONG_MAX);
  printf("Unsigned Long Long Max:   %12d\n", ULLONG_MAX);
  printf("Float Min:                %12d\n", FLT_MIN);
  printf("Float Max:                %12d\n", FLT_MAX);
  printf("Double Min:               %12d\n", DBL_MIN);
  printf("Double Max:               %12d\n", DBL_MAX);
  printf("Long Double Min:          %12d\n", LDBL_MIN);
  printf("Long Double Max:          %12d\n", LDBL_MAX);

  return 0;
}
