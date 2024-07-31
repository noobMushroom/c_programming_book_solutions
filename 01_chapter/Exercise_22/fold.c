/*Exercise 1.22: Write a program to "fold" long input lines into two or more
 * shorter lines after the last non-blank character that occurs before the nth
 * coulumn of input. Make sure your program does something intelligent with very
 * long lines, and if there are no blanks or tabs before a specified column. */

#include <stdio.h>

#define BUFFER 1000
#define FOLD_LIMIT 40

int get_length(char s[]);
int getline_a(char s[], int lim);
void fold_line(char s[], int length);

int main(void) {
  char line[BUFFER];
  int len;
  while ((len = getline_a(line, BUFFER)) > 0) {
    len = get_length(line);
    fold_line(line, len);
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
  int i = 0;
  while (s[i] != '\0')
    ++i;
  return i;
}

void fold_line(char s[], int length) {
  int start = 0, end;
  while (start < length) {
    end = start + FOLD_LIMIT;
    if (end >= length) {
      printf("%s", &s[start]);
      break;
    }

    int last_blank = -1;
    for (int i = start; i < end; i++) {
      if (s[i] == ' ' || s[i] == '\t')
        last_blank = i;
    }

    if (last_blank != -1) {
      s[last_blank] = '\n';
      printf("%.*s\n", last_blank - start, &s[start]);
      start = last_blank + 1;
    } else {
      printf("%.*s-\n", FOLD_LIMIT, &s[start]);
      start = end;
    }
  }
}
