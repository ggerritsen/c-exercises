#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int factorial(int input) {
  if (input == 1) return 1;
  else return input * factorial(input - 1);
}

int main(int argc, char *argv[]) {
  int number;
  if (argc != 2 || !strcmp(argv[1], "-h")) {
    printf("Usage : %s <number>\n", argv[0]);
    printf("Prints out the factorial of a number\n");
    return 1;
  }

  number = factorial(atoi(argv[1]));
  printf("The factorial of %s is %d\n", argv[1], number);
  return 0;
}
