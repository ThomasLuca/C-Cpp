#include <stdio.h>

void schrijf_aantal(char *arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%c ", *arr++);
  }
}

void schrijf(char *start, char *end) {
  schrijf_aantal(start, end-start);
}

int main(){

    char letters [] = {'p','o','r','g','o','e','d','o','i','e','o','k','i',':','a','-','t','('};
    char *p = letters;

    schrijf_aantal(letters+3,4);
    printf("\n");
    schrijf(p+10,p+12);
    printf("\n");
    return 0;
}
