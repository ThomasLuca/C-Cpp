#include "vierkant.h"

Vierkant::Vierkant(int l) : Rechthoek(l, l){};

void Vierkant::print(std::ostream &out) const {
  out << "Vierkant: zijde " << hoogte << std::endl;
}
