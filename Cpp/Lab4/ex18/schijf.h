#include "doos.h"

template <typename T> class Schijf {
public:
  Schijf();
  Schijf(const Schijf<T> &);
  Schijf<T> &operator=(const Schijf<T> &);
  ~Schijf();

private:
  Doos<T> *a;
};
