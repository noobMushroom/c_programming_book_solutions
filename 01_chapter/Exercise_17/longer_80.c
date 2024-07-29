/* Exercise 1.17: Write a program to print all input lines that are longer than
 * 80 characters*/

#include <stdio.h>

#define BUFFER 1000

/* getline is C internal function to avoid it I named getline_a here*/
int getline_a(char line[], int lim);

int main(void) {
  int len;
  char line[BUFFER];

  while ((len = getline_a(line, BUFFER)) > 0) {
    if (len > 80) {
      printf("%s", line);
    }
  }

  return 0;
}

int getline_a(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - i && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;
}
