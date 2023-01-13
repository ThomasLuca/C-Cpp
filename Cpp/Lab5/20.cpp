#include "ex19/gekleurd.h"
#include "ex19/rechthoek.h"
#include "ex19/vierkant.h"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

ostream &operator<<(ostream &out, const Rechthoek &rh) {
  rh.print(out);
  return out;
}

int main() {
  Rechthoek r2(4, 6);
  GekleurdeRechthoek gr1;
  GekleurdeRechthoek gr3(6, 9, "rood");
  Vierkant v2(10);

  vector<unique_ptr<Rechthoek>> v;
  v.push_back(make_unique<Rechthoek>(r2));
  v.push_back(make_unique<GekleurdeRechthoek>(gr1));
  v.push_back(make_unique<GekleurdeRechthoek>(gr3));
  v.push_back(make_unique<Vierkant>(v2));

  for (int i = 0; i < v.size(); i++) {
    cout << *v[i];
    cout << " oppervlakte: " << v[i]->oppervlakte() << endl
         << " omtrek: " << v[i]->omtrek() << endl;
  }

  return 0;
}
