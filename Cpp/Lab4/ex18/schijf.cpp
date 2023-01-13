#include "schijf.h"

template <typename T> Schijf<T>::Schijf() : a(nullptr) {}

template <typename T> Schijf<T>::Schijf(const Schijf<T> &schijf) {
  if (schijf.a) { // geen nullptr
    a = new Doos<T>(*schijf.a);
  } else
    a = nullptr;
}

template <typename T> Schijf<T>::~Schijf() { delete a; }

template <typename T> Schijf<T> &Schijf<T>::operator=(const Schijf<T> &schijf) {
  if (this != &schijf) {
    delete a;
    a = nullptr;
    if (schijf.a) {
      a = new Doos<T>(*schijf.a);
    }
  }
  return *this;
}
