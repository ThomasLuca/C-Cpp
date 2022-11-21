#include <functional>
#include <iostream>
using namespace std;

void schrijf(const string &text, const int t[], int n) {
  cout << text;
  for (int i = 0; i < n; i++) {
    cout << " " << t[i];
  }
  cout << endl;
}

void vul_array(const int a[], const int b[], int c[], int n,
               function<int(int, int)> fn) {
  for (int i = 0; i < n; i++) {
    c[i] = fn(a[i], b[i]);
  }
}

int main() {
  const int GROOTTE = 10;
  int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int b[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
  int c[GROOTTE];

  vul_array(a, b, c, GROOTTE, [](int a, int b) { return a + b; });
  schrijf("SOM:      ", c, GROOTTE);
  /* output bovenstaande opdracht:
     SOM:      0 11 22 33 ...
  */

  vul_array(a, b, c, GROOTTE, [](int a, int b) { return a * b; });
  schrijf("PRODUCT:  ", c, GROOTTE);
  /* output bovenstaande opdracht:
     PRODUCT:  0 10 40 60 ...
  */

  vul_array(a, b, c, GROOTTE, [](int a, int b) { return a - b; });
  schrijf("VERSCHIL: ", c, GROOTTE);
  /* output bovenstaande opdracht:
     VERSCHIL: 0 -9 -18 -27 ...
  */

  return 0;
}
