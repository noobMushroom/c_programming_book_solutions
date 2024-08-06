/* Exercise 2.3: Write the function htoi(s), which converts a string of
 * hexadecimal digits (including an optional 0x or 0X) into it's equivalent
 * integer value. The allowable digits are 0 through 9, a through f, and A
 * through F.*/

#include <math.h>
#include <stdio.h>
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
  int j, i, power;
  double base, value;
  j = base = value = 0;
  if (s[j] == '0' && (s[j + 1] == 'x' || s[j + 1] == 'X'))
    j += 2;

  for (i = len - 1; i >= j; i--) {
    if (((s[i] >= 'A' || s[i] >= 'a') && (s[i] <= 'f' || s[i] <= 'F')) ||
        s[i] >= 0 && s[i] <= '9') {
      power = pow(16, value);
      if (s[i] >= 'a' && s[i] <= 'f') {
        base += ((s[i] - 'a') + 10) * power;
      } else if (s[i] >= 'A' && s[i] <= 'F') {
        base += ((s[i] - 'A') + 10) * power;
      } else if (s[i] >= '0' && s[i] <= '9') {
        base += (s[i] - '0') * power;
      }
      value++;
    } else {
      printf("Wrong input\n");
      return 0;
    }
  }

  return base;
}
