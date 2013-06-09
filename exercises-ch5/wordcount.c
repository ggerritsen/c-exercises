#include <stdio.h>
#include "mystrlen.h"

#define BOOL int
#define FALSE 0
#define TRUE 1

BOOL isBlank(char someChars[]) {
  int i;
  for (i = 0; i < mystrlen(someChars) - 1; i++) {
    int ch = someChars[i];
    if (ch != 32) {
      return FALSE;
    }
  }
  return TRUE; 
}

int wordcount(char sentence[]) {
  if (isBlank(sentence)) {
    return 0;
  }

  int words = 1;
  int counter = 0;
  int character = sentence[counter];
  while (character != 0) {
    if (character == 32) {
      words++;
      // skip to next word
      do {
        character = sentence[++counter];
      } while (character == 32);
    } else {
      character = sentence[++counter];
    }
  }
  return words;
}

int test(char input[]) {
  printf("The number of words in '%s' is: %d\n", input, wordcount(input));
  return 0;
}

int main(void) {
  test("this   is  a weird    sentence since it does not");
  test("     ");
  return 0;
}
