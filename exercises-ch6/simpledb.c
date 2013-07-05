#include <stdio.h>

int main(void) {
  char input[80];
  printf("Please insert a Person\n");
  scanf("%79s", &input);
  
  printf("You entered: %s\n", input);
  return 0;
}
