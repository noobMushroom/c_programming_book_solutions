/* Exercise 1.8: Write a program to count blank, tabs, and newlines */

#include <stdio.h>

int main(void) {
  int c, tab, newline, blank;
  tab = newline = blank = 0;
  while ((c = getchar()) != EOF)
    if (c == '\n')
      ++newline;
    else if (c == '\t')
      ++tab;
    else if (c == ' ')
      ++blank;

  printf("Newlines: %d\nTabs: %d\nBlanks: %d\n", newline, tab, blank);
}
