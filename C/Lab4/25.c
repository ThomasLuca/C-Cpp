#include <ctype.h>
#include <stdio.h>

int aantal_verschillende_letters(const char *s, size_t len) {
  int uniques = 0;
  for (int i = 0; i < len; i++) {
    int occurences = 0;
    for (int j = 0; j < len; j++) {
      if (tolower(s[i]) == tolower(s[j]))
        occurences++;
    }
    if (occurences <= 1)
      uniques++;
  }
  return uniques;
}

int main() {
  char str[] = "foobasbar";
  int diff = aantal_verschillende_letters(str, sizeof(str) / sizeof(char));
  printf("Unieke karakters: %d\n", diff);
  return 0;
}
