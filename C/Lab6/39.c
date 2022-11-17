#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct knoop knoop;

struct knoop {
  int getal;
  knoop *volgend;
};

void voeg_vooraan_toe(int, knoop **);
knoop *maak_gesorteerde_lijst_automatisch(int, int);
void print_lijst(const knoop *);
void verwijder_dubbels(knoop **);

int main() {
  srand(time(NULL));
  knoop *l = maak_gesorteerde_lijst_automatisch(50, 100);
  print_lijst(l);
  printf("\nnu worden dubbels verwijderd \n");
  verwijder_dubbels(&l);
  printf("\nna verwijderen van dubbels: \n\n");
  print_lijst(l);
  return 0;
}

void voeg_vooraan_toe(int value, knoop **list) {
  knoop *new = (knoop *)malloc(sizeof(knoop));
  new->getal = value;
  new->volgend = *list;
  *list = new;
}

knoop *maak_gesorteerde_lijst_automatisch(int n, int bovengrens) {
  int value = bovengrens;
  knoop *tail = malloc(sizeof(knoop));
  tail->getal = value;
  tail->volgend = NULL;

  int max_decrement = bovengrens / n;

  for (int i = 1; i < n; i++) {
    int rnd = (int)rand() % max_decrement;
    value -= rnd;
    voeg_vooraan_toe(value, &tail);
  }
  return tail;
}

void print_lijst(const knoop *list) {
  while (list) {
    printf("%d - ", list->getal);
    list = list->volgend;
  }
  printf("\n");
}

void verwijder_dubbels(knoop **l) {
  knoop *ll = *l;
  while (ll->volgend) {
    int current = ll->getal;
    int next = ll->volgend->getal;
    if (current == next && ll->volgend->volgend) {
      knoop *m = ll->volgend;
      while (m->getal == current)
        m = m->volgend;
      ll->volgend = m->volgend;
      free(m);
    }
    ll = ll->volgend;
  }
}
