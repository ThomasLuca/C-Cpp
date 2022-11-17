#include <stdio.h>

int ggd(int a, int b) {
  if (!b) return a;
  return ggd(b, (a % b));
}

int zijn_onderling_ondeelbaar(int a, int b) { return ggd(a, b) == 1; }

void print_onderling_ondeelbaar(int a, int b) {
  int g1 = a;
  int g2 = a + 1;
  while (g1 != b && g2 <= b) {
    if (zijn_onderling_ondeelbaar(g1, g2) == 1) {
      printf("[%d, %d], ", g1, g2);
    }
    if (g1 < g2 - 1) {
      g1++;
    } else {
      g2++;
      g1 = a;
    }
  }
}

int main() {
  printf("ggd(-6,-8) = %d\n", ggd(-6, -8));
  printf("ggd(24,18) = %d\n", ggd(24, 18));
  printf("ggd( 0,-5) = %d\n", ggd(0, -5));
  printf("ggd(6,-35) = %d\n", ggd(6, -35));

  print_onderling_ondeelbaar(10, 20);

  return 0;
}
