#include <iostream>
using namespace std;

int main() {
  // ****WRONG****
  // Can't use '+' to concat with ""
  // char c = 'x';
  // string s = "" + c;
  // cout << "karakter " << c << " omgezet: " << s << "." << endl;

  char k = 'y';
  string w = "";
  w += k;
  cout << "karakter " << k << " omgezet: " << w << "." << endl;
  return 0;
}