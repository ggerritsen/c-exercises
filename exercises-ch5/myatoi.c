#include <stdio.h>
#include "mystrlen.h"
#include <math.h>

int myatoi(char input[]) {
  if (input[0] == 0) return 0;
  else {
    int length = mystrlen(input);
    int modifier = pow(10, (length - 1));
    return (input[0] - 48) * modifier + myatoi(&input[1]);
  }
}

int main(int argc, char *argv[]) {
  printf("myatoi of %s is: %d\n", argv[1], myatoi(argv[1]));
  return 0;
}
