/* Exercise 2.2: Write a loop equivalent to the for loop above without using &&
 * and or ||. */

#include <stdio.h>
#define BUFFER 1000
#define LIMIT 100

int main(void) {
  char s[BUFFER];
  int c, i, lim;
  lim = LIMIT;
  while ((c = getchar()) != EOF) {
    if (i >= lim - 1) {
      break;
    }
    if (c == '\n') {
      break;
    }
    s[i++] = c;
  }

  return 0;
}
