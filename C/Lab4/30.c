#include <stdio.h>
#include <string.h>

int cmp_int(const void *x, const void *y) {
  return *(const int *)x == *(const int *)y ? 0 : 1;
}

int cmp_cstring(const void *x, const void *y) {
  return strcmp((const char *)x, (const char *)y);
}

int array_bevat_dubbels_na_elkaar(const void *a, size_t len, size_t grootte,
                                  int (*compare)(const void *, const void *)) {
  for (int i = 0; i < len; i++) {
    if (compare(((const char *)a + i * grootte),
                (const char *)a + (i + 1) * grootte) == 0)
      return 1;
  }
  return 0;
}

int main() {
  int getallen_ja[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 11};
  int getallen_neen[] = {1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 3, 4, 5};
  char *woorden_ja[] = {"leentje", "leerde", "lotje", "lopen",
                        "lopen",   "langs",  "de",    "lindelaan"};
  char *woorden_neen[] = {"wie", "goed", "doet", "goed", "ontmoet"};

  char dbls[] = "Deze array bevat dubbels na elkaar\n";
  char no_dbls[] = "Deze array bevat geen dubbels na elkaar\n";

  // voor elk van deze vier arrays wordt er opgeroepen:
  array_bevat_dubbels_na_elkaar(getallen_ja,
                                sizeof(getallen_ja) / sizeof(getallen_ja[0]),
                                sizeof(int), cmp_int)
      ? puts(dbls)
      : puts(no_dbls);

  array_bevat_dubbels_na_elkaar(getallen_neen,
                                sizeof(getallen_ja) / sizeof(getallen_neen[0]),
                                sizeof(int), cmp_int)
      ? puts(dbls)
      : puts(no_dbls);

  array_bevat_dubbels_na_elkaar(woorden_ja, sizeof(woorden_ja) / sizeof(char *),
                                sizeof(char *), cmp_cstring)
      ? puts(dbls)
      : puts(no_dbls);

  array_bevat_dubbels_na_elkaar(woorden_neen,
                                sizeof(woorden_neen) / sizeof(char *),
                                sizeof(char *), cmp_cstring)
      ? puts(dbls)
      : puts(no_dbls);

  return 0;
}