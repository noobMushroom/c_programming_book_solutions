/*Exercise 1.20: Write a program detab that replaces tabs in the input with the
 * proper number of blanks to space to the next tab stop. Assumea a fixed set of
 * tab stops, say every n columns. Should n be a variable or a symbolic
 * parameter?*/

#include <stdio.h>

#define TAB_STOP 25
#define BUFFER 1000

char line[BUFFER];

int get_line(void);
int get_tabs(int index);
void detab(void);

int main(void) {
  int c, len;
  extern char line[];

  while ((len = get_line()) > 0) {
    detab();
    printf("%s", line);
  }

  return 0;
}

int get_line(void) {
  int c, i;

  extern char line[];

  for (i = 0; i < BUFFER - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
    line[i] = c;
  }
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}

void detab(void) {
  int i, j, k, space;
  char temp[BUFFER];
  int temp_index = 0;

  for (i = 0; line[i] != '\0'; i++) {
    if (line[i] != '\t') {
      temp[temp_index++] = line[i];
    } else {
      space = get_tabs(temp_index);
      for (j = 0; j < space; j++) {
        if (temp_index < BUFFER - 1) {
          temp[temp_index++] = ' ';
        }
      }
    }
  }
  temp[temp_index] = '\0';

  // Copy back to the original line
  for (k = 0; k <= temp_index; k++) {
    line[k] = temp[k];
  }
}

int get_tabs(int index) { return TAB_STOP - (index % TAB_STOP); }
