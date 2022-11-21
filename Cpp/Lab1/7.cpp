#include <fstream>
#include <iostream>
using namespace std;

int main() {
  ifstream inv1, inv2;
  inv1.open("./7.txt/stationnetje.txt", ios::in);
  inv2.open("./7.txt/paddestoel.txt", ios::in);
  if (!(inv1.is_open() && inv2.is_open())) {
    cout << "Failed to open files" << endl;
    return -1;
  }

  ofstream uit("./7.txt/mix.txt", ios::app);
  if (!uit.is_open()) {
    cout << "Failed to open files" << endl;
    return -1;
  }
  string s;
  int c = 0;

  while (true) {
    if (c % 2 == 0) {
      if (!(inv2 >> s))
        break;
      uit << s << ' ';
    } else {
      if (!(inv1 >> s))
        break;
      uit << s << ' ';
    }
  }

  uit << endl;
  inv1.close();
  inv2.close();
  uit.close();

  return 0;
}
