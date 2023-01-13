#include <string>
#ifndef GEKLEURD_H
#define GEKLEURD_H

#include "../ex19/rechthoek.h"

class GekleurdeRechthoek : public Rechthoek {
public:
  GekleurdeRechthoek();
  GekleurdeRechthoek(int, int, const std::string & = "onbekend");
  virtual void print(std::ostream &out) const;

protected:
  std::string kleur;
};

#endif
