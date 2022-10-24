#include <stdio.h>
#include <string.h>

void schrijf_cstring(const void *e) { printf("%s", *(const char **)e); }

void schrijf_int(const void *e) { printf("%d", *(const int *)e); }

void schrijf_double(const void *e) { printf("%1.1lf", *(const double *)e); }

void schrijf_array(const void *t, int aantal, int grootte, char tussenteken,
                   void (*schrijf)(const void *)) {
  for (int i = 0; i < aantal; i++) {
    schrijf((const char *)t + i * grootte);
    printf("%c", tussenteken);
  }
  printf("\n");
}

int main() {
  char *namen[] = {"Evi", "Jaro", "Timen", "Youri", "Ashaf", "Jennifer"};
  int leeftijden[] = {21, 30, 18, 14, 22, 19};
  double scores[] = {0.5, 1.6, 8.2, -2.4};

  // TODO: fix grootte van c-string
  schrijf_array(namen, sizeof(namen) / sizeof(char *), sizeof(char *), '|',
                schrijf_cstring);

  schrijf_array(leeftijden, sizeof(leeftijden) / sizeof(int), sizeof(int), '.',
                schrijf_int);

  schrijf_array(scores, sizeof(scores) / sizeof(double), sizeof(double), '~',
                schrijf_double);

  return 0;
}