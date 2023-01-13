#include "containers.h"
#include <iostream>
#include <vector>

using namespace std;
const int AANTAL = 5;

int main() {
  vector<vector<int>> av(AANTAL);

  for (int i = 0; i < AANTAL; i++) {
    vector<int> v;
    v.reserve(i);
    for (int j = 0; j < i; j++) {
      v.push_back(j * 10);
    }
    av[i] = std::move(v);
  }

  for (auto &v : av) {
    cout << v;
  }

  return 0;
}
