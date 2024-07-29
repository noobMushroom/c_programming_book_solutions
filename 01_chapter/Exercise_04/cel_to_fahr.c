/*************************************************************************************************/
/*                                                                                               */
/* Exercise 1.4: Write a programming to print the corresponding Celsius to Fahrenheit table.     */
/*                                                                                               */
/*************************************************************************************************/

#include <stdio.h>

int main(void) {
  int lower, upper, step;
  float celsius, fahr;
  lower = 0;
  upper = 300;
  step = 20;

  celsius = lower;
  printf("Celsius\t\tFahrenheit\n");
  while (celsius <= upper) {
    fahr = (9.0 / 5.0) * celsius + 32.0;
    printf("%3.0f\t\t%6.1f\n", celsius, fahr);
    celsius += step;
  }

  return 0;
}
