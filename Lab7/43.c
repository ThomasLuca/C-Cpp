#include <stdio.h>

typedef unsigned int uint;

int bit_i(uint x, int i) { return (x >> i) & 1; }

int eenbit(int i) { return 1 << i; }

int aantal_eenbits(uint x) {
  int eenbits = 0;
  uint total = 0;
  uint currentbit = x;
  int i = 0;
  while (total != x) {
    if (currentbit & 1) {
      eenbits++;
      total |= (1 << i);
    }
    i++;
    currentbit >>= 1;
  }
  return eenbits;
}

uint bit_i_aangezet(uint x, int i) { return x | (1 << i); }

uint bit_i_uitgezet(uint x, int i) { return x & ~(1 << i); }

uint bit_i_gewisseld(uint x, int i) { return x ^ (1 << i); }

int zijn_verschillend(uint x, uint y) { return (x ^ y) == 0 ? 0 : 1; }

int is_even(uint x) { return !(x & 1); }

int main() {
  printf("Bit i: %d\n", bit_i(8, 3));
  printf("eenbit: %d\n", eenbit(3));
  printf("Aantal eenbits: %d\n", aantal_eenbits(7));
  printf("Bit i aangezet: %d\n", bit_i_aangezet(8, 5));
  printf("Bit i uitgezet: %d\n", bit_i_uitgezet(15, 2));
  printf("Bit i gewisseld: %d\n", bit_i_gewisseld(15, 4));
  printf("Zijn verschillend: %d\n", zijn_verschillend(15, 15));
  printf("Is even: %d\n", is_even(15));

  return 0;
}

