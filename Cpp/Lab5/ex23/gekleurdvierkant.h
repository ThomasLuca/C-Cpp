#ifndef GEKLEURDVIERKANT_H
#define GEKLEURDVIERKANT_H

#include "../ex19/vierkant.h"
#include "gekleurd.h"

class GekleurdVierkant : public Vierkant, public GekleurdeRechthoek {
public:
  GekleurdVierkant(int = 1, const std::string & = "onbekend");
  void print(std::ostream &out) const;
};

#endif
