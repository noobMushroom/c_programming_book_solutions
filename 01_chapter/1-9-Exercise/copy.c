/* Exercise 1.9: write a program to copy its input to its ouput, replacing each
 * string of one or more blanks by a single blank */
#include <stdio.h>

int main(void) {
  int c, last_c, is_last_char_blank;
  is_last_char_blank = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      if (!is_last_char_blank) {
        putchar(c);
        is_last_char_blank = 1;
      }
    } else {
      putchar(c);
      is_last_char_blank = 0;
    }
  }
  return 0;
}
