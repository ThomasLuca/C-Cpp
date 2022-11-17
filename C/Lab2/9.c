#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cijfersom(int lst) {
  int sum = 0;
  while (lst > 0) {
    int digit = lst % 10;
    sum += digit;
    lst /= 10;
  }
  return sum;
};

int main() {
  srand(time(0));

  for (int i = 0; i < 10; i++) {
    int rand_num = rand() % 100000;
    printf("Sum of %d = %d\n", rand_num, cijfersom(rand_num));
  }
  return 0;
}
