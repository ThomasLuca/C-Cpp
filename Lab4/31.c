#include <stdio.h>
#include <string.h>

void format_name(char *s, size_t len) {
  if (*s >= 'a' && *s <= 'z')
    *s = *s + ('A' - 'a');
}

int main(int argc, char **argv) {

  if (argc == 1) {
    printf("Dag Allemaal!\n");
    return 0;
  }

  for (int i = 1; i < argc; i++) {
    format_name(argv[i], strlen(argv[i]));
    printf("Dag %s!\n", argv[i]);
  }

  return 0;
}