#include <iostream>
#include <memory>
using namespace std;

void schrijf(unique_ptr<string> pn[], int aantal) {
  cout << *pn[0];
  for (int i = 1; i < aantal; i++) {
    cout << " - " << *pn[i]; 
  }
  cout << endl;
}

void verwijder(unique_ptr<string> pn[], int aantal, int volgnr) {
  for (int i = volgnr; i < aantal - 1; i++) {
    pn[i].swap(pn[i+1]);
  }
  pn[aantal-1].reset();
}

int main() {
  string namen[] = {"Rein", "Ada", "Eppo", "Pascal", "Ilse"};
  unique_ptr<string> pnamen[5];
  for (int i = 0; i < 5; i++) {
    pnamen[i] = make_unique<string>(namen[i]);
  }

  schrijf(pnamen, 5);
  verwijder(pnamen, 5, 1);
  schrijf(pnamen, 4);

  return 0;
}