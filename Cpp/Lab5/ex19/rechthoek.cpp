#include "rechthoek.h"

Rechthoek::Rechthoek(int _h, int _b) : hoogte{_h}, breedte{_b} {};

Rechthoek::Rechthoek() : Rechthoek(1, 1){};

int Rechthoek::omtrek() const { return 2 * hoogte + 2 * breedte; }

int Rechthoek::oppervlakte() const { return hoogte * breedte; }

void Rechthoek::print(std::ostream &out) const {
  out << "Rechthoek: " << hoogte << " op " << breedte << std::endl;
}
