#include <stdio.h>

void read_chars(int arr[], int arr_size) {
  char usr_char;
  while (1) {
    scanf("%c", &usr_char);
    if (usr_char == '$')
      break;
    if (usr_char >= 'a' && usr_char <= 'z')
      arr[usr_char - 'a']++;
    if (usr_char >= 'A' && usr_char <= 'Z')
      arr[usr_char - 'A']++;
  }
}

void print_horizontal(int arr[], int arr_size) {
  for (int i = 0; i < arr_size; i++) {
    printf("%c: ", 'a' + i);
    for (int j = 0; j < arr[i]; j++) {
      printf("*");
    }
    printf("\n");
  }
}

void print_vertical(int arr[], int arr_size) {
  // Get largest value in array
  int largest = 0;
  for (int i = 0; i < arr_size; i++) {
    largest = arr[i] > largest ? arr[i] : largest;
  }

  while (largest > 0) {
    for (int i = 0; i < arr_size; i++) {
      if (arr[i] >= largest)
        printf("%c", i + 'a');
      else
        printf(" ");
    }
    printf("\n");
    largest--;
  }
}

int main() {
  int alphbt[26] = {0};
  int alphbt_size = 26;
  read_chars(alphbt, alphbt_size);
  print_horizontal(alphbt, alphbt_size);
  printf("---------------------------------------------------\n");
  print_vertical(alphbt, alphbt_size);
  return 0;
}
