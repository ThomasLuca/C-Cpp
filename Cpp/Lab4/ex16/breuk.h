#include <iostream>

class Breuk {
public:
  Breuk(int _a = 0, int _b = 1);

  Breuk operator+(const Breuk &) const;
  Breuk operator-(const Breuk &) const;
  Breuk operator-() const;
  Breuk operator*(const Breuk &) const;
  Breuk &operator+=(const Breuk &);
  Breuk &operator-=(const Breuk &);
  Breuk &operator++();
  Breuk operator++(int);
  Breuk operator+(int) const;
  bool operator<(const Breuk &) const;
  bool operator==(const Breuk &) const;
  bool operator!=(const Breuk &) const;

  friend std::ostream &operator<<(std::ostream &, const Breuk &);
  friend std::istream &operator>>(std::istream &, Breuk &);
  friend bool is_stambreuk(const Breuk &);

private:
  void normaliseer();
  int mijn_ggd(int, int);

private:
  int t;
  int n;
};
