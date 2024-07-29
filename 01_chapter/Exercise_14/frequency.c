/*Exercise 1.14: write a program to print a histogram of the frequencies of
 * different characters in its input. */

#include <stdio.h>

#define BUFFER 128

int main(void) {

  int characters[BUFFER] = {0};
  int c, max_count;

  max_count = 0;
  while ((c = getchar()) != EOF) {
    ++characters[c];
    max_count = characters[c] > max_count ? characters[c] : max_count;
  }

  for (int i = max_count; i > 0; i--) {
    printf("%3d | ", i);
    for (int j = 0; j < BUFFER; j++) {
      if (characters[j] >= i) {
        printf(" # ");
      } else if (characters[j] > 0) {
        printf("   ");
      }
    }
    printf("\n");
  }

  // Print the x-axis
  printf("    +");
  for (int j = 1; j < BUFFER; j++) {
    if (characters[j] > 0) {
      printf("---");
    }
  }

  printf("\n     ");
  // Print the word characters as labels on the x-axis
  for (int j = 1; j < BUFFER; j++) {
    if (characters[j] > 0) {
      if (j == '\n') {
        printf("%2c", '\\');
        printf("n ");
      } else if (j == '\t') {
        printf("%2c", '\\');
        printf("t ");
      } else {
        printf("%2c ", j);
      }
    }
  }
  printf("\n\n");
  return 0;
}
