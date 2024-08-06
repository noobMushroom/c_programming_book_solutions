/* Exercise 2.3: Write the function htoi(s), which converts a string of
 * hexadecimal digits (including an optional 0x or 0X) into it's equivalent
 * integer value. The allowable digits are 0 through 9, a through f, and A
 * through F.*/

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 64

long double htoi(char hex[], int len);

int main(void) {
  char s[BUFFER];
  int i, c, len;
  long double dec;
  printf("Enter the hexadecimal number: ");

  while ((c = getchar()) != '\n') {
    if (i >= BUFFER - 1) {
      break;
    };
    s[i++] = c;
  }
  s[i] = '\0';

  len = strlen(s);
  dec = htoi(s, len);

  printf("%.0Lf\n", dec);
  return 0;
}

long double htoi(char s[], int len) {
  int j, i;
  char temp;
  double base, value;
  j = base = value = 0;

  if (len == 0 || s == NULL) {
    printf("Empty or null input\n");
    exit(EXIT_FAILURE);
  }

  if (s[j] == '0' && (s[j + 1] == 'x' || s[j + 1] == 'X'))
    j += 2;

  if (j == len) {
    printf("No hex digits after prefix\n");
    exit(EXIT_FAILURE);
  }

  for (i = len - 1; i >= j; i--) {
    temp = tolower(s[i]);
    if (isalpha(temp) && temp >= 'a' && temp <= 'f') {
      base += ((temp - 'a') + 10) * pow(16, value);
    } else if (isdigit(temp)) {
      base += (s[i] - '0') * pow(16, value);
    } else {
      printf("Wrong input\n");
      exit(EXIT_FAILURE);
    }
    value++;
  }
  return base;
}
