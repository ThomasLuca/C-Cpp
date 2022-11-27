#include <iostream>
#include <strings.h>
#include <vector>
using namespace std;

typedef struct persoon persoon;
struct persoon {
  string naam;
  int leeftijd;
  int lengte;
};

template <typename T> ostream &operator<<(ostream &out, const vector<T> &v) {
  for (auto &e : v) {
    out << e << " ";
  }
  return out;
}

ostream &operator<<(ostream &out, const persoon &p) {
  out << p.naam << " (" << p.leeftijd << " jaar, " << p.lengte << "cm)";
  return out;
}

int main() {
  vector<int> vint = {5, 1, 5, 9, 7, 6};
  vector<double> vdoub = {0.0, 5.3, 9.1, 151.87};
  vector<string> vstr = {"Billy", "Bob", "Marley"};

  cout << vint << endl;
  cout << vdoub << endl;
  cout << vstr << endl;

  persoon p1 = {"Thomas", 21, 170};
  persoon p2 = {"Marley", 3, 40};
  vector<persoon> vpers = {p1, p2};
  cout << vpers << endl;

  // Maak in het hoofdprogramma een vector v van vectoren aan, voeg aan v één
  // vector toe die één geheel getal bevat. Schrijf de vector v uit met de <<
  // -operator.
  vector<vector<int>> vvi = {{55}};
  cout << vvi << endl;

  return 0;
}
