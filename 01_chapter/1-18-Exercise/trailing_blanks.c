/*Exercise 1.18: write a program to remove trailing blanks and tabs from each
 * line of input, and to delete entirely blank lines. */

#include <stdio.h>

#define BUFFER 1000

int getline_a(char s[], int lim);
int get_length(char s[]);
int is_empty(char s[], int length);
void remove_trailing_blanks(char s[], int length);

int main(void) {
  int len;
  char line[BUFFER];

  while ((len = getline_a(line, BUFFER)) > 0) {
    len = get_length(line);
    if (!is_empty(line, len)) {
      remove_trailing_blanks(line, len);
      printf("%s", line);
    }
  }

  return 0;
}

int getline_a(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

int get_length(char s[]) {
  int i;
  i = 0;
  while (s[i] != '\0')
    ++i;
  return i;
}

int is_empty(char s[], int length) {
  for (int i = 0; i < length; i++) {
    if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n') {
      return 0;
    }
  }
  return 1;
}

void remove_trailing_blanks(char s[], int length) {
  int i = length;

  while (i >= 0 && (s[i] == ' ' || s[i] == '\t')) {
    i--;
  }

  if (s[length - 1] == '\n') {
    s[++i] = '\n';
  }

  s[++i] = '\0';
}
