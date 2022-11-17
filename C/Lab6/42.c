#include <stdio.h>
#include <stdlib.h>

typedef struct knoop knoop;
struct knoop {
  int getal;
  knoop *volgend;
};

void voeg_getal_toe(int, knoop **);
void verwijder(int, knoop **);

int main() {
  knoop *k;
  k->getal = 5;
  voeg_getal_toe(6, &k);
  voeg_getal_toe(7, &k);
  verwijder(6, &k);
  return 0;
}

void voeg_getal_toe(int getal, knoop **pl) {
  while (*pl && (*pl)->getal < getal) {
    pl = &((*pl)->volgend);
  }
  knoop *naar_achter = *pl;
  *pl = malloc(sizeof(knoop));
  (*pl)->getal = getal;
  (*pl)->volgend = naar_achter;
}

void verwijder(int x, knoop **pl) {
  while (*pl && (*pl)->getal < x) {
    pl = &((*pl)->volgend);
  }
  if (*pl && (*pl)->getal == x) {
    knoop *te_verwijderen = *pl;
    *pl = (*pl)->volgend;
    free(te_verwijderen);
  }
}