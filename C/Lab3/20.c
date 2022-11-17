#include <stdio.h>

void zoek_extremen(int t[], int n, int *min, int *max) {
  int mn = 0;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    int val = t[i];
    if (val < mn)
      mn = val;
    if (val > mx)
      mx = val;
  }
  *min = mn;
  *max = mx;
}

int main() {
  int arr[] = {1, 5, 6, 7, -8, 9, 5, 3, 111, 5, 95};
  int arr_len = sizeof(arr) / sizeof(int);
  int m, n;

  zoek_extremen(arr, arr_len, &m, &n);
  printf("Max: %d, Min: %d\n", m, n);

  return 0;
}