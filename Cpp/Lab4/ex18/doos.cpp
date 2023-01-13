#include "doos.h"

template <typename T> Doos<T>::Doos() : n(0), c(nullptr), d(nullptr) {}

template <typename T> void Doos<T>::copy(const Doos<T> &doos) {
  b = doos.b;
  if (doos.c) {
    c = new Doos<T>(*doos.c);
  } else {
    c = nullptr;
  }
  n = doos.n;
  if (n > 0) {
    d = new std::unique_ptr<std::string>[n];
    for (int i = 0; i < n; i++) {
      if (doos.d[i]) {
        d[i] = std::make_unique<std::string>(*doos.d[i]);
      } else
        d[i] = nullptr;
    }
  } else {
    d = nullptr;
  }
}

template <typename T> Doos<T>::Doos(const Doos<T> &doos) { copy(doos); }

template <typename T> Doos<T> &Doos<T>::operator=(const Doos<T> &doos) {
  if (this != &doos) {
    delete c;
    delete[] d;
    copy(doos);
  }
  return *this;
}

template <typename T> Doos<T>::~Doos() {
  delete c;
  delete[] d;
}
