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
knoop *merge(knoop *, int, knoop *, int);

int main() {
  srand(time(NULL));
  int size_m = 10;
  int size_n = 5;
  knoop *m = maak_gesorteerde_lijst_automatisch(size_m, 1000);
  knoop *n = maak_gesorteerde_lijst_automatisch(size_n, 1000);

  printf("\nLIJST m:\n");
  print_lijst(m);
  printf("\nLIJST n:\n");
  print_lijst(n);
  printf("\nDeze worden gemerged.\n");

  knoop *mn = merge(m, size_m, n, size_n);
  printf("\nRESULTAAT: \n");
  print_lijst(mn);
  free(mn);
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
      knoop *k = ll->volgend;
      while (k->getal == current)
        k = k->volgend;
      ll->volgend = k->volgend;
    }
    ll = ll->volgend;
  }
}

knoop *merge(knoop *a, int size_a, knoop *b, int size_b) {
  knoop *c = malloc((size_a + size_b + 1)*sizeof(knoop));
  knoop *c_start = c;
  c->getal = 0;

  while (a || b) {
    if (a && a->getal <= b->getal) {
      c->volgend = a;
      a = a->volgend;
    } else {
      c->volgend = b;
      b = b->volgend;
    }
    c = c->volgend;
  }

  return c_start->volgend;
}
