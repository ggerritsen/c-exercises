#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  printf("strcmp works like this:\n");
  printf("strcmp(test, test) is: %d\n", strcmp("test", "test"));
  printf("strcmp(geert, NaN) is: %d\n", strcmp("geert", "NaN"));

  printf("booleans work like this:\n");
  if (0) {
    printf("0 is true, 1 is false\n");
  }
  if (1) {
    printf("1 is true, 0 is false\n");
  }

  return 0;
}
