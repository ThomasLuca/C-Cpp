#include <math.h>
#include <stdio.h>

double faculty(int n) {
  long double res = 1;
  for (int i = 1; i <= n; i++)
    res *= i;
  return res;
}

double dpow(double d, int pw) {
  double res = 1;
  for (int i = 0; i < pw; i++) {
    res *= d;
  }
  return res;
}

double sinus(double x) {
  double res = 0;
  for (int i = 0; i < 10; i++) {
    if (i % 2) {
      res -= ((1 * dpow(x, 2 * i + 1)) / faculty(2 * i + 1));
    } else {
      res += ((1 * dpow(x, 2 * i + 1)) / faculty(2 * i + 1));
    }
  }
  return res;
}

int main() {
  /* double x = 0.23; */
  double x = 8.2;
  printf("Sin <custom> %f: %.32f\n", x, sinus(x));
  printf("Sin <math.h> %f: %.32f\n", x, sin(x));

  return 0;
}
