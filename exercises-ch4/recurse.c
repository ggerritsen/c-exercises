#include <stdio.h>

int recurse(int n) {
  if (n <= 0) return 0;
  else return recurse(n - 1);
} 

int main(void) {
  int input = 262071;
  recurse(input);
  printf("reached 0 for input: %d\n", input);
  
  return 0;
}
