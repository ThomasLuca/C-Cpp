#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *lees() {
  const int MAX_WC = 1000;
  char text[MAX_WC];

  fgets(text, MAX_WC, stdin);
  // Remove newline read by fgets
  text[strcspn(text, "\n")] = '\0';

  // Clear input buffer if it exceeds fgets range
  if (strlen(text) == MAX_WC - 1)
    while ((getchar() != '\n'))
      ;

  char *output = malloc(strlen(text) + 1);
  strcpy(output, text);
  return output;
}

int main() {
  for (int i = 0; i < 5; i++) {
    char *tekst = lees();
    printf("Ik las ***%s*** \n", tekst);
    free(tekst);
  }
  return 0;
}