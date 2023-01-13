#include <iostream>
#ifndef RECHTHOEK_H
#define RECHTHOEK_H

class Rechthoek {
public:
  Rechthoek();
  Rechthoek(int, int);
  int omtrek() const;
  int oppervlakte() const;

  virtual void print(std::ostream &out) const;

protected:
  int hoogte;
private:
  int breedte;
};

#endif
