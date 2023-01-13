#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Langeslang : public vector<unique_ptr<int>> {
private:
  void schrijf(ostream &) const;

public:
  void vul(const vector<int> &);
  Langeslang &concatenate(Langeslang &);

  friend ostream &operator<<(ostream &out, const Langeslang &l) {
    l.schrijf(out);
    return out;
  }
};

void Langeslang::vul(const vector<int> &v) {
  this->resize(v.size());
  for (int i = 0; i < v.size(); i++) {
    (*this)[i] = make_unique<int>(v[i]);
  }
}

void Langeslang::schrijf(ostream &out) const {
  for (auto &e : *this) {
    out << *e << ", ";
  }
}

Langeslang &Langeslang::concatenate(Langeslang &ls) {
  int size_a = this->size();
  int size_b = ls.size();
  this->resize(size_a + size_b);

  if (this == &ls) {
    for (int i = size_a; i < size_a * 2; i++) {
      (*this)[i] = make_unique<int>(*ls[i - size_a]);
    }
    return *this;
  }

  for (int i = size_a; i < size_a + size_b; i++) {
    (*this)[i] = std::move(ls[i - size_a]);
  }
  ls.resize(0);

  return *this;
}

int main() {
  Langeslang a, b, c;
  a.vul({1, 2});    // via a vind je de getallen 1 en 2
  b.vul({3, 4, 5}); // via b vind je de getallen 3, 4 en 5
  c.vul({6, 7});    // via c vind je de getallen 6 en 7
  cout << "a: " << a << endl
       << "b: " << b << endl
       << "c: " << c << endl
       << endl;

  a.concatenate(a);
  // via a vind je nu de 4 getallen 1, 2, 1 en 2

  cout << "na a.concatenate(a)" << endl;
  cout << "a: " << a << endl;

  a.concatenate(b).concatenate(c);
  // via a vind je nu de 9 getallen 1, 2, 1, 2, 3, 4, 5, 6 en 7
  // b is leeg
  // c is leeg

  cout << "na a.concatenate(b).concatenate(c)" << endl;
  cout << "a: " << a << endl
       << "b: " << b << endl
       << "c: " << c << endl
       << endl;
  return 0;
}
