#include <stdio.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

int printArray(int numbers[]) {
  if (numbers[0] == 0) {
    return 0;
  }
  printf("%d,", numbers[0]);
  return printArray(&numbers[1]);
}

int main() {
  int input[] = {12, 1, 25};
  printf("Input is: ");
  printArray(input);
  printf(". Output is: ");
  printArray(input);
  printf(".\n");
  return 0;
}
