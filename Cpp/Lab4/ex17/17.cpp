#include "containter.h"
#include <iostream>
#include <set>
using namespace std;

template <typename T> class Container {
private:
  set<T> elementen;
  string naam;

public:
  Container() {};
  Container(const T[], int, const string &);
  Container<T> &operator+=(const T &);
  Container<T> operator*(const Container<T> &) const;
  template <typename U>
  friend ostream &operator<<(ostream &, const Container<U> &);
};

template <typename T>
Container<T>::Container(const T arr[], int n, const string &s) : naam{s} {
  for (int i = 0; i < n; i++) {
    elementen.insert(arr[i]);
  }
}

template <typename T> Container<T> &Container<T>::operator+=(const T &c) {
  elementen.insert(c);
  return *this;
}

template <typename T>
Container<T> Container<T>::operator*(const Container<T> &c) const {
  Container<T> doorsnede;
  doorsnede.naam = naam + " ⋂ " + c.naam;
  for (auto &e : elementen) {
    if (c.elementen.count(e))
      doorsnede.elementen.insert(e);
  }
  return doorsnede;
}

template <typename T> ostream &operator<<(ostream &out, const Container<T> &c) {
  out << "*** set " << c.naam << " ***\n" << c.elementen << endl;
  return out;
}

int main() {
  char v[] = {'a', 'b', 'c', 'd', 'e', 'e'};
  Container<char> verz1(v, 6, "groot"); // voegt de 6 eerste elementen van v toe
                                        // aan het attriuut element
  Container<char> verz2(v, 2, "klein"); // voegt de 2 eerste elementen van v toe
                                        // aan het attriuut element
  (verz2 += 'e') += 'z';
  Container<char> doorsnede = verz1 * verz2; // Maak de doorsnede
  cout << verz1; // print de naam en de elementen (zie hieronder)
  cout << verz2;
  cout << doorsnede;
  return 0;
}
