#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE (5)
#define ERROR_OUT_OF_MEMORY (-2)

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

person_t *database = NULL;
int current_index = 0;
size_t current_size = 0;

int insert_person(const person_t *p) {
  
  // first call - initialize database
  if (!database) {
    database = malloc(CHUNK_SIZE * sizeof(person_t));
    if (!database) 
      return ERROR_OUT_OF_MEMORY;
    current_size = CHUNK_SIZE;
  }

  // database is full
  if (current_index == current_size) {
    size_t new_size = current_size * CHUNK_SIZE;
    person_t *new_space = realloc(database, new_size * sizeof(person_t));
    if (!new_space) 
      return ERROR_OUT_OF_MEMORY;
    database = new_space;
  }

  database[current_index++] = *p;
  return 0;
}

int main(void) {

  person_t *insertPerson = malloc(sizeof(person_t));
  char input[256];
  char address[256];
  
  printf("Insert a new person with address\n");
  scanf("%s %s", input, address);
  init_person(insertPerson, &input[0], &address[0]);
  printf("Inserted person: %s, %s\n", insertPerson->name, insertPerson->address);
  
  return 0;
}
