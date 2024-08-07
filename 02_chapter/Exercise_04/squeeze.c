/* Exercise 2.4: Write an alternate version of squeeze(s1, s2) that deletes each
 * character is s1 and matches any character in the string s2. */

#include <stdio.h>

#define BUFFER 256  /* Buffer for all the ascii characters */
#define LENGTH 1000 /* Buffer length for input string */

void squeeze(char s1[], char s2[]);

int main(void) {
  char s1[LENGTH], s2[LENGTH];

  printf("Enter the first string: ");
  fgets(s1, sizeof(s1), stdin);

  printf("Enter the second string: ");
  fgets(s2, sizeof(s2), stdin);

  squeeze(s1, s2);

  printf("%s", s1);

  return 0;
}

void squeeze(char s1[], char s2[]) {
  int i, j;
  char temp[BUFFER] = {0};

  /* Iterates through s2 string and increase the counter of the characters
   * found in s2 string*/
  for (i = 0; s2[i] != '\0' && s2[i] != '\n'; i++)
    ++temp[(unsigned char)s2[i]];

  for (i = 0, j = 0; i < LENGTH; i++)
    if (!temp[(unsigned char)s1[i]])
      s1[j++] = s1[i];

  s1[j] = '\0';
}
