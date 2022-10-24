#include <stdio.h>

void schrijf_aantal(const char *arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%c", *arr++);
  }
}

void schrijf(const char *start, const char *end) {
  schrijf_aantal(start, end - start);
}

const char *pointerNaarEersteKleineLetter(const char *s) {
  const char *p = s;
  while ((*p < 'a' || *p > 'z') && *p != '\0') {
    p++;
  }
  return p;
}

void verzetNaarEersteHoofdletter(const char **s) {
  const char *p = *s;
  while ((*p < 'A' || *p > 'Z') && *p != '\0') {
    p++;
  }
  *s = p;
}

int main() {
  char zus1[50] = "sneeuwWITje";
  char zus2[50] = "rozeROOD";
  const char *begin = zus1;
  verzetNaarEersteHoofdletter(&begin);
  const char *eind = pointerNaarEersteKleineLetter(begin);
  schrijf(begin, eind); /* schrijft 'WIT' uit */
  printf("\n");

  begin = zus2;
  verzetNaarEersteHoofdletter(&begin);
  eind = pointerNaarEersteKleineLetter(begin);
  schrijf(begin, eind); /* schrijft 'ROOD' uit */
  printf("\n");
  return 0;
}
