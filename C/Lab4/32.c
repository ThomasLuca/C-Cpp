#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void format_name(char *s, size_t len) {
  if (*s >= 'a' && *s <= 'z')
    *s = *s + ('A' - 'a');
}

int compar_cstring(const void *x, const void *y) {
  return strcmp(*(const char **)x, *(const char **)y);
}

char *alfab_kleinste(char **voornamen, size_t len) {
  qsort(voornamen, len, sizeof(char *), compar_cstring);
  // For some reason executable name is at index 0
  return voornamen[1];
}

int main(int argc, char **argv) {

  if (argc <= 1) {
    printf("Dag Allemaal!\n");
    return 0;
  }

  char *name = alfab_kleinste(argv, argc);
  format_name(name, strlen(name));
  printf("Dag %s!\n", name);

  return 0;
}