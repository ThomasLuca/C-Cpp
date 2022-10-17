#include <stdio.h>

int *plaats_van(int t[], int n, int g) {
  for (int i = 0; i < n; i++) {
    if (t[i] == g)
      return &t[i];
  }
  return NULL;
}

int *plaats_ptr_op_getal(int *p, int n, int g) {
  for (int i = 0; i < n; i++) {
    if (*p == g)
      return p;
    p++;
  }
  return NULL;
}

int main() {
  int arr[] = {1, 5, 6, -9, 8, 7, 3, 15, 11};
  int userInput = 8;

  int *p = plaats_ptr_op_getal(arr, sizeof(arr) / sizeof(int), userInput);
  int *end = &arr[sizeof(arr) / sizeof(int) - 1];

  if (p == NULL) {
    printf("Value: %d does not exist in array.\n", userInput);
  } else {
    printf("Value: %d does exist in array.\nDouble = %d\nPrev: %d\n", userInput,
           (*p) * 2, p[-1]);

    printf("Rest: ");
    for (int i = 0; i < end-p; i++) {
      printf("%d ", p[i]);
    }
    printf("\n");
  }

  return 0;
}
