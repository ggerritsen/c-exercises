#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBER_OF_PEOPLE (100)
#define ERROR_DATABASE_FULL (-1)

typedef struct {
  char *name;
  char *address;
} person_t;

void init_person(person_t *p, const char *name, const char *address) {
  p->name = strdup(name);
  p->address = strdup(address);
}

void finalize_person(person_t *p) {
  free(p->name);
  free(p->address);
}

person_t database[MAX_NUMBER_OF_PEOPLE];
int current_index = 0;

int insert_person(person_t *p) {
  if (current_index == MAX_NUMBER_OF_PEOPLE) {
    return ERROR_DATABASE_FULL;
  }
  database[current_index++] = *p;
  return 0;
}

int main(void) {

  person_t *insertPerson = malloc(sizeof(person_t));
  char input[256];
  char defaultAddress[] = "address";
  
  printf("Insert a new person\n");
  scanf("%s", input);
  init_person(insertPerson, &input[0], &defaultAddress[0]);
  printf("Inserted person: %s, %s\n", insertPerson->name, insertPerson->address);
  
  return 0;
}
