#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0));
  int rij[26] = {0};

  // Generate random values
  printf("Rand values: ");
  for(int i = 0; i < 20; i++) {
    int rnd_indx = rand() % 26;
    printf("%d, ", rnd_indx + 100);
    rij[rnd_indx]++;
  }
  printf("\n");

  // Print remaining values in array
  printf("Remaining: ");
  for(int i = 0; i < 26; i++) {
    if(rij[i]<1)
      printf("%d, ", i+100);
  }
  printf("\n");

  return 0;
}
