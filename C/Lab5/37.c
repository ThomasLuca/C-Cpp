#include <stdio.h>
#include <stdlib.h>

typedef struct deeltal deeltal;

struct deeltal {
  int waarde;
  int aantal_delers;
  int *delers;
};

void schrijf_ints(const int *, int);
void schrijf_deeltal(deeltal *);
int aantal_delers_van(int);
int *delers_van(int, int);
void lees_deeltal(deeltal *);
int vraag_aantal_deeltallen();
void lees_deeltallen(deeltal **, int);
void schrijf_deeltallen(deeltal **, int);
deeltal *zoek(int, deeltal **, int);
void free_mem(deeltal **, int);

int main() {
  int n = vraag_aantal_deeltallen();
  deeltal **dt = calloc(n, sizeof(deeltal *));
  lees_deeltallen(dt, n);
  schrijf_deeltallen(dt, n);

  deeltal *search_res = zoek(6, dt, n);
  schrijf_deeltal(search_res);

  printf("\nFreeing memory...\n");
  free_mem(dt, n);
  return 0;
}

void schrijf_ints(const int *t, int n) {
  for (int i = 0; i < n - 1; i++) {
    printf("%d-", t[i]);
  }
  printf("%d\n", t[n - 1]);
}

void schrijf_deeltal(deeltal *dt) {
  if (dt->waarde == -1) {
    printf("Deeltal niet gevonden\n");
    free(dt);
    return;
  }
  printf("%d\t", dt->waarde);
  schrijf_ints(dt->delers, dt->aantal_delers);
}

int aantal_delers_van(int x) {
  int count = 0;
  for (int i = 1; i <= (x / 2); i++) {
    if (x % i == 0)
      count++;
  }
  return count;
}

int *delers_van(int x, int aantal) {
  int *delers = calloc(aantal, sizeof(int *));
  int count = 0;
  for (int i = 1; i <= (x / 2); i++) {
    if (x % i == 0)
      delers[count++] = i;
  }
  return delers;
}

void lees_deeltal(deeltal *dt) {
  int input;
  printf("Deeltal: ");
  scanf("%d", &input);

  int n_delers = aantal_delers_van(input);
  dt->waarde = input;
  dt->aantal_delers = aantal_delers_van(input);
  dt->delers = delers_van(input, n_delers);
}

int vraag_aantal_deeltallen() {
  printf("Aantal deeltallen: ");
  int n;
  scanf("%d", &n);
  printf("\n");
  return n;
}

void lees_deeltallen(deeltal **t, int n) {
  for (int i = 0; i < n; i++) {
    deeltal *dt = malloc(sizeof(deeltal));
    lees_deeltal(dt);
    t[i] = dt;
  }
}

void schrijf_deeltallen(deeltal **t, int n) {
  printf("\nDeelers:\n");
  for (int i = 0; i < n; i++) {
    schrijf_deeltal(t[i]);
  }
}

deeltal *zoek(int w, deeltal **t, int n) {
  printf("\nDeeltal met waarde %d?\n", w);
  for (int i = 0; i < n; i++) {
    if (t[i]->waarde == w) {
      deeltal *dt = t[i];
      return dt;
    }
  }

  deeltal *dt_null = malloc(sizeof(deeltal));
  dt_null->waarde = -1;
  dt_null->aantal_delers = -1;
  dt_null->delers = NULL;
  return dt_null;
}

void free_mem(deeltal **t, int n) {
  for (int i = 0; i < n; i++) {
    printf("Free: ");
    schrijf_deeltal(t[i]);
    free(t[i]);
  }
}
