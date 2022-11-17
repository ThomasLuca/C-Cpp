#include <stdio.h>

int main() {
  printf("Type 5 numbers (exit when number is negative): ");

  int sum = 0;
  int succesfull_answers = 0;
  int res;

  // Read in answers
  while(succesfull_answers < 5 && scanf("%d", &res) && res >= 0){
    sum += res;
    succesfull_answers++;
  }

  // Clear input buffer for future use
  while(getchar() != '\n');

  printf("Sum: \t%d\n", sum);

  return 0;
}
