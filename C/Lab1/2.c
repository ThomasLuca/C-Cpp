#include <stdio.h>

int main() {
  for (int i = 0; i <= 64; i++) {
    printf("%o\t%d\t%x\n", i, i, i);
  }
  return 0;
}
