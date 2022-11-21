#include <iostream>
using namespace std;

void schrijf(const int *array, int aantal, bool achterstevoren = false,
             char tussenteken = ' ') {
  if (!achterstevoren) {
    cout << array[0];
    for (int i = 1; i < aantal; i++) {
      cout << tussenteken << array[i];
    }
  } else {
    cout << array[aantal - 1];
    for (int i = aantal-2; i >= 0; i--) {
      cout << tussenteken << array[i];
    }
  }
  cout << endl;
};

int main() {
  int t[] = {1, 3, 5, 7, 9, 11, 13};
  schrijf(t, 7);
  schrijf(t, 7, true);
  schrijf(t, 7, false, '-');
  schrijf(t, 7, true, '-');
  return 0;
}