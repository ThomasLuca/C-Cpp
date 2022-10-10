#include <stdio.h>

void schrijf_even_posities(char l[], int l_size) {
  for(int i=0; i < l_size - 1; i+=2) {
    printf("%c", l[i]);
  }
    printf("\n");
}

int main() {
  char letters[] = {'p', 'o', 'r', 'e', 'o', 'i', 'f', 'o', 'i',
                    'e', 'c', 'i', 'i', ':', 'a', '-', 't', '('};

  int letters_length = sizeof(letters) / sizeof(letters[0]);

  printf("Size of letters: %d\n", letters_length);

  schrijf_even_posities(letters, letters_length);

  return 0;
}
