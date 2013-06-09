#include <stdio.h>

int factorial(int input) {
  if (input == 1) return 1;
  else return input * factorial(input - 1);
}

int main(void) {
  int input;
  for (input = 1; input <= 5; input++) {
    printf("Factorial of %d is: %d\n", input, factorial(input));
  }
  
  return 0;
}
