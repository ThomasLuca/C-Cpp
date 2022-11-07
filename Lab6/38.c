#include <stdio.h>
#include <stdlib.h>

typedef struct knoop knoop;
struct knoop {
  int getal;
  knoop *volgend;
};

void voeg_vooraan_toe(int value, knoop **list) {
  knoop *new = (knoop *)malloc(sizeof(knoop));
  new->getal = value;
  new->volgend = *list;
  *list = new;
}

void print_lijst(const knoop *list) { 
  while(list) {
    printf("%d\t", list->getal);
    list = list->volgend;
  }
  printf("\n");
}

int main() {
  knoop *lst = 0;
  voeg_vooraan_toe(7, &lst);
  voeg_vooraan_toe(3, &lst);
  print_lijst(lst);
  return 0;
}