#include <iostream>
#include "rechthoek.h"
#include "gekleurd.h"
#include "vierkant.h"

using namespace std;

ostream& operator << (ostream &out, const Rechthoek &rh) {
   rh.print(out);
   return out;
}

int main() {
  Rechthoek r1;
  r1.print(cout);
  cout << "  oppervlakte: " << r1.oppervlakte() << endl
       << "  omtrek: " << r1.omtrek() << endl;

  Rechthoek r2(4,6);
  cout << r2;
  cout << "  oppervlakte: " << r2.oppervlakte() << endl
       << "  omtrek: " << r2.omtrek() << endl;

  GekleurdeRechthoek gr1;
  gr1.print(cout);
  cout << "  oppervlakte: " << gr1.oppervlakte() << endl
       << "  omtrek: " << gr1.omtrek() << endl;

  GekleurdeRechthoek gr2(5,7);
  cout << gr2;
  cout << "  oppervlakte: " << gr2.oppervlakte() << endl
       << "  omtrek: " << gr2.omtrek() << endl;

  GekleurdeRechthoek gr3(6,9,"rood");
  gr3.print(cout);
  cout << "  oppervlakte: " << gr3.oppervlakte() << endl
       << "  omtrek: " << gr3.omtrek() << endl;

  Vierkant v1;
  cout << v1;
  cout << "  oppervlakte: " << v1.oppervlakte() << endl
       << "  omtrek: " << v1.omtrek() << endl;

  Vierkant v2(10);
  v2.print(cout);
  cout << "  oppervlakte: " << v2.oppervlakte() << endl
       << "  omtrek: " << v2.omtrek() << endl;

  return 0;
}
