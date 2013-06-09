#include <stdio.h>

int signum(double x) {
  if (x < 0) return -1;
  else if (x == 0) return 0;
  else return 1;
}

int main(void) {
  printf("Hello\n");
  printf("Signum of -6 is: %d\n", signum(-6));
  printf("Signum of 0 is: %d\n", signum(0));
  printf("Signum of 3 is: %d\n", signum(3));
  return 0;
}
