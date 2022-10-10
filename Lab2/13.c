#include <stdio.h>

void schuif_links(char arr[], int arr_size) {
  char tmp = arr[0];
  for (int i = 1; i < arr_size; i++) {
    arr[i - 1] = arr[i];
  }
  arr[arr_size - 1] = tmp;
}

void schuif_links_amount(char arr[], int arr_size, int shift_amount) {
  for (int i = 0; i < shift_amount; i++) {
    schuif_links(arr, arr_size);
  }
}

void print_rij(char arr[], int arr_size) {
  for (int i = 0; i < arr_size; i++) {
    printf("%c", arr[i]);
  }
  printf("\n");
}

int main() {
  char rij[] = {'s', 'a', 'p', 'a', 'p', 'p', 'e', 'l'};
  int rij_size = sizeof(rij) / sizeof(rij[0]);

  print_rij(rij, rij_size);
  schuif_links_amount(rij, rij_size, 3);
  print_rij(rij, rij_size);

  return 0;
}
