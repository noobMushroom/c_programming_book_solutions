/*Exercise 1.15: Rewrite the temperature conversion program of section 1.2 to
 * use a function for conversion*/

#include <stdio.h>

#define UPPER 300
#define LOWER 0

float cel_to_fahr(int celsius);

int main(void) {
  int i;

  for (i = LOWER; i <= UPPER; i += 20) {
    printf("%3d\t%6.2f\n", i, cel_to_fahr(i));
  }

  return 0;
}

float cel_to_fahr(int celsius) { return (9.0 / 5.0) * celsius + 32.0; }
