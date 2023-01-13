#ifndef VIERKANT_H
#define VIERKANT_H
#include "rechthoek.h"

class Vierkant : public Rechthoek {
public:
  Vierkant(int = 1);
  virtual void print(std::ostream &out) const;
};

#endif
