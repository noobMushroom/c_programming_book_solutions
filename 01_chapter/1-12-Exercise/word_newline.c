/*Exercise 1.12: Write a program that prints its input one word per line. */

#include <stdio.h>

int main(void) {
  int c, in_word;
  in_word = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (in_word) {
        putchar('\n');
        in_word = 0;
      }
    } else {
      putchar(c);
      in_word = 1;
    }
  }

  return 0;
}
