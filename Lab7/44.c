#include <stdio.h>

typedef unsigned int uint;

uint reverse(uint g) {
  uint res = 0;
  while (g) {
    res <<= 4;
    res |= (g & 0xF);
    g >>= 4;
  }
  return res;
}

uint wijzig_eerste_cijfer(uint g) {
  g = reverse(g) | 15;
  return reverse(g);
}

int main() {
  printf("%x\n", wijzig_eerste_cijfer(0x5391));
  return 0;
}