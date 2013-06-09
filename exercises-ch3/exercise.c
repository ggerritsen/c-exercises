#include <stdio.h>
#include <math.h>

double cube(double input) {
  return input * input * input;
}

double hypothenusa(double x, double y) {
  return sqrt(x * x + y * y);
}

int main(void) {
  double a = 1;
  int b = 2;
  double c = a/b;

  printf("This is the value: %f\n", c);

  printf("Cube(3) should be 27: %f\n", cube(3));

  printf("Hypothenusa of 3 and 4 should be 5: %f\n", hypothenusa(3, 4));

  return 0;
}
