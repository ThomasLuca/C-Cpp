#include <stdio.h>

int main() {
  int t[6] = {0, 10, 20, 30, 40, 50};
  int *pt[3];

  for (int i = 0; i < 3; i++) {
    pt[i] = &t[2 * i];
  }

  pt[1]++;
  pt[2] = pt[1];
  *pt[1] += 1;
  *pt[2] *= 2;
  int **ppt = &pt[0];
  (*ppt)++;
  **ppt += 1;

  for (int i = 0; i < sizeof(t) / sizeof(int); i++) {
    printf("%d ", t[i]);
  }
  printf("\n");
  for (int i = 0; i < sizeof(pt) / sizeof(int *); i++) {
    printf("%d ", *pt[i]);
  }
  printf("\n");
  return 0;
}
