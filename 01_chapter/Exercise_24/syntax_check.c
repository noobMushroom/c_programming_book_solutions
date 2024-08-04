/* Exercise 1.24: Write a program to check a C program for rudimentary syntax
 * error like unbalanced parentheses, brackets and braces. Don't forget about
 * quotes, both single and double, escape sequences, and  comments*/

#include <stdbool.h>
#include <stdio.h>

#define BUFFER 1000

char stack[BUFFER];
int ptr = 0;
bool quoted = false;
bool line_comment = false;
bool block_comment = false;

int getline_a(char line[]);
int check_syntax(char line[]);
bool is_comment(char current, char next);
bool check_escape(char val);
bool handle_brakets(char val);

int main(void) {
  char line[BUFFER];
  int len, result, line_number;
  line_number = 0;
  while ((len = getline_a(line)) > 0) {
    line_number++;
    result = check_syntax(line);
    if (!result) {
      printf("Syntax error detected\n");
      return 1;
    }
  }
  if (ptr != 0 || block_comment || line_comment) {
    printf("Unbalanced symbols detected at end of input\n");
    return 1;
  }
  printf("No syntax errors detected.\n");
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

int check_syntax(char s[]) {
  int i;
  char current, next;
  current = next = '\0';

  for (i = 0; s[i] != '\0'; i++) {
    current = s[i];
    next = s[i + 1];

    if (!line_comment && !block_comment && !quoted) {
      if (is_comment(current, next)) {
        i++;
        continue;
      }
    }

    if ((current == '"' || current == '\'') && !quoted && !line_comment &&
        !block_comment) {
      stack[ptr++] = current;
      quoted = true;
      continue;
    }

    if (!quoted && !line_comment && !block_comment) {
      if (!handle_brakets(current)) {
        return 0;
      }
    } else if (quoted) {
      if (current == stack[ptr - 1]) {
        quoted = false;
        ptr--;
        continue;
      }
      if (current == '\\') {
        if (check_escape(next)) {
          i++;
          continue;
        } else {
          return 0;
        }
      }
    } else if (line_comment || block_comment) {
      if (block_comment && current == '\n') {
        line_comment = block_comment = false;
        continue;
      } else if (line_comment && current == '*' && next == '/') {
        line_comment = false;
        i++;
        continue;
      }
    }
  }
  return 1;
}

/* Checks if the value is comment and then change the comment values*/
bool is_comment(char current, char next) {
  if (current == '/' && next == '*') {
    line_comment = true;
    return true;
  } else if (current == '/' && next == '/') {
    block_comment = true;
    return true;
  }
  return false;
}

bool check_escape(char val) {
  if (val == 'n' || val == 'a' || val == '\\' || val == 't' || val == 'b' ||
      val == 'v' || val == 'r' || val == '\'' || val == '"' || val == '0') {
    return true;
  }
  return false;
}

bool handle_brakets(char val) {
  if (val == '(' || val == '{' || val == '[') {
    stack[ptr++] = val;
  } else if (val == ')' || val == '}' || val == ']') {
    if (ptr == 0)
      return false;
    if ((val == '}' && stack[ptr - 1] == '{') ||
        (val == ')' && stack[ptr - 1] == '(') ||
        (val == ']' && stack[ptr - 1] == '[')) {
      ptr--;
      return true;
    } else {
      return false;
    }
  }
  return true;
}
