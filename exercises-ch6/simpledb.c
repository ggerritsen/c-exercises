#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE (5)
#define ERROR_OUT_OF_MEMORY (-2)
#define ERROR_PERSON_NOT_FOUND (-3)

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

const person_t *find_person(const char *name) {
  int i;
  for (i = 0; i < current_index; i++) {
    if (!strcmp(database[i].name, name)) {
      return &database[i];
    }  
  }
  return NULL;
}

int remove_person(const char *name) {
  int i;
  for (i = 0; i < current_index; i++) {
    if (!strcmp(database[i].name, name)) {
      break;
    }
  }

  if (i == current_index) {
    return ERROR_PERSON_NOT_FOUND;
  }

  finalize_person(&database[i]);
  for (; i < current_index; i++) {
    database[i] = database[i + 1];
  }
  current_index--;
  return 0;
}

void print_database() {
  int i;
  for (i = 0; i < current_size; i++) {
    printf("%d: %s\n", i, database[i].name);
  }
}

int main(void) {

  person_t *insertPerson = malloc(sizeof(person_t));
  char input[256];
  char address[256];
  
  printf("Insert a new person with address\n");
  scanf("%s %s", input, address);
  init_person(insertPerson, &input[0], &address[0]);
  insert_person(insertPerson);
  printf("Inserted person: %s, %s\n", insertPerson->name, insertPerson->address);
  
  print_database();

  char nameToFind[256];
  printf("Find a person with name:\n");
  scanf("%s", nameToFind);

  person_t *foundPerson = find_person(nameToFind);
  if (!foundPerson) {
    printf("Did not find a person with name '%s'\n", nameToFind);
  } else {
    printf("Found this person with name %s: [%s, %s]\n", nameToFind, foundPerson->name, foundPerson->address);
  }

  char nameToRemove[256];
  printf("Remove a person with name:\n");
  scanf("%s", nameToRemove);
  printf("Return code when removing: %d\n", remove_person(nameToRemove));
  
  print_database();

  return 0;
}
