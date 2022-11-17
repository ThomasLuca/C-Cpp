#include <stdio.h>
#include <stdlib.h>

typedef struct knoop knoop;
struct knoop {
  int getal;
  knoop *volgend;
};

void voeg_getal_toe(int, knoop **);

int main() { 
  knoop *k; 
  voeg_getal_toe(6, &k);
  voeg_getal_toe(7, &k);
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