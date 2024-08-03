/* Exercise 1.23: Write a program to remove all comments from a c program. Don't
 * forget to handle quoted strings and characters constants properly. c comments
 * do not nest. */

#include <stdbool.h>
#include <stdio.h>

#define BUFFER 1000

bool line_comments = false;
bool block_comments = false;
bool quote = false;

int getline_a(char line[]);
void uncomment(char from[], char to[]);

int main(void) {
  char line[BUFFER], temp[BUFFER];

  int len;
  while ((len = getline_a(line)) > 0) {
    uncomment(line, temp);
    printf("%s", temp);
  }
  return 0;
}

int getline_a(char s[]) {
  int c, i;

  for (i = 0; i < BUFFER - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void uncomment(char s[], char to[]) {
  int i, temp_index;

  extern bool line_comments, block_comments, quote;

  char next, current;

  next = current = '\0';
  temp_index = 0;

  for (i = 0; s[i] != '\0'; i++) {
    current = s[i];
    next = s[i + 1];

    if (current == '"' && !quote && !block_comments && !line_comments) {
      quote = true;
    } else if (quote && current == '"' && !block_comments && !line_comments) {
      quote = false;
    }

    if (!quote) {
      /* To check if new comment is starting */
      if (!line_comments && !block_comments) {
        if (!line_comments && current == '/' && next == '/') {
          line_comments = true;
          i++;
          continue;
        } else if (!block_comments && current == '/' && next == '*') {
          block_comments = true;
          i++;
          continue;
        }
      }

      /* To check if the comment is over */
      if (current == '\n' && line_comments) {
        line_comments = block_comments = false;
        continue;
      } else if (block_comments && current == '*' && next == '/') {
        block_comments = false;
        i++;
        continue;
      }

      if (!line_comments && !block_comments) {
        to[temp_index++] = current;
      }
    } else {
      to[temp_index++] = current;
    }
  }

  to[temp_index] = '\0';
}
