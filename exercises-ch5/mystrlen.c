#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mystrlen(char input[]) {
  if (input[0] == 0) return 0;
  else return 1 + mystrlen(&input[1]);
}

int was_main(int argc, char *argv[]) {
  char userInput[30];
  strcpy(userInput, argv[1]);

  printf("Length of the string '%s' is: %d\n", userInput, mystrlen(userInput));
  return 0;
}
