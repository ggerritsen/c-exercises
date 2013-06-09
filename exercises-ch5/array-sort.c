#include <stdio.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

int bubbleSort(int numbers[], int length) {
  int swaps = 0;
  int i, j;
  for (i = 0, j = 1; j < length; i++, j++) {
    int first = numbers[i];
    int second = numbers[j];
    if (first > second) {
      // swap
      numbers[i] = second;
      numbers[j] = first;
      swaps++;
    }
  }
  return swaps;
}

int arraySort(int numbers[], int length) {
  int iterations;
  do {
    iterations = bubbleSort(numbers, length);
  } while (iterations > 0);
  return 0;
}

int printArray(int numbers[], int length) {
  int i;
  printf("{");
  for (i = 0; i < length; i++) {
    printf("%d,", numbers[i]);
  }
  printf("}");
  return 0;
}

int main() {
  int input[] = {12, 1, 25, 9109, -343};
  int length = ARRAY_SIZE(input);
  printf("Input is: ");
  printArray(input, length);
  
  arraySort(input, length);
  printf(". Output is: ");
  printArray(input, length);
  printf(".\n");
  return 0;
}
