#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(const char *s1, const char *s2) {
  const size_t len1 = strlen(s1);
  const size_t len2 = strlen(s2);
  char *result = malloc(len1 + len2 + 1); // +1 for the null-terminator
  if (result == NULL) {
    printf("Fatal: Failed to allocate memory.\n");
    abort();
  }
  memcpy(result, s1, len1);
  memcpy(result + len1, s2, len2 + 1); // +1 to copy the null-terminator
  return result;
}

void print_help(char *argv[]) {
  printf("You have to provide two arguments!\n"
         "%s IN OUT\n"
         "Where IN and OUT are files!\n"
         "Where IN is required and OUT is not! Out defaults to IN+language\n",
         argv[0]);
}
