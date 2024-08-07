/* Exercise 2.5: Write the function any(s1, s2), which returns the first
 * location in the string s1 where any character from s2 occurs, or -1 if s1
 * contains no characters from s2. ( The standard library strpbrk does the same
 * job but returns a pointer to the location.)*/

#include <stdio.h>

#define LENGTH 1000 /* Buffer length for input string */

int any(char s1[], char s2[]);

int main(void) {
  int ptr;
  char s1[LENGTH], s2[LENGTH];

  printf("Enter the first string: ");
  fgets(s1, sizeof(s1), stdin);

  printf("Enter the second string: ");
  fgets(s2, sizeof(s2), stdin);

  ptr = any(s1, s2);
  printf("%d\n", ptr);

  return 0;
}

int any(char s1[], char s2[]) {
  int i, j, ptr;

  for (i = 0; s1[i] != '\0' && s1[i] != '\n'; i++)
    for (j = 0; s2[j] != '\0' && s2[j] != 'n'; j++)
      if (s1[i] == s2[j]) {
        return i;
      }

  return -1;
}
