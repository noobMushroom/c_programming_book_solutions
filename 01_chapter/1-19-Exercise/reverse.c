/*Exercise 1.19: write a function reverse(s) that reverse the character string
 * s. Use it to write a program that reverse its input a line at a time.*/

#include <stdio.h>

#define BUFFER 1000

void reverse_string(char from[], char to[], int length);
int get_length(char s[]);
int getline_a(char s[], int lim);

int main(void) {
  char line[BUFFER], temp[BUFFER];
  int len;
  while ((len = getline_a(line, BUFFER)) > 0) {
    len = get_length(line);
    reverse_string(line, temp, len);
    printf("%s", temp);
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

void reverse_string(char from[], char to[], int length) {
  int i, j;
  for (i = length - 1, j = 0; i >= 0 && j < length; i--, j++) {
    to[j] = from[i];
  }
  to[length] = '\0';
}
