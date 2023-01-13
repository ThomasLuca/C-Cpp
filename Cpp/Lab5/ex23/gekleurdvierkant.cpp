#include "gekleurdvierkant.h"

GekleurdVierkant::GekleurdVierkant(int l, const std::string &s)
    : GekleurdeRechthoek(l, l, s), Vierkant(l) {}

void GekleurdVierkant::print(std::ostream &out) const {
  Vierkant::print(out);
  std::cout << "  kleur: " << GekleurdeRechthoek::kleur << std::endl;
}
