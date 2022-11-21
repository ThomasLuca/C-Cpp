#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int N = 10;

string genereer_string(int len) {
  string s;
  for (int i = 0; i < len; i++) {
    char l = (random() % 26) + 'a';
    s += l;
  }
  return s;
}

void vul_array_met_strings(string *const tab, int n, int len) {
  for (int i = 0; i < n; i++) {
    tab[i] = genereer_string(len);
  }
}

void schrijf(const string *const tab, int n) {
  for (int i = 0; i < n; i++) {
    cout << tab[i] << endl;
  }
}

void bepaal_min_en_max(const string *const tab, int n, string &min,
                       string &max) {
  min = tab[0];
  max = tab[0];

  for (int i = 1; i < n; i++) {
    if (tab[i] > max)
      max = tab[i];
    else if (tab[i] < min)
      min = tab[i];
  }
}

int main() {
  srand(time(NULL));
  const int n = 5;
  string sarr[N];

  int minl = 5;
  int maxl = 15;
  int len = 0;

  do {
    cin.sync();
    cout << "Len [5, 15]: ";
    cin >> len;
  } while (len < minl || len > maxl);

  vul_array_met_strings(sarr, n, len);
  schrijf(sarr, n);

  string min, max;
  bepaal_min_en_max(sarr, n, min, max);
  cout << "Min: " << min << endl;
  cout << "Max: " << max << endl;
  return 0;
}