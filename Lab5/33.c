// Compile with -lm flag to link math library
// gcc ./33.c -o -lm
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct punt punt;

struct punt {
  double x;
  double y;
};

double euclidische_afstand(const punt *p, const punt *q) {
  return sqrt(pow(p->x - q->x, 2) + pow(p->y - q->y, 2));
}

double manhattan_afstand(const punt *p, const punt *q) {
  // abs()-> int, fabs -> double
  return fabs(p->x - q->x) + fabs(p->y - q->y);
}

double chebyshev(const punt *p, const punt *q) {
  return fmax(fabs(p->x - q->x), fabs(p->y - q->y));
}

int distance_compbar(const void *d1, const void *d2) {
  double l = *(const double *)d1;
  double r = *(const double *)d2;
  if (l > r)
    return -1;
  if (r > l)
    return 1;
  return 0;
}

double bepaal_max_afstand(punt **punten, const int aantal,
                          double (*afstand_functie)(const punt *p1,
                                                    const punt *p2)) {

  // for (int i = 0; i < aantal; i++) {
  //   printf("x: %lf  y: %lf\n", punten[i]->x, punten[i]->y);
  // }

  const int len_distances = (aantal * aantal) - aantal;
  double afstanden[len_distances];

  int ndx = 0;
  for (int i = 0; i < aantal; i++) {
    for (int j = 0; j < aantal; j++) {
      if (i == j)
        continue;
      afstanden[ndx++] = afstand_functie(punten[i], punten[j]);
    }
  }

  qsort(afstanden, len_distances, sizeof(double), distance_compbar);
  return afstanden[0];
}

int main() {
  int len_points = 0;
  printf("Number of points to read: ");
  scanf("%d", &len_points);

  // clear input buffer
  while ((getchar()) != '\n')
    ;
  printf("\n");

  punt *punten[len_points];

  for (int i = 0; i < len_points; i++) {
    punt *p;
    p = malloc(sizeof(punt));
    punt tmp;

    printf("Point %d.x: ", i);
    scanf("%lf", &(tmp.x));
    while ((getchar()) != '\n')
      ;

    printf("Point %d.y: ", i);
    scanf("%lf", &(tmp.y));
    while ((getchar()) != '\n')
      ;

    *p = tmp;
    punten[i] = p;
  }

  double max_d = bepaal_max_afstand(punten, len_points, manhattan_afstand);

  printf("Max distance = %lf\n", max_d);

  return 0;
}
