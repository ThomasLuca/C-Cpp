#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long faculty(int n) {
  long long res = 1;
  for (int i = 1; i <= n; i++)
    res *= i;
  return res;
}

int main() {
  srand(time(0));

  /* for (int i = 2; i <= 30; i++) */
  /*   printf("Factorial %d = %lld\n", i, faculty(i)); */

  /* int r = rand() % 18 + 2; */
  /* printf("Factorial %d = %lld\n", r, faculty(r)); */

  int userInput;
  do {
    printf("Input [2, 20]: ");
    scanf("%d", &userInput);
  } while (userInput > 20 || userInput < 2);
  printf("Factorial %d = %lld\n", userInput, faculty(userInput));

  return 0;
}
