#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int number;
  if (argc != 2 || !strcmp(argv[1], "-h")) {
    printf("Usage : %s <number>\n", argv[0]);
    printf("Prints out a number\n");
    return 1;
  }

  number = atoi(argv[1]);
  printf("You entered %d\n", number);
  return 0;
}
