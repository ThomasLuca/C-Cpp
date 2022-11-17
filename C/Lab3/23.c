#include <stdio.h>

void schrijf_aantal(char arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%c", arr[i]);
  }
  printf("\n");
}

void schrijf(char *start, char *end) { schrijf_aantal(start, end - start); }

void pivoteer(char *begin, char *einde, char *pivot) {
  /* int diff = einde - begin; */
  int rel = einde - pivot < pivot - begin ? einde - pivot : pivot - begin;

  for (int i = 0; i <= rel; i++) {
    char tmp = *(pivot - i);
    *(pivot - i) = *(pivot + i);
    *(pivot + i) = tmp;
  }
}

int main() {
  char tekst[] = {'b', 'd', '?', 'z', 'g', 'o', 'e', 'z', 'e', 'b',
                  ' ', 'd', 'i', 'g', '!', 'h', 'o', 's', 'v'};
  pivoteer(tekst + 7, tekst + 12, tekst + 9);
  schrijf(tekst + 4, tekst + 15);
  return 0;
}
