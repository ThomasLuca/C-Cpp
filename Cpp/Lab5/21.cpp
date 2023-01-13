#include "containers.h" //zodat we vectoren kunnen uitschrijven m.b.v. operator<<
#include <iostream>
#include <vector>

template <typename T> class mijn_vector : public vector<T> {
  using vector<T>::vector;

public:
  void verdubbel(bool = false);
};

template <typename T> void mijn_vector<T>::verdubbel(bool repeat) {
  if (!repeat) {
    for (int i = 0; i < this->size(); i++)
      (*this)[i] = 2 * (*this)[i];
    return;
  }

  int len = this->size();
  this->resize(len * 2);
  for (int i = len - 1; i >= 0; i--) {
    (*this)[2 * i] = (*this)[i];
    (*this)[2 * i + 1] = (*this)[i];
  }
  return;
}

using namespace std;
int main() {
  mijn_vector<int> v{10, 20, 30};
  cout << v;

  v.verdubbel();
  cout << endl << "na verdubbelen zonder parameter: " << v;
  v.verdubbel(true);
  cout << endl << "na verdubbelen met param true:   " << v;

  mijn_vector<int> w(v);
  cout << endl << "een kopie van v: " << w;

  mijn_vector<double> u(7);
  cout << endl << "een vector met 7 default-elt: " << u;
  for (int i = 0; i < u.size(); i++) {
    u[i] = i * 1.1;
  }
  cout << endl << "na opvullen met getallen: " << u;

  u.verdubbel();
  cout << endl << "na verdubbelen zonder parameter: " << u;

  return 0;
}
