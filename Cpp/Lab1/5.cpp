#include <iostream>
#include <strings.h>
using namespace std;

typedef struct persoon persoon;
struct persoon {
  string naam;
  int leeftijd;
  int lengte;
};

int grootte(const string s) { return s.length(); }

double grootte(const double d) { return d; }

int grootte(const int i) { return i; }

int grootte(const persoon p) { return p.leeftijd; }

template <typename T> T grootste(const T *arr, int lengte) {
  double g = grootte(arr[0]);
  T g_elem = arr[0];
  for (int i = 1; i < lengte; i++) {
    if (grootte(arr[i]) > g) {
      g = grootte(arr[i]);
      g_elem = arr[i];
    }
  }
  return g_elem;
}

void initialiseer(persoon *pers, string naam, int leeftijd, int lengte) {
  pers->naam = naam;
  pers->leeftijd = leeftijd;
  pers->lengte = lengte;
}

void print(const persoon &pers) {
  cout << "Name: " << pers.naam << "\tAge: " << pers.leeftijd
       << "\tHeight: " << pers.lengte << endl;
}

int main() {
  double getallen[5] = {5.5, 7.7, 2.2, 9.9, 9.8};
  string woorden[3] = {"geloof", "hoop", "de liefde"};
  persoon peeps[3];
  initialiseer(&peeps[0], "Bob", 50, 180);
  initialiseer(&peeps[1], "Billy", 1, 100);
  initialiseer(&peeps[2], "Marley", 3, 30);

  print(peeps[2]);

  cout << "Het grootste woord is: " << grootste(woorden, 3) << "." << endl;
  cout << "Oudste persoon is: " << grootste(peeps, 3).naam << endl;
  return 0;
}