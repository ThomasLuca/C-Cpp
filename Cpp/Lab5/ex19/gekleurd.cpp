#include "gekleurd.h"

GekleurdeRechthoek::GekleurdeRechthoek(int h, int b, const std::string &s)
    : Rechthoek(h, b), kleur{s} {};

GekleurdeRechthoek::GekleurdeRechthoek() : Rechthoek(), kleur{"onbekend"} {};


void GekleurdeRechthoek::print(std::ostream &out) const {
  Rechthoek::print(out);
  out << "  kleur: " << kleur << std::endl;
}
