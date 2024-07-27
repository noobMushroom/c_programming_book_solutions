/*Exercise 1.19: write a function reverse(s) that reverse the character string
 * s. Use it to write a program that reverse its input a line at a time.*/

#include <stdio.h>

#define BUFFER 1000

void reverse_string(char line[], int length);
int get_length(char s[]);
int getline_a(char s[], int lim);

int main(void) {
  char line[BUFFER];
  int len;
  while ((len = getline_a(line, BUFFER)) > 0) {
    len = get_length(line);
    reverse_string(line, len);
    printf("%s", line);
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

void reverse_string(char s[], int length) {
  int front, back;
  char temp;

  front = 0;
  back = length;

  if (s[back - 1] == '\n') {
    back -= 2;
  } else {
    back -= 1;
  }

  while (back > front) {
    temp = s[front];
    s[front] = s[back];
    s[back] = temp;
    front++;
    back--;
  }
}
