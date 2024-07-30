/*Exercise 1.21: write a program entab that replaces strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing. Use the same
 * tab stop as for entab. When either a tab or a single blank woould suffice to
 * reach a tab stop, which should be given preference? */

#include <stdio.h>

#define TAB_STOP 8
#define BUFFER 1000

char line[BUFFER];

int get_line(void);
void entab(void);
int get_space_count(int index);

int main(void) {
  int c, len;
  extern char line[];

  while ((len = get_line()) > 0) {
    entab();
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

void entab(void) {
  int i, k, space, tabs_space;
  char temp[BUFFER];
  int temp_index = 0;

  for (i = 0; line[i] != '\0'; i++) {
    if (line[i] == ' ') {
      space++;
      if (space % TAB_STOP == 0 && space > 1) {
        temp[temp_index++] = '\t';
        space = 0;
      }
    } else {
      if (space > 1) {
        tabs_space = get_space_count(temp_index);
        while (tabs_space) {
          temp[temp_index++] = ' ';
          tabs_space--;
        }
        space = 0;
      } else if (space == 1) {
        temp[temp_index++] = ' ';
        space = 0;
      }
      temp[temp_index++] = line[i];
    }
  }
  temp[temp_index] = '\0';

  // Copy back to the original line
  for (k = 0; k <= temp_index; k++) {
    line[k] = temp[k];
  }
}

/*Takes the index and returns how mnany spaces are required to get to the next
 * tabstop*/
int get_space_count(int index) { return TAB_STOP - (index % TAB_STOP); }
