#include "breuk.h"
#include <math.h>
#include <sstream>

Breuk::Breuk(int _a, int _b) : t(_a), n(_b) { normaliseer(); }

int Breuk::mijn_ggd(int a, int b) {
  if (a < 0 || b < 0) {
    return mijn_ggd(abs(a), abs(b));
  }
  if (b == 0) {
    return a;
  }
  return mijn_ggd(b, a % b);
};

void Breuk::normaliseer() {
  if (n < 0) {
    n *= -1;
    t *= -1;
  }
  int ggd = mijn_ggd(t, n);
  t /= ggd;
  n /= ggd;
}

Breuk Breuk::operator+(const Breuk &b) const {
  return Breuk((t * b.n) + (b.t * n), n * b.n);
}

Breuk Breuk::operator-(const Breuk &b) const {
  return Breuk((t * b.n) - (b.t * n), n * b.n);
}

Breuk Breuk::operator-() const { return Breuk(-t, n); }

Breuk Breuk::operator*(const Breuk &b) const { return Breuk(t * b.t, n * b.n); }

Breuk &Breuk::operator+=(const Breuk &b) {
  t = (t * b.n) + (b.t * n);
  n = n * b.n;
  normaliseer();
  return *this;
}

Breuk &Breuk::operator-=(const Breuk &b) {
  t = (t * b.n) - (b.t * n);
  n = n * b.n;
  normaliseer();
  return *this;
}

Breuk &Breuk::operator++() {
  t += n;
  normaliseer();
  return *this;
}

Breuk Breuk::operator++(int _) {
  Breuk temp(*this);
  t += n;
  normaliseer();
  return temp;
}

bool Breuk::operator<(const Breuk &b) const { return (t * b.n) < (b.t * n); }

Breuk Breuk::operator+(int i) const {
  Breuk b(i);
  return b + *this;
}

bool Breuk::operator==(const Breuk &b) const {
  return (t == b.t) && (n == b.n);
}

bool Breuk::operator!=(const Breuk &b) const { return !(*this == b); }

std::ostream &operator<<(std::ostream &out, const Breuk &b) {
  out << b.t << "/" << b.n;
  return out;
}

std::istream &operator>>(std::istream &in, Breuk &b) {
  std::string getalbeeld;
  in >> getalbeeld;
  std::stringstream ss;
  ss << getalbeeld;
  int positie = getalbeeld.find("/");
  if (positie != std::string::npos) {
    int t;
    char c;
    int n;
    ss >> t;
    ss >> c;
    ss >> n;
    b = Breuk(t, n);
  } else {
    int t;
    ss >> t;
    b = Breuk(t);
  }
  return in;
}
