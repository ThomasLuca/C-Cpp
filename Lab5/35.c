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

char **lees_meerdere(const int n) {
  char **leeslist = calloc(n + 1, sizeof(char *));
  leeslist[n] = (char *)NULL;
  for (int i = 0; i < n; i++) {
    leeslist[i] = lees();
  }
  return leeslist;
}

int main() {
  const int N = 2;
  char **ll = lees_meerdere(N);
  for (int i = 0; i < N; i++) {
    printf("Ik las ***%s*** \n", ll[i]);
    free(ll[i]);
  }
  free(ll);
  return 0;
}