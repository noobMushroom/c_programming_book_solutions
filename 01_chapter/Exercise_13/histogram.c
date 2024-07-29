/* Exercise 1.13: Write a program to print a histogram of the lengths of words
 * in its input. It is easy to draw the histogram with the bars horizontal; a
 * vertical orientation is more challenging. */

#include <stdio.h>

#define BUFFER 100

int main(void) {
  int lengths[BUFFER] = {0};
  int length, c, max_word;

  max_word = length = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (length != 0) {
        if (length <= BUFFER) {
          lengths[length]++;
          if (lengths[length] > max_word) {
            max_word = lengths[length];
          }
        }
        length = 0;
      }
    } else {
      ++length;
    }
  }
  if (length != 0 && length < BUFFER) {
    lengths[length]++;
    if (lengths[length] > max_word) {
      max_word = lengths[length];
    }
  }

  for (int i = 0; i < BUFFER; i++) {
    if (lengths[i] != 0) {
      printf("%4d | ", i);
      for (int j = 0; j < lengths[i]; j++) {
        printf("#");
      }
      printf("\n");
    }
  }

  printf("\n\n");
  /*Fot vertical histogram*/
  for (int i = max_word; i > 0; i--) {
    printf("%2d | ", i);
    for (int j = 0; j < BUFFER; j++) {
      if (lengths[j] >= i) {
        printf(" # ");
      } else if (lengths[j] > 0) {
        printf("   ");
      }
    }
    printf("\n");
  }

  // Print the x-axis
  printf("   +");
  for (int j = 1; j < BUFFER; j++) {
    if (lengths[j] > 0) {
      printf("---");
    }
  }
  printf("\n    ");

  // Print the word lengths as labels on the x-axis
  for (int j = 1; j < BUFFER; j++) {
    if (lengths[j] > 0) {
      printf("%2d ", j);
    }
  }
  printf("\n");

  return 0;
}
