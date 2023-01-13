#include "gekleurdvierkant.h"
#include <iostream>
using namespace std;

ostream &operator<<(ostream &out, const GekleurdVierkant &v) {
  v.print(out);
  return out;
}

int main() {
  GekleurdVierkant gv1;
  cout << gv1;
  cout << "  oppervlakte: " << gv1.Vierkant::oppervlakte() << endl
       << "  omtrek: " << gv1.Vierkant::omtrek() << endl;

  GekleurdVierkant gv2(12);
  gv2.print(cout);
  cout << "  oppervlakte: " << gv2.Vierkant::oppervlakte() << endl
       << "  omtrek: " << gv2.GekleurdeRechthoek::omtrek() << endl;

  GekleurdVierkant gv3(15, "geel");
  cout << gv3;
  cout << "  oppervlakte: " << gv3.GekleurdeRechthoek::oppervlakte() << endl
       << "  omtrek: " << gv3.GekleurdeRechthoek::omtrek() << endl;

  return 0;
}
