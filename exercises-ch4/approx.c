#include <stdio.h>

int approx_equal(double a, double b, double fraction) {
  return ((b - fraction) <= a && a <= b) || 
    (b <= a && a <= (b + fraction));
}

int main(void) {
  printf("5 is within 0.1 of 5.1: %d\n", approx_equal(5, 5.1, 0.1));
  printf("5 is not within 0.01 of 5.1: %d\n", approx_equal(5, 5.1, 0.01));
  return 0;
}
