#include <stdio.h>

int index_van(int t[], int t_size, int g) {
  for (int i = 0; i < t_size; i++) {
    if (t[i] == g)
      return i;
  }
  return -1;
}

int main() {
  int arr[] = {1, 5, 6, 9, 8, 7, 3, 15, 11};
  int userInput;
  do {
    printf("Find number: ");
    while (getchar() != '\n')
      getchar();
    scanf("%d", &userInput);
    printf("\n");
  } while (getchar() != '\n');

  printf("index arr[%d] == %d\n",
         index_van(arr, sizeof(arr) / sizeof(arr[0]), userInput), userInput);
  return 0;
}
